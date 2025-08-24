#include "mainpage.h"
#include "floating.h"
#include "flying.h"
#include "grounded.h"
#include "ui_mainpage.h"
#include <QApplication>
#include <QLabel>
#include <QObject>
#include <QWidget>
#include <QEvent>
#include <vector>
#include <QPushButton>
#include <QMessageBox>
#include "tile.h"
#include "agent.h"
#include "player.h"
#include "waterwalking.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QPainter>
tile *cell[5][9] = {};
bool canGo[5][9] = {};
bool canAttack[5][9] = {};
QList<QLabel*> previousHighlights;
QVector<QPushButton*> vec, v1, v2;
std::vector<int> hexa;
QVector<tile*> MainPage:: getNeighbors(int row, int col) {
    QVector<tile*> neighbors;
    // جهت‌ها برای ستون زوج
    static const int even_directions[6][2] = {
        {-1, 0}, {-1, 1}, {0, 1},
        {1, 0}, {0, -1}, {-1, -1}
    };

    // جهت‌ها برای ستون فرد
    static const int odd_directions[6][2] = {
        {-1, 0}, {0, 1}, {1, 1},
        {1, 0}, {1, -1}, {0, -1}
    };

    const int (*directions)[2] = (col % 2 == 0) ? even_directions : odd_directions;

    for (int i = 0; i < 6; ++i) {
        int nr = row + directions[i][0];
        int nc = col + directions[i][1];

        if (nr >= 0 && nr < 5 && nc >= 0 && nc < 9 ) {
            if(cell[nr][nc] != nullptr) {
                neighbors.push_back(cell[nr][nc]);
                qDebug()<<"cell null in neighbor";

            }
        }
    }

    return neighbors;
}

void MainPage::hid1(){
    ui->scrollArea_2->hide();
}
void MainPage::hid2(){
    ui->scrollArea_4->hide();
}
void MainPage::switchTurn() {
    if (currentPlayer == &player1) {
        currentPlayer = &player2;
        qDebug() << "Turn: Player 2";
    } else {
        currentPlayer = &player1;
        qDebug() << "Turn: Player 1";
    }
}
void MainPage::highlightingMove(QPushButton *p) {
    int size = 50;
    int width = 2 * size;
    int height = static_cast<int>(round(size * sqrt(3)));

    QLabel* overlay = new QLabel(p->parentWidget());
    overlay->setAttribute(Qt::WA_TransparentForMouseEvents);

    // موقعیت دقیق دکمه روی فرم اصلی
    QPoint pos = p->mapTo(this, QPoint(0, 0));
    int x = pos.x() + (p->width() - width) / 2;
    int y = pos.y() + (p->height() - height) / 2;
    overlay->setGeometry(x, y, width, height);

    QPixmap pixmap(width, height);
    pixmap.fill(Qt::transparent);

    QPainter painter(&pixmap);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setBrush(QColor(255, 0, 0, 70));
    painter.setPen(Qt::NoPen);

    QPolygon hexagon;
    for (int i = 0; i < 6; ++i) {
        double angle_deg = 60 * i - 60;
        double angle_rad = M_PI / 180 * angle_deg;
        int px = width / 2 + static_cast<int>(round(size * cos(angle_rad)));
        int py = height / 2 + static_cast<int>(round(size * sin(angle_rad)));
        hexagon << QPoint(px, py);
    }

    painter.drawPolygon(hexagon);
    painter.end();

    overlay->setPixmap(pixmap);
    overlay->show();
    overlay->raise();
}
void MainPage::highlightingAttack(QWidget *p) {
    int size = 50;
    int width = 2 * size;
    int height = static_cast<int>(round(size * sqrt(3)));

    QLabel* overlay = new QLabel(p->parentWidget());
    overlay->setAttribute(Qt::WA_TransparentForMouseEvents);

    QPoint pos = p->mapTo(this, QPoint(0, 0));
    int x = pos.x() + (p->width() - width) / 2;
    int y = pos.y() + (p->height() - height) / 2;
    overlay->setGeometry(x, y, width, height);

    QPixmap pixmap(width, height);
    pixmap.fill(Qt::transparent);

    QPainter painter(&pixmap);
    painter.setRenderHint(QPainter::Antialiasing);

    painter.setBrush(Qt::NoBrush);
    painter.setPen(QPen(QColor(0, 255, 0), 3));  // رنگ خط قرمز با ضخامت ۳

    QPolygon hexagon;
    for (int i = 0; i < 6; ++i) {
        double angle_deg = 60 * i - 60;
        double angle_rad = M_PI / 180 * angle_deg;
        int px = width / 2 + static_cast<int>(round(size * cos(angle_rad)));
        int py = height / 2 + static_cast<int>(round(size * sin(angle_rad)));
        hexagon << QPoint(px, py);
    }

    painter.drawPolygon(hexagon);  // فقط خط دور شش‌ضلعی کشیده میشه
    painter.end();

    overlay->setPixmap(pixmap);
    overlay->show();
    overlay->raise();

}
void MainPage::highlightAtacking(QWidget *m) {
    qDebug() << "[highlight] started";

    // پاک کردن هایلایت‌های قبلی
    for (QLabel* label : previousHighlights) {
        if (label) {
            label->hide();
            label->deleteLater();
        }
    }
    previousHighlights.clear();

    const int overlayWidth = 100;
    const int overlayHeight = 100;
    const int size = 20;
    const float height = sqrt(3) * size;

    for (int row = 0; row < 5; ++row) {
        for (int col = 0; col < 9; ++col) {
            qDebug() << "[highlight] checking cell[" << row << "][" << col << "]";

            if (!cell[row][col]) {
                qDebug() << "[highlight] cell is null";
                continue;
            }

            if (!canAttack[row][col]) {
                continue;
            }

            tile *p = cell[row][col];
            if (!p) {
                qDebug() << "[highlight] tile pointer is null after cell check!";
                continue;
            }

            int pw = p->width();
            int ph = p->height();

            if (pw <= 0 || ph <= 0 || pw > 1000 || ph > 1000) {
                qDebug() << "[highlight] invalid tile size: width=" << pw << ", height=" << ph;
                continue;
            }

            double x = (size * 3.0 / 2 + 55.0) * col;
            double y = (height + 55.0) * (row + 0.5 * (col % 2));

            QLabel* overlay = new QLabel(m);
            overlay->setGeometry(x + 280, y + 146, overlayWidth, overlayHeight);

            QPixmap pixmap(overlayWidth, overlayHeight);
            pixmap.fill(Qt::transparent);

            QPainter painter(&pixmap);
            painter.setRenderHint(QPainter::Antialiasing);
            painter.setBrush(Qt::NoBrush);
            painter.setPen(QPen(QColor(0, 255, 0), 3));

            QPolygon hexagon;
            for (int i = 0; i < 6; ++i) {
                double angle_deg = 60 * i - 60;
                double angle_rad = M_PI / 180 * angle_deg;
                int px = overlayWidth / 2 + (overlayWidth / 2) * cos(angle_rad);
                int py = overlayHeight / 2 + (overlayHeight / 2) * sin(angle_rad);
                hexagon << QPoint(px, py);
            }

            painter.drawPolygon(hexagon);
            painter.end();

            overlay->setPixmap(pixmap);
            overlay->setAttribute(Qt::WA_TransparentForMouseEvents);
            overlay->show();
            //overlay->raise();

            previousHighlights.append(overlay);

            qDebug() << "[highlight] overlay added at" << row << col;
        }
    }

    qDebug() << "[highlight] finished";
}
void MainPage::highlight(QWidget *m) {

    for(int row = 0; row < 5; row++){
        for(int col = 0; col < 9; col++){
            if(!cell[row][col]) continue;
            if(!canGo[row][col] && !canAttack[row][col]) continue;
            QPushButton *p = cell[row][col]->w;
            int c = cell[row][col]->type;
            if(canAttack[row][col]){
                if(c == 0 || c == 1 || c == 2)
                    p->setStyleSheet("image: url(:/new/prefix17/redd.png); "
                                     "background-color: transparent");
                if(c == 3)
                    p->setStyleSheet("image: url(:/new/prefix17/redw.png); "
                                     "background-color: transparent");
                if(c == 4)
                    p->setStyleSheet("image: url(:/new/prefix17/reds.png); "
                                     "background-color: transparent");
            }
            else if(canGo[row][col]){
                if(c == 0 || c == 1 || c == 2)
                    p->setStyleSheet("image: url(:/new/prefix18/Greend.png); "
                                     "background-color: transparent");
                if(c == 3)
                    p->setStyleSheet("image: url(:/new/prefix18/Greenw.png); "
                                     "background-color: transparent");
                if(c == 4)
                    p->setStyleSheet("image: url(:/new/prefix18/Greenr.png); "
                                     "background-color: transparent");
            }
        }
    }


}
/*
void MainPage::highlight(QWidget *m) {
    qDebug() << "[highlight] started";

    // پاک کردن هایلایت‌های قبلی
    for (QLabel* label : previousHighlights) {
        if (label) {
            label->hide();
            label->deleteLater();
        }
    }
    previousHighlights.clear();

    const int overlayWidth = 100;
    const int overlayHeight = 100;
    const int size = 20;
    const float height = sqrt(3) * size;

    for (int row = 0; row < 5; ++row) {
        for (int col = 0; col < 9; ++col) {
            qDebug() << "[highlight] checking cell[" << row << "][" << col << "]";

            if (!cell[row][col]) {
                qDebug() << "[highlight] cell is null";
                continue;
            }
            QColor color;
            if (canGo[row][col] && canAttack[row][col]) {
                color = QColor(255, 165, 0, 128); // نارنجی = هم حمله هم حرکت
            } else if (canGo[row][col]) {
                color = QColor(255, 0, 0, 128); // قرمز = فقط حرکت
            } else if (canAttack[row][col]) {
                color = QColor(0, 255, 0, 128); // سبز = فقط حمله
            } else {
                continue;
            }

            tile *p = cell[row][col];
            if (!p) {
                qDebug() << "[highlight] tile pointer is null after cell check!";
                continue;
            }

            int pw = p->width();
            int ph = p->height();

            if (pw <= 0 || ph <= 0 || pw > 1000 || ph > 1000) {
                qDebug() << "[highlight] invalid tile size: width=" << pw << ", height=" << ph;
                continue;
            }

            double x = (size * 3.0 / 2 + 55.0) * col;
            double y = (height + 55.0) * (row + 0.5 * (col % 2));

            // قبلی: QLabel روی m ساخته شده
            QLabel* overlay = new QLabel(p->parentWidget());
            overlay->setAttribute(Qt::WA_TransparentForMouseEvents);

            // موقعیت دقیق دکمه روی فرم اصلی
            QPoint pos = p->mapTo(this, QPoint(0, 0));
            QPixmap pixmap(overlayWidth, overlayHeight);
            pixmap.fill(Qt::transparent);

            QPainter painter(&pixmap);
            painter.setRenderHint(QPainter::Antialiasing);
            painter.setBrush(color);
            painter.setPen(Qt::NoPen);

            QPolygon hexagon;
            for (int i = 0; i < 6; ++i) {
                double angle_deg = 60 * i - 60;
                double angle_rad = M_PI / 180 * angle_deg;
                int px = overlayWidth / 2 + (overlayWidth / 2) * cos(angle_rad);
                int py = overlayHeight / 2 + (overlayHeight / 2) * sin(angle_rad);
                hexagon << QPoint(px, py);
            }

            painter.drawPolygon(hexagon);
            painter.end();

            overlay->setPixmap(pixmap);
            overlay->setAttribute(Qt::WA_TransparentForMouseEvents);
            overlay->show();
            overlay->raise();

            previousHighlights.append(overlay);

            qDebug() << "[highlight] overlay added at" << row << col;
        }
    }

    qDebug() << "[highlight] finished";
}
*/
void MainPage::loop(QWidget *m) {
    qDebug() << "[loop] Running loop for" << (currentPlayer == &player1 ? "Player 1" : "Player 2");

    for (int i = 0; i < currentPlayer->playerAgents.size(); ++i) {
        Agent* a = currentPlayer->playerAgents[i];
        if (!a) {
            qDebug() << "[loop] agent[" << i << "] is nullptr!";
            continue;
        }

        if (a->parent() == nullptr) {
            qDebug() << "[loop] agent[" << i << "] has no parent!";
            continue;
        }

        tile* ti = a->getCell();
        if (!ti) {
            qDebug() << "[loop] agent[" << i << "] has no tile!";
            continue;
        }

        //disconnect(a, &QPushButton::clicked, nullptr, nullptr);

    }
}



//tile *cell[8][8] = {};
void changeStyle(QPushButton *p, int c){

    if(c == 0 || c == 1 || c == 2)
        p->setStyleSheet("image: url(:/new/prefix9/dgray.png); "
                         "background-color: transparent");
    if(c == 3)
        p->setStyleSheet("image: url(:/new/prefix10/watergray.png); "
                         "background-color: transparent");
    if(c == 4)
        p->setStyleSheet("image: url(:/new/prefix11/rockgray.png); "
                         "background-color: transparent");
}


void MainPage::changeBack(){

    for(int i = 0; i < vec.size(); i++){
        QPushButton *p = vec[i];
        int c = hexa[i];
        if(c == 0 || c == 1 || c == 2)
            p->setStyleSheet("image: url(:/new/prefix3/d.png); "
                             "background-color: transparent");
        if(c == 3)
            p->setStyleSheet("image: url(:/new/prefix4/water.png); "
                             "background-color: transparent");
        if(c == 4)
            p->setStyleSheet("image: url(:/new/prefix5/rock.png); "
                             "background-color: transparent");
    }

}


class SelectButton : public QPushButton {

public:
    SelectButton(int h, int m, int d, int a, QLabel *linkedCharacter,QVector<QPushButton*>& buttons,
                 QVector<QPushButton*>& valid, int type,
                 QPushButton *s, QString style, QWidget *parent1 = nullptr,
                 MainPage *parent2 = nullptr)
        : QPushButton(parent1),
        characterLabel(linkedCharacter),
        allButtons(buttons),
        validButtons(valid),
        hasCharachter(false),           // مقداردهی اولیه اضافه شد
        waitingForTarget(false)         // مقداردهی اولیه اضافه شد
    {
        qDebug()<<":"<<characterLabel->styleSheet();

        this->setText(s->text());
        this->setIcon(s->icon());
        this->setStyleSheet(s->styleSheet());
        this->setFont(s->font());
        s->lower();
        s->hide();
        this->show();
        this->setGeometry(s->geometry());

        connect(this, &QPushButton::clicked, this, [this,parent2]() {
            if(hasCharachter){
                QMessageBox msgBox(QMessageBox::Warning,
                                   "Warning",
                                   "This character has already been chosen",
                                   QMessageBox::Ok,
                                   parent2);
                msgBox.setStyleSheet(
                    "QMessageBox {"
                    "background-color: #FFC07C;"
                    "color: #000000;"
                    "font-size: 12px;"
                    "padding: 10px;"
                    "}"
                    "QLabel {"
                    "color: #000000;"
                    "font-size: 12px;"
                    "}"
                    "QPushButton {"
                    "background-color: #FFF;"
                    "color: #000000;"
                    "border: 1px solid #FFC07C;"
                    "border-radius: 5px;"
                    "padding: 5px;"
                    "}"
                    );
                msgBox.exec();

            }
            else{
                this->waitingForTarget = true;
                qDebug() <<waitingForTarget;
                int cnt = 0;
                for(QPushButton *p : allButtons){
                    p->raise();
                    if(!validButtons.contains(p))
                        changeStyle(p, hexa[cnt]);
                    cnt++;
                }
            }
        });

        int cnt = 0;


        for (int row = 0; row < 5; ++row) {
            for (int col = 0; col < 9; col += 2) {
                if (col % 2 == 1 && row == 4) continue;

                QPushButton* p = allButtons[cnt];

                // اتصال کلیک برای قرار دادن ایجنت
                connect(p, &QPushButton::clicked, p, [=, this, &linkedCharacter]() {
                    if (!waitingForTarget) {
                        return; // اگر در حالت انتخاب نیستیم، هیچ کاری نکن
                    }

                    if (hasCharachter) {
                        return; // اگر کاراکتر قبلاً انتخاب شده، کاری نکن
                    }

                    if(validButtons.contains (p)){
                        // اگر تا اینجا رسید، یعنی همه شرایط OK است
                        double x = p->x() - 10;
                        double y = p->y();
                        Agent *character = nullptr;

                        // ساخت ایجنت بر اساس نوع انتخابی
                        if (type == 0)
                            character = new Grounded(parent2, h, m, d, a);
                        else if (type == 1)
                            character = new flying(parent2, h, m, d, a);
                        else if (type == 2)
                            character = new floating(parent2, h, m, d, a);
                        else
                            character = new waterWalking(parent2, h, m, d, a);

                        currentPlayer->addAgent(character);
                        character->setOwner(currentPlayer);

                        // ست کردن مکان و tile مربوط
                        tile* targetTile = cell[row][col];
                        character->setCell(targetTile);
                        //targetTile->agent = character;

                        QString updatedStyle = "QPushButton {border: none; background-color: transparent; " + style + "}";
                        character->setStyleSheet(updatedStyle);
                        character->setAttribute(Qt::WA_TranslucentBackground);
                        character->setGeometry(x, y, 140, 90);
                        character->show();
                    }else if (!validButtons.contains (p)){
                        QMessageBox msgBox(QMessageBox::Warning,
                                           "Warning",
                                           "choos a valid tile!",
                                           QMessageBox::Ok,
                                           parent2);
                        msgBox.setStyleSheet(
                            "QMessageBox {"
                            "background-color: #FFC07C;"
                            "color: #000000;"
                            "font-size: 12px;"
                            "padding: 10px;"
                            "}"
                            "QLabel {"
                            "color: #000000;"
                            "font-size: 12px;"
                            "}"
                            "QPushButton {"
                            "background-color: #FFF;"
                            "color: #000000;"
                            "border: 1px solid #FFC07C;"
                            "border-radius: 5px;"
                            "padding: 5px;"
                            "}"
                            );
                        msgBox.exec();

                    }

                    if (player1.countAgent == 5) {
                        parent2->hid1();
                        currentPlayer = &player2;
                    }
                    if (player2.countAgent == 5) {
                       // parent2->ui->lineEdit->show();
                        parent2->hid2();
                        currentPlayer = &player1;
                        parent2->loop(parent2);
                        for(Agent * A : player1.playerAgents){
                            A->setConnection(parent2);
                        }
                        for(Agent * A : player2.playerAgents){
                            A->setConnection(parent2);
                        }



                    }

                    validButtons.removeAll(p);
                    hasCharachter=true;
                    parent2->changeBack();

                    for (Agent* a : player1.playerAgents) a->raise();
                    for (Agent* a : player2.playerAgents) a->raise();
                });

                cnt++;

                // جابه‌جا شدن از ستون زوج به فرد
                if (col == 8) col = -1;
            }
        }
    }


    void addvec(MainPage *parent, QVector<SelectButton*>sb){
        MainPage *m = parent;
        qDebug() << waitingForTarget << "<<<";

    }


private:
    QLabel *characterLabel;
    QVector<QPushButton*> allButtons;
    QVector<QPushButton*> &validButtons;
    bool waitingForTarget = false;
    bool hasCharachter = false;
};

QVector <QLabel*> chars;
QVector <SelectButton*> charbuttons;



//extern????


void highlightTiles(tile* grid[9][9]) {


    int size = 20;  // شعاع
    float height = sqrt(3) * size;

    for (int row = 0; row < 5; ++row) {
        for (int col = 0; col < 9; col+=2) {
            double x1 = (size * 3.0/2 + 55.0) * col;
            double y1 = (height + 55.0) * (row + 0.5 * (col % 2));
            if(col % 2 && row == 4) continue;
            QPolygonF polygon;
            const double PI = 3.14159265358979323846;

            for (int i = 0; i < 6; ++i) {
                double angle_deg = 60 * i - 30; // برای قرارگیری صحیح شش ضلعی
                double angle_rad = PI / 180 * angle_deg;
                double x = (grid[row][col]->x()) + size * cos(angle_rad);
                double y = (grid[row][col]->y()) + size * sin(angle_rad);
                polygon << QPointF(x, y);
            }
            QPolygon hexPolygon = polygon.toPolygon();
            tile *button = grid[row][col];
            button->setMask(QRegion(hexPolygon));
            if(col == 8) col = -1;

        }
    }


}


MainPage::MainPage(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainPage)
{
    ui->setupUi(this);
    ui->lineEdit->setDisabled(1);;
    //QString fileName = ":/new/prefix1/board/grid1.txt";
    QString fileName;
    int r=rand()%8;
    switch (r) {
    case 0:
        fileName = ":/new/prefix1/board/grid1.txt";

        break;
    case 1:
        fileName = ":/new/prefix2/board/grid2.txt";
        break;
    case 2:
        fileName = ":/new/prefix3/board/grid3.txt";
        break;
    case 3:
        fileName = ":/new/prefix4/board/grid4.txt";

        break;
    case 4:
        fileName = ":/new/prefix5/board/grid5.txt";
        break;
    case 5:
        fileName = ":/new/prefix6/board/grid6.txt";
        break;
    case 6:
        fileName = ":/new/prefix7/board/grid7.txt";

        break;
    case 7:
        fileName = ":/new/prefix8/board/grid8.txt";
        break;

    }

    QFile file(fileName);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Cannot open file for reading:" << file.errorString();
        exit(0);
    }

    QTextStream in(&file);


    while (!in.atEnd()) {
        QString line = in.readLine();
        int startIndex = 0;

        while (true) {
            startIndex = line.indexOf('/', startIndex);
            if (startIndex == -1) break;

            int endIndex = line.indexOf('\\', startIndex);
            if (endIndex == -1) break;
            QString content = line.mid(startIndex + 1, endIndex - startIndex - 1);
            if (content[0] == " ")
                hexa.push_back(0);
            if(content[0]=='~')
                hexa.push_back(3);
            if(content[0]=='#')
                hexa.push_back(4);
            if(content[0]=='1')
                hexa.push_back(1);
            if(content[0]=='2')
                hexa.push_back(2);
            startIndex = endIndex + 1;
        }
    }
    file.close();

    for(int i : hexa)
        qDebug() << i;

    float size = 20; // اندازه هر شش‌ضلعی

    int cnt = 0;

    float height = sqrt(3) * size;

    for (int row = 0; row < 5; ++row) {
        // اول ستون‌های زوج
        for (int col = 0; col < 9; col += 2) {
            if (col % 2 == 1 && row == 4) continue; // همچنان این شرط رو نگه می‌داریم اگر برای ردیف آخر بخوای ستون فرد حذف بشه

            double x = (size * 3.0/2 + 55.0) * col;
            double y = (height + 55.0) * (row + 0.5 * (col % 2));

            cell[row][col] = new tile(this, x + 280, y + 150, this, hexa[cnt], row, col);

            if (hexa[cnt] == 1) v1.push_back(vec[cnt]);
            else if (hexa[cnt] == 2) v2.push_back(vec[cnt]);
            cell[row][col]->pic(hexa[cnt++]);
        }

        // بعد ستون‌های فرد
        for (int col = 1; col < 9; col += 2) {
            if (col % 2 == 1 && row == 4) continue;

            double x = (size * 3.0/2 + 55.0) * col;
            double y = (height + 55.0) * (row + 0.5 * (col % 2));

            cell[row][col] = new tile(this, x + 280, y + 150, this, hexa[cnt], row, col);

            if (hexa[cnt] == 1) v1.push_back(vec[cnt]);
            else if (hexa[cnt] == 2) v2.push_back(vec[cnt]);
            cell[row][col]->pic(hexa[cnt++]);
        }
    }
    for (int row = 0; row < 5; ++row) {
        for (int col = 0; col < 9; ++col) {
            if (cell[row][col]) {
                cell[row][col]->neighbors = getNeighbors(row, col);
            }
        }
    }


    qDebug() << vec.size() << "******************\n";
    ui->centralwidget->raise();
    ui->centralwidget->setStyleSheet("background-color: transparent");
    for(QPushButton *p : vec){
        p->raise();
    }



    chars.push_back(ui->label_1); chars.push_back(ui->label_2);
    chars.push_back(ui->label_8); chars.push_back(ui->label_9);
    chars.push_back(ui->label_10); chars.push_back(ui->label_11); chars.push_back(ui->label_12);
    chars.push_back(ui->label_13); chars.push_back(ui->label_14); chars.push_back(ui->label_15);
    chars.push_back(ui->label_16); chars.push_back(ui->label_17); chars.push_back(ui->label_18);
    chars.push_back(ui->label_19); chars.push_back(ui->label_20); chars.push_back(ui->label_21);
    chars.push_back(ui->label_22); chars.push_back(ui->label_23); chars.push_back(ui->label_24);
    chars.push_back(ui->label_25); chars.push_back(ui->label_26); chars.push_back(ui->label_27);
    chars.push_back(ui->label_28);


    qDebug()<<ui->label_28->styleSheet();
    currentPlayer = &player1;


    // charbuttons[0]->addvec(this, charbuttons);

    charbuttons.push_back(new SelectButton(320, 2, 90, 1, ui->label_1, vec, v1, 0, ui->pushButton_1, ui->label_1->styleSheet(), ui->scrollArea_2->widget(), this));
    charbuttons.push_back(new SelectButton(240, 3, 120, 2, ui->label_2, vec, v1, 2, ui->pushButton_2, ui->label_2->styleSheet(), ui->scrollArea_2->widget(), this));
    charbuttons.push_back(new SelectButton(260, 2, 80, 2, ui->label_8, vec, v1, 0, ui->pushButton_8, ui->label_8->styleSheet(), ui->scrollArea_2->widget(), this));
    charbuttons.push_back(new SelectButton(400, 2, 100, 1, ui->label_9, vec, v1, 0, ui->pushButton_9, ui->label_9->styleSheet(), ui->scrollArea_2->widget(), this));
    charbuttons.push_back(new SelectButton(400, 2, 120, 1, ui->label_10, vec, v1, 0, ui->pushButton_10, ui->label_10->styleSheet(), ui->scrollArea_2->widget(), this));
    charbuttons.push_back(new SelectButton(320, 3, 100, 1, ui->label_11, vec, v1, 2, ui->pushButton_11, ui->label_11->styleSheet(), ui->scrollArea_2->widget(), this));
    charbuttons.push_back(new SelectButton(320, 3, 120, 1, ui->label_12, vec, v1, 1, ui->pushButton_12, ui->label_12->styleSheet(), ui->scrollArea_2->widget(), this));
    charbuttons.push_back(new SelectButton(280, 2, 140, 2, ui->label_13, vec, v1, 0, ui->pushButton_13, ui->label_13->styleSheet(), ui->scrollArea_2->widget(), this));
    charbuttons.push_back(new SelectButton(400, 2, 100, 1, ui->label_14, vec, v1, 0, ui->pushButton_14, ui->label_14->styleSheet(), ui->scrollArea_2->widget(), this));
    charbuttons.push_back(new SelectButton(320, 2, 100, 2, ui->label_15, vec, v1, 0, ui->pushButton_15, ui->label_15->styleSheet(), ui->scrollArea_2->widget(), this));
    charbuttons.push_back(new SelectButton(160, 2, 100, 2, ui->label_16, vec, v1, 0, ui->pushButton_16, ui->label_16->styleSheet(), ui->scrollArea_2->widget(), this));
    charbuttons.push_back(new SelectButton(400, 2, 100, 1, ui->label_17, vec, v1, 0, ui->pushButton_17, ui->label_17->styleSheet(), ui->scrollArea_2->widget(), this));
    charbuttons.push_back(new SelectButton(320, 3, 110, 1,ui->label_18, vec, v1, 0, ui->pushButton_18, ui->label_18->styleSheet(), ui->scrollArea_2->widget(), this));
    charbuttons.push_back(new SelectButton(400, 2, 80, 1, ui->label_19, vec, v1, 0, ui->pushButton_19, ui->label_19->styleSheet(), ui->scrollArea_2->widget(), this));
    charbuttons.push_back(new SelectButton(240, 2, 100, 2,ui->label_20, vec, v1, 0, ui->pushButton_20, ui->label_20->styleSheet(), ui->scrollArea_2->widget(), this));
    charbuttons.push_back(new SelectButton(320, 2, 80, 2, ui->label_21, vec, v1, 3, ui->pushButton_21, ui->label_21->styleSheet(), ui->scrollArea_2->widget(), this));
    charbuttons.push_back(new SelectButton(400, 2, 100, 1, ui->label_22, vec, v1, 3, ui->pushButton_22, ui->label_22->styleSheet(), ui->scrollArea_2->widget(), this));
    charbuttons.push_back(new SelectButton(320, 2, 90, 2, ui->label_23, vec, v1, 3, ui->pushButton_23, ui->label_23->styleSheet(), ui->scrollArea_2->widget(), this));
    charbuttons.push_back(new SelectButton(320, 3, 100, 1, ui->label_24, vec, v1, 3, ui->pushButton_24, ui->label_24->styleSheet(), ui->scrollArea_2->widget(), this));
    charbuttons.push_back(new SelectButton(320, 3, 90, 1, ui->label_25, vec, v1, 3, ui->pushButton_25, ui->label_25->styleSheet(), ui->scrollArea_2->widget(), this));
    charbuttons.push_back(new SelectButton(400, 2, 100, 1,ui->label_26, vec, v1, 3, ui->pushButton_26, ui->label_26->styleSheet(), ui->scrollArea_2->widget(), this));
    charbuttons.push_back(new SelectButton(320, 2, 100, 2,ui->label_27, vec, v1, 3, ui->pushButton_27, ui->label_27->styleSheet(), ui->scrollArea_2->widget(), this));
    charbuttons.push_back(new SelectButton(320, 3, 100, 1, ui->label_28, vec, v1, 3, ui->pushButton_28, ui->label_28->styleSheet(), ui->scrollArea_2->widget(), this));

    chars.push_back(ui->label2_1); chars.push_back(ui->label2_2); chars.push_back(ui->label2_3);
    chars.push_back(ui->label2_4); chars.push_back(ui->label2_5); chars.push_back(ui->label2_6);
    chars.push_back(ui->label2_7); chars.push_back(ui->label2_8); chars.push_back(ui->label2_9);
    chars.push_back(ui->label2_10); chars.push_back(ui->label2_11); chars.push_back(ui->label2_12);
    chars.push_back(ui->label2_13); chars.push_back(ui->label2_14); chars.push_back(ui->label2_15);
    chars.push_back(ui->label2_16); chars.push_back(ui->label2_17); chars.push_back(ui->label2_18);
    chars.push_back(ui->label2_19); chars.push_back(ui->label2_20); chars.push_back(ui->label2_21);
    chars.push_back(ui->label2_22); chars.push_back(ui->label2_23);

    charbuttons.push_back(new SelectButton(320, 3, 100, 1, ui->label2_1, vec, v2, 3, ui->pushButton2_1, ui->label2_1->styleSheet(), ui->scrollArea_4->widget(), this));
    charbuttons.push_back(new SelectButton(320, 2, 100, 2, ui->label2_2, vec, v2, 3, ui->pushButton2_2, ui->label2_2->styleSheet(), ui->scrollArea_4->widget(), this));
    charbuttons.push_back(new SelectButton(400, 2, 100, 1, ui->label2_3, vec, v2, 3, ui->pushButton2_3, ui->label2_3->styleSheet(), ui->scrollArea_4->widget(), this));
    charbuttons.push_back(new SelectButton(320, 3, 90, 1, ui->label2_4, vec, v2, 3, ui->pushButton2_4, ui->label2_4->styleSheet(), ui->scrollArea_4->widget(), this));
    charbuttons.push_back(new SelectButton(320, 3, 100, 1, ui->label2_5, vec, v2, 3, ui->pushButton2_5, ui->label2_5->styleSheet(), ui->scrollArea_4->widget(), this));
    charbuttons.push_back(new SelectButton(320, 2, 90, 2, ui->label2_6, vec, v2, 3, ui->pushButton2_6, ui->label2_6->styleSheet(), ui->scrollArea_4->widget(), this));
    charbuttons.push_back(new SelectButton(400, 2, 100, 1, ui->label2_7, vec, v2, 3, ui->pushButton2_7, ui->label2_7->styleSheet(), ui->scrollArea_4->widget(), this));
    charbuttons.push_back(new SelectButton(320, 2, 80, 2, ui->label2_8, vec, v2, 3, ui->pushButton2_8, ui->label2_8->styleSheet(), ui->scrollArea_4->widget(), this));
    charbuttons.push_back(new SelectButton(240, 2, 100, 2, ui->label2_9, vec, v2, 0, ui->pushButton2_9, ui->label2_9->styleSheet(), ui->scrollArea_4->widget(), this));
    charbuttons.push_back(new SelectButton(400, 2, 80, 1, ui->label2_10, vec, v2, 0, ui->pushButton2_10, ui->label2_10->styleSheet(), ui->scrollArea_4->widget(), this));
    charbuttons.push_back(new SelectButton(320, 2, 110, 1, ui->label2_11, vec, v2, 0, ui->pushButton2_11, ui->label2_11->styleSheet(), ui->scrollArea_4->widget(), this));
    charbuttons.push_back(new SelectButton(400, 2, 100, 1, ui->label2_12, vec, v2, 0, ui->pushButton2_12, ui->label2_12->styleSheet(), ui->scrollArea_4->widget(), this));
    charbuttons.push_back(new SelectButton(160, 2, 100, 2,ui->label2_13, vec, v2, 0, ui->pushButton2_13, ui->label2_13->styleSheet(), ui->scrollArea_4->widget(), this));
    charbuttons.push_back(new SelectButton(320, 2, 100, 2, ui->label2_14, vec, v2, 0, ui->pushButton2_14, ui->label2_14->styleSheet(), ui->scrollArea_4->widget(), this));
    charbuttons.push_back(new SelectButton(400, 2, 100, 1,ui->label2_15, vec, v2, 0, ui->pushButton2_15, ui->label2_15->styleSheet(), ui->scrollArea_4->widget(), this));
    charbuttons.push_back(new SelectButton(280, 2, 140, 2, ui->label2_16, vec, v2, 0, ui->pushButton2_16, ui->label2_16->styleSheet(), ui->scrollArea_4->widget(), this));
    charbuttons.push_back(new SelectButton(320, 3, 120, 1, ui->label2_17, vec, v2, 1, ui->pushButton2_17, ui->label2_17->styleSheet(), ui->scrollArea_4->widget(), this));
    charbuttons.push_back(new SelectButton(320, 3, 100, 1, ui->label2_18, vec, v2, 2, ui->pushButton2_18, ui->label2_18->styleSheet(), ui->scrollArea_4->widget(), this));
    charbuttons.push_back(new SelectButton(400, 2, 120, 1, ui->label2_19, vec, v2, 0, ui->pushButton2_19, ui->label2_19->styleSheet(), ui->scrollArea_4->widget(), this));
    charbuttons.push_back(new SelectButton(320, 2, 90, 1, ui->label2_20, vec, v2, 0, ui->pushButton2_20, ui->label2_20->styleSheet(), ui->scrollArea_4->widget(), this));
    charbuttons.push_back(new SelectButton(400, 2, 100, 1,ui->label2_21, vec, v2, 0, ui->pushButton2_21, ui->label2_21->styleSheet(), ui->scrollArea_4->widget(), this));
    charbuttons.push_back(new SelectButton(260, 2, 80, 2,ui->label2_22, vec, v2, 0, ui->pushButton2_22, ui->label2_22->styleSheet(), ui->scrollArea_4->widget(), this));
    charbuttons.push_back(new SelectButton(240, 3, 120, 2, ui->label2_23, vec, v2, 2, ui->pushButton2_23, ui->label2_23->styleSheet(), ui->scrollArea_4->widget(), this));

}

MainPage::~MainPage()
{
    delete ui;
}


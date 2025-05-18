#include "mainpage.h"
#include "ui_mainpage.h"
#include <QApplication>
#include <QLabel>
#include <QObject>
#include <QWidget>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QEvent>
#include <vector>
#include <QPushButton>
#include <QMessageBox>



QVector<QPushButton*> vec, v1, v2;
std::vector<int> hex;

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

void changeBack(){

    for(int i = 0; i < vec.size(); i++){
        QPushButton *p = vec[i];
        int c = hex[i];
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
    SelectButton(QLabel *linkedCharacter,QVector<QPushButton*>& buttons,
        QVector<QPushButton*>& valid, QWidget *parent = nullptr)
        : QPushButton("Select", parent),
        characterLabel(linkedCharacter),
        allButtons(buttons),
        validButtons(valid)   {
        this->setStyleSheet("background-color: #F0E4DA;"
                            "color: #3E3A39;"
                            "border: 2px solid #C8A974;"
                            "border-radius: 6px;"
                            "padding: 4px 8px;"
                            "font-family: 'Black Ops One' ;"
                            "font-size: 14px;"
                            "letter-spacing: 1px;");
        connect(this, &QPushButton::clicked, this, [this, parent]() {
            if(hasCharachter){
                QMessageBox msgBox(QMessageBox::Warning,
                                   "Warning",
                                   "This character has already been chosen",
                                   QMessageBox::Ok,
                                   parent);
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
            waitingForTarget = true;
            int cnt = 0;
            for(QPushButton *p : allButtons){
                p->raise();
                if(!validButtons.contains(p))
                    changeStyle(p, hex[cnt]);
                cnt++;
            }
            }
        });
    }
        void addvec(MainPage *parent, QVector<SelectButton*>sb){
            MainPage *m = parent;
            for(QPushButton *p : allButtons){
                connect(p, &QPushButton::clicked, p, [=](){
                    if(waitingForTarget){
                        if(validButtons.contains(p)){
                            double x = p->x() - 80;
                            double y = p->y() - 50;
                            characterLabel->setGeometry(x, y, 271, 181);
                            m->centralWidget()->raise();

                            validButtons.removeAll(p);

                            changeBack();
                            m->centralWidget()->raise();
                            for(SelectButton *s : sb)
                                s->raise();
                            hasCharachter = true;
                        }
                        else{
                            QMessageBox msgBox1(QMessageBox::Warning,
                                               "Warning",
                                               "Choose a valid tile to continue",
                                               QMessageBox::Ok,
                                               parent);
                            msgBox1.setStyleSheet(
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
                            msgBox1.exec();

                            //QMessageBox::warning(parent, "Warning", "Choose a valid tile to continue", "OK");

                            changeBack();
                            m->centralWidget()->raise();
                            for(SelectButton *s : sb)
                                s->raise();

                        }
                        waitingForTarget = false;

                    }
                });
            }
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

class tile : public QPushButton {
   // Q_OBJECT
    public:
    tile(double x, double y, QWidget *p) {
        w = new QPushButton(p);
        w->setGeometry(x, y, 100, 86);
        vec.push_back(w);
    }

    void pic(int c) {
        if (c == 0 || c == 1 || c == 2)
            w->setStyleSheet("image: url(:/new/prefix3/d.png); "
                             "background-color: transparent");
        else if (c == 3)
            w->setStyleSheet("image: url(:/new/prefix4/water.png);"
                             "background-color: transparent");
        else
            w->setStyleSheet("image: url(:/new/prefix5/rock.png);"
                             "background-color: transparent");
        w->show();
    }



private:
    QPushButton *w;
};




tile *cell[8][8] = {};

MainPage::MainPage(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainPage)
{
    ui->setupUi(this);

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
                hex.push_back(0);
            if(content[0]=='~')
                hex.push_back(3);
            if(content[0]=='#')
                hex.push_back(4);
            if(content[0]=='1')
                hex.push_back(1);
            if(content[0]=='2')
                hex.push_back(2);
            startIndex = endIndex + 1;
       }
    }
    file.close();

    for(int i : hex)
        qDebug() << i;

    float size = 20; // اندازه هر شش‌ضلعی
    float height = sqrt(3) * size;

    int cnt = 0;
    for (int row = 0; row < 5; ++row) {
        for (int col = 0; col < 9; col+=2) {
            double x = (size * 3.0/2 + 55.0) * col;
            double y = (height + 55.0) * (row + 0.5 * (col % 2));
            if(col % 2 && row == 4) continue;
            cell[row][col] = new tile(x + 280, y + 150, this);
            if(hex[cnt] == 1) v1.push_back(vec[cnt]);
            else if(hex[cnt] == 2) v2.push_back(vec[cnt]);
            cell[row][col]->pic( hex[cnt++] );
            if(col == 8) col = -1;

        }
    }

    ui->centralwidget->raise();
    ui->centralwidget->setStyleSheet("background-color: transparent");

    chars.push_back(ui->label); chars.push_back(ui->label_2); chars.push_back(ui->label_3);
    chars.push_back(ui->label_4); chars.push_back(ui->label_5); chars.push_back(ui->label_6);
    charbuttons.push_back(new SelectButton(ui->label, vec, v1, this) );
    charbuttons[0]->setGeometry(80, 170, 75, 24);

    charbuttons.push_back(new SelectButton(ui->label_2, vec, v1, this) );
    charbuttons[1]->setGeometry(90, 430, 75, 24);

    charbuttons.push_back(new SelectButton(ui->label_3, vec, v1, this) );
    charbuttons[2]->setGeometry(90, 660, 75, 24);

    charbuttons.push_back(new SelectButton(ui->label_4, vec, v2, this) );
    charbuttons[3]->setGeometry(1190, 170, 75, 24);

    charbuttons.push_back(new SelectButton(ui->label_5, vec, v2, this) );
    charbuttons[4]->setGeometry(1200, 430, 75, 24);

    charbuttons.push_back(new SelectButton(ui->label_6, vec, v2, this) );
    charbuttons[5]->setGeometry(1200, 660, 75, 24);

    charbuttons[0]->addvec(this, charbuttons);
    charbuttons[1]->addvec(this, charbuttons);
    charbuttons[2]->addvec(this, charbuttons);
    charbuttons[3]->addvec(this, charbuttons);
    charbuttons[4]->addvec(this, charbuttons);
    charbuttons[5]->addvec(this, charbuttons);



}

MainPage::~MainPage()
{
    delete ui;
}

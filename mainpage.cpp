#include "mainpage.h"
#include "ui_mainpage.h"
#include <QApplication>
#include <QLabel>
#include <QObject>
#include <QWidget>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <vector>

#include <QMessageBox>
#include <QWidget>
#include <QPushButton>
#include <QLabel>

#include <QEvent>
#include <QDebug>

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
    SelectButton(QLabel *linkedCharacter,const QVector<QPushButton*>& buttons,
        const QVector<QPushButton*>& valid, QWidget *parent = nullptr)
        : QPushButton("Select", parent),
        characterLabel(linkedCharacter),
        allButtons(buttons),
        validButtons(valid)   {
        connect(this, &QPushButton::clicked, this, [this, parent]() {
            waitingForTarget = true;
            int cnt = 0;
            for(QPushButton *p : allButtons){
                p->raise();
                if(!validButtons.contains(p))
                    changeStyle(p, hex[cnt]);
                cnt++;
            }
        });
    }
        void addvec(const QVector<QPushButton*>& buttons,
                    const QVector<QPushButton*>& valid,
                    MainPage *parent){
            MainPage *m = parent;
            for(QPushButton *p : allButtons){
                connect(p, &QPushButton::clicked, p, [=](){
                    if(waitingForTarget){
                        if(validButtons.contains(p)){
                            double x = p->x() - 80;
                            double y = p->y() - 50;
                            characterLabel->setGeometry(x, y, 271, 181);
                            m->centralWidget()->raise();
                        }
                        else{
                            QMessageBox::warning(parent, "Warning", "Choose a valid tile to continue", "OK");
                            changeBack();
                            m->centralWidget()->raise();
                            this->raise();

                        }
                        waitingForTarget = false;

                    }
                });
            }
        }


private:
    QLabel *characterLabel;
    QVector<QPushButton*> allButtons;
    QVector<QPushButton*> validButtons;
    bool waitingForTarget = false;
};

class tile : public QPushButton {
   // Q_OBJECT
    public:
    tile(double x, double y, QWidget *p) {
        w = new QPushButton(p);
        w->setGeometry(x, y, 100, 86);
        w->installEventFilter(p);
        vec.push_back(w);  // اضافه کردن پوش باتن به لیست

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

    QString fileName = ":/new/prefix1/board/grid1.txt";

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
            //qDebug() << hex[hex.size()-1];
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
    SelectButton *btn = new SelectButton(ui->label, vec, v1, this);
    btn->setGeometry(100, 250, 74, 24);
    btn->addvec(vec, v1, this);

}

MainPage::~MainPage()
{
    delete ui;
}

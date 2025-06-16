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

QVector<QPushButton*> vec, v1, v2;
std::vector<int> hexa;

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
#include <QFile>
#include <QTextStream>
#include <QDebug>

void changeBack(){

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
    SelectButton(QLabel *linkedCharacter,QVector<QPushButton*>& buttons,
        QVector<QPushButton*>& valid, int type,
        QPushButton *s, QString style, QWidget *parent1 = nullptr,
                 MainPage *parent2 = nullptr)
        : QPushButton(parent1),
        characterLabel(linkedCharacter),
        allButtons(buttons),
        validButtons(valid)   {
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


        for(QPushButton *p : allButtons){
            connect(p, &QPushButton::clicked, p, [=, this, &linkedCharacter](){
                if(waitingForTarget){

                    if(validButtons.contains(p)){
                        double x = p->x()-10;
                        double y = p->y();
                        Agent *charachter; // از نوعش نیو کن

                        if(type == 0)
                            charachter = new Grounded(parent2);
                        else if(type == 1)
                        charachter = new flying(parent2);
                        else if(type == 2)
                            charachter = new floating;
                        else
                            charachter = new waterWalking(parent2);
                        QString oldStyle = style;
                        QString newRule = "QPushButton {border: none; background-color: transparent;";
                        QString updatedStyle = newRule + ' ' + oldStyle +"}";

                        charachter->setStyleSheet(updatedStyle);
                        qDebug() <<"LL"<< characterLabel->styleSheet();
                        charachter->setAttribute(Qt::WA_TranslucentBackground);
                        charachter->setGeometry(x, y, 140, 90);
                        charachter->show();
                        currentPlayer.addAgent(charachter);
                        //m->centralWidget()->raise();

                        validButtons.removeAll(p);

                        changeBack();
                        for(Agent * a : currentPlayer.playerAgents){
                            a->raise();
                        }
                        /*m->centralWidget()->raise();
                        for(SelectButton *s : sb)
                            s->raise();*/

                        hasCharachter = true;
                    }
                    else{
                        QMessageBox msgBox1(QMessageBox::Warning,
                                            "Warning",
                                            "Choose a valid tile to continue",
                                            QMessageBox::Ok,
                                            parent2);
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
                        parent2->centralWidget()->raise();
                        for(QPushButton *s : allButtons)
                            s->lower();

                    }
                    waitingForTarget = false;

                }
            });
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
    float height = sqrt(3) * size;

    int cnt = 0;
    for (int row = 0; row < 5; ++row) {
        for (int col = 0; col < 9; col+=2) {
            double x = (size * 3.0/2 + 55.0) * col;
            double y = (height + 55.0) * (row + 0.5 * (col % 2));
            if(col % 2 && row == 4) continue;
            cell[row][col] = new tile(x + 280, y + 150, this, hexa[cnt]);
            if(hexa[cnt] == 1) v1.push_back(vec[cnt]);
            else if(hexa[cnt] == 2) v2.push_back(vec[cnt]);
            cell[row][col]->pic( hexa[cnt++] );
            if(col == 8) col = -1;

        }
    }

    qDebug() << vec.size() << "******************\n";
    ui->centralwidget->raise();
    ui->centralwidget->setStyleSheet("background-color: transparent");
    for(QPushButton *p : vec){
        p->raise();
    }
    /*charbuttons = {new SelectButton(ui->label_13, vec, v2,ui->pushButton_7, ui->scrollAreaWidgetContents, this),
                   new SelectButton(ui->label_14, vec, v2,ui->pushButton_8, ui->scrollAreaWidgetContents, this),
                   new SelectButton(ui->label_15, vec, v2,ui->pushButton_9, ui->scrollAreaWidgetContents, this),
                   new SelectButton(ui->label_16, vec, v2,ui->pushButton_10, ui->scrollAreaWidgetContents, this),
                   new SelectButton(ui->label_17, vec, v2,ui->pushButton_11, ui->scrollAreaWidgetContents, this),
                   new SelectButton(ui->label_18, vec, v2,ui->pushButton_12, ui->scrollAreaWidgetContents, this),
                   new SelectButton(ui->label_19, vec, v2,ui->pushButton_13, ui->scrollAreaWidgetContents, this),
                   new SelectButton(ui->label_20, vec, v2,ui->pushButton_14, ui->scrollAreaWidgetContents, this)};}

*/

    chars.push_back(ui->label_1); chars.push_back(ui->label_2); chars.push_back(ui->label_3);
    chars.push_back(ui->label_4); chars.push_back(ui->label_5); chars.push_back(ui->label_6);
    chars.push_back(ui->label_7); chars.push_back(ui->label_8); chars.push_back(ui->label_9);
    chars.push_back(ui->label_10); chars.push_back(ui->label_11); chars.push_back(ui->label_12);
    chars.push_back(ui->label_13); chars.push_back(ui->label_14); chars.push_back(ui->label_15);
    chars.push_back(ui->label_16); chars.push_back(ui->label_17); chars.push_back(ui->label_18);
    chars.push_back(ui->label_19); chars.push_back(ui->label_20); chars.push_back(ui->label_21);
    chars.push_back(ui->label_22); chars.push_back(ui->label_23); chars.push_back(ui->label_24);
    chars.push_back(ui->label_25); chars.push_back(ui->label_26); chars.push_back(ui->label_27);
    chars.push_back(ui->label_28);


    qDebug()<<ui->label_28->styleSheet();
    currentPlayer = player1;


   // charbuttons[0]->addvec(this, charbuttons);

    charbuttons.push_back(new SelectButton(ui->label_1, vec, v1, 1, ui->pushButton_1, ui->label_1->styleSheet(), ui->scrollArea_2->widget(), this));
    charbuttons.push_back(new SelectButton(ui->label_2, vec, v1, 1, ui->pushButton_2, ui->label_2->styleSheet(), ui->scrollArea_2->widget(), this));
    charbuttons.push_back(new SelectButton(ui->label_3, vec, v1, 1, ui->pushButton_3, ui->label_3->styleSheet(), ui->scrollArea_2->widget(), this));
    charbuttons.push_back(new SelectButton(ui->label_4, vec, v1, 1, ui->pushButton_4, ui->label_4->styleSheet(), ui->scrollArea_2->widget(), this));
    charbuttons.push_back(new SelectButton(ui->label_5, vec, v1, 1, ui->pushButton_5, ui->label_5->styleSheet(), ui->scrollArea_2->widget(), this));
    charbuttons.push_back(new SelectButton(ui->label_6, vec, v1, 1, ui->pushButton_6, ui->label_6->styleSheet(), ui->scrollArea_2->widget(), this));
    charbuttons.push_back(new SelectButton(ui->label_7, vec, v1, 1, ui->pushButton_7, ui->label_7->styleSheet(), ui->scrollArea_2->widget(), this));
    charbuttons.push_back(new SelectButton(ui->label_8, vec, v1, 1, ui->pushButton_8, ui->label_8->styleSheet(), ui->scrollArea_2->widget(), this));
    charbuttons.push_back(new SelectButton(ui->label_9, vec, v1, 1, ui->pushButton_9, ui->label_9->styleSheet(), ui->scrollArea_2->widget(), this));
    charbuttons.push_back(new SelectButton(ui->label_10, vec, v1, 1, ui->pushButton_10, ui->label_10->styleSheet(), ui->scrollArea_2->widget(), this));
    charbuttons.push_back(new SelectButton(ui->label_11, vec, v1, 1, ui->pushButton_11, ui->label_11->styleSheet(), ui->scrollArea_2->widget(), this));
    charbuttons.push_back(new SelectButton(ui->label_12, vec, v1, 1, ui->pushButton_12, ui->label_12->styleSheet(), ui->scrollArea_2->widget(), this));
    charbuttons.push_back(new SelectButton(ui->label_13, vec, v1, 1, ui->pushButton_13, ui->label_13->styleSheet(), ui->scrollArea_2->widget(), this));
    charbuttons.push_back(new SelectButton(ui->label_14, vec, v1, 1, ui->pushButton_14, ui->label_14->styleSheet(), ui->scrollArea_2->widget(), this));
    charbuttons.push_back(new SelectButton(ui->label_15, vec, v1, 1, ui->pushButton_15, ui->label_15->styleSheet(), ui->scrollArea_2->widget(), this));
    charbuttons.push_back(new SelectButton(ui->label_16, vec, v1, 1, ui->pushButton_16, ui->label_16->styleSheet(), ui->scrollArea_2->widget(), this));
    charbuttons.push_back(new SelectButton(ui->label_17, vec, v1, 1, ui->pushButton_17, ui->label_17->styleSheet(), ui->scrollArea_2->widget(), this));
    charbuttons.push_back(new SelectButton(ui->label_18, vec, v1, 1, ui->pushButton_18, ui->label_18->styleSheet(), ui->scrollArea_2->widget(), this));
    charbuttons.push_back(new SelectButton(ui->label_19, vec, v1, 1, ui->pushButton_19, ui->label_19->styleSheet(), ui->scrollArea_2->widget(), this));
    charbuttons.push_back(new SelectButton(ui->label_20, vec, v1, 1, ui->pushButton_20, ui->label_20->styleSheet(), ui->scrollArea_2->widget(), this));
    charbuttons.push_back(new SelectButton(ui->label_21, vec, v1, 1, ui->pushButton_21, ui->label_21->styleSheet(), ui->scrollArea_2->widget(), this));
    charbuttons.push_back(new SelectButton(ui->label_22, vec, v1, 1, ui->pushButton_22, ui->label_22->styleSheet(), ui->scrollArea_2->widget(), this));
    charbuttons.push_back(new SelectButton(ui->label_23, vec, v1, 1, ui->pushButton_23, ui->label_23->styleSheet(), ui->scrollArea_2->widget(), this));
    charbuttons.push_back(new SelectButton(ui->label_24, vec, v1, 1, ui->pushButton_24, ui->label_24->styleSheet(), ui->scrollArea_2->widget(), this));
    charbuttons.push_back(new SelectButton(ui->label_25, vec, v1, 1, ui->pushButton_25, ui->label_25->styleSheet(), ui->scrollArea_2->widget(), this));
    charbuttons.push_back(new SelectButton(ui->label_26, vec, v1, 1, ui->pushButton_26, ui->label_26->styleSheet(), ui->scrollArea_2->widget(), this));
    charbuttons.push_back(new SelectButton(ui->label_27, vec, v1, 1, ui->pushButton_27, ui->label_27->styleSheet(), ui->scrollArea_2->widget(), this));
    charbuttons.push_back(new SelectButton(ui->label_28, vec, v1, 1, ui->pushButton_28, ui->label_28->styleSheet(), ui->scrollArea_2->widget(), this));

    chars.push_back(ui->label2_1); chars.push_back(ui->label2_2); chars.push_back(ui->label2_3);
    chars.push_back(ui->label2_4); chars.push_back(ui->label2_5); chars.push_back(ui->label2_6);
    chars.push_back(ui->label2_7); chars.push_back(ui->label2_8); chars.push_back(ui->label2_9);
    chars.push_back(ui->label2_10); chars.push_back(ui->label2_11); chars.push_back(ui->label2_12);
    chars.push_back(ui->label2_13); chars.push_back(ui->label2_14); chars.push_back(ui->label2_15);
    chars.push_back(ui->label2_16); chars.push_back(ui->label2_17); chars.push_back(ui->label2_18);
    chars.push_back(ui->label2_19); chars.push_back(ui->label2_20); chars.push_back(ui->label2_21);
    chars.push_back(ui->label2_22); chars.push_back(ui->label2_23);

    charbuttons.push_back(new SelectButton(ui->label2_1, vec, v2, 1, ui->pushButton2_1, ui->label2_1->styleSheet(), ui->scrollArea_4->widget(), this));
    charbuttons.push_back(new SelectButton(ui->label2_2, vec, v2, 1, ui->pushButton2_2, ui->label2_2->styleSheet(), ui->scrollArea_4->widget(), this));
    charbuttons.push_back(new SelectButton(ui->label2_3, vec, v2, 1, ui->pushButton2_3, ui->label2_3->styleSheet(), ui->scrollArea_4->widget(), this));
    charbuttons.push_back(new SelectButton(ui->label2_4, vec, v2, 1, ui->pushButton2_4, ui->label2_4->styleSheet(), ui->scrollArea_4->widget(), this));
    charbuttons.push_back(new SelectButton(ui->label2_5, vec, v2, 1, ui->pushButton2_5, ui->label2_5->styleSheet(), ui->scrollArea_4->widget(), this));
    charbuttons.push_back(new SelectButton(ui->label2_6, vec, v2, 1, ui->pushButton2_6, ui->label2_6->styleSheet(), ui->scrollArea_4->widget(), this));
    charbuttons.push_back(new SelectButton(ui->label2_7, vec, v2, 1, ui->pushButton2_7, ui->label2_7->styleSheet(), ui->scrollArea_4->widget(), this));
    charbuttons.push_back(new SelectButton(ui->label2_8, vec, v2, 1, ui->pushButton2_8, ui->label2_8->styleSheet(), ui->scrollArea_4->widget(), this));
    charbuttons.push_back(new SelectButton(ui->label2_9, vec, v2, 1, ui->pushButton2_9, ui->label2_9->styleSheet(), ui->scrollArea_4->widget(), this));
    charbuttons.push_back(new SelectButton(ui->label2_10, vec, v2, 1, ui->pushButton2_10, ui->label2_10->styleSheet(), ui->scrollArea_4->widget(), this));
    charbuttons.push_back(new SelectButton(ui->label2_11, vec, v2, 1, ui->pushButton2_11, ui->label2_11->styleSheet(), ui->scrollArea_4->widget(), this));
    charbuttons.push_back(new SelectButton(ui->label2_12, vec, v2, 1, ui->pushButton2_12, ui->label2_12->styleSheet(), ui->scrollArea_4->widget(), this));
    charbuttons.push_back(new SelectButton(ui->label2_13, vec, v2, 1, ui->pushButton2_13, ui->label2_13->styleSheet(), ui->scrollArea_4->widget(), this));
    charbuttons.push_back(new SelectButton(ui->label2_14, vec, v2, 1, ui->pushButton2_14, ui->label2_14->styleSheet(), ui->scrollArea_4->widget(), this));
    charbuttons.push_back(new SelectButton(ui->label2_15, vec, v2, 1, ui->pushButton2_15, ui->label2_15->styleSheet(), ui->scrollArea_4->widget(), this));
    charbuttons.push_back(new SelectButton(ui->label2_16, vec, v2, 1, ui->pushButton2_16, ui->label2_16->styleSheet(), ui->scrollArea_4->widget(), this));
    charbuttons.push_back(new SelectButton(ui->label2_17, vec, v2, 1, ui->pushButton2_17, ui->label2_17->styleSheet(), ui->scrollArea_4->widget(), this));
    charbuttons.push_back(new SelectButton(ui->label2_18, vec, v2, 1, ui->pushButton2_18, ui->label2_18->styleSheet(), ui->scrollArea_4->widget(), this));
    charbuttons.push_back(new SelectButton(ui->label2_19, vec, v2, 1, ui->pushButton2_19, ui->label2_19->styleSheet(), ui->scrollArea_4->widget(), this));
    charbuttons.push_back(new SelectButton(ui->label2_20, vec, v2, 1, ui->pushButton2_20, ui->label2_20->styleSheet(), ui->scrollArea_4->widget(), this));
    charbuttons.push_back(new SelectButton(ui->label2_21, vec, v2, 1, ui->pushButton2_21, ui->label2_21->styleSheet(), ui->scrollArea_4->widget(), this));
    charbuttons.push_back(new SelectButton(ui->label2_22, vec, v2, 1, ui->pushButton2_22, ui->label2_22->styleSheet(), ui->scrollArea_4->widget(), this));
    charbuttons.push_back(new SelectButton(ui->label2_23, vec, v2, 1, ui->pushButton2_23, ui->label2_23->styleSheet(), ui->scrollArea_4->widget(), this));




/*    SelectButton(QLabel *linkedCharacter,QVector<QPushButton*>& buttons,
        QVector<QPushButton*>& valid, int type,
        QPushButton *s, QWidget *parent1 = nullptr,
                 MainPage *parent2 = nullptr)
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
    charbuttons[5]->addvec(this, charbuttons);*/

}

MainPage::~MainPage()
{
    delete ui;
}

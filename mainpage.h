#ifndef MAINPAGE_H
#define MAINPAGE_H

#include "qpushbutton.h"
#include <QMainWindow>
#include <QObject>
#include "tile.h"
#include <QVector>
class tile;
extern QVector<QPushButton*> vec, v1, v2;
extern bool canGo[5][9];
extern bool canAttack[5][9];

extern tile *cell[5][9];
namespace Ui {
class MainPage;
}

class MainPage : public QMainWindow
{
    Q_OBJECT
    friend class tile;
public:
    explicit MainPage(QWidget *parent = nullptr);
    void hid1();
    void hid2();
    ~MainPage();
    void switchTurn();
    void highlightingMove(QPushButton *p);
    void highlightingAttack(QWidget *p);
    void highlightAtacking(QWidget *m) ;
    void highlight(QWidget *m);
    void loop(QWidget *m);
    QVector <tile*>  getNeighbors(int row, int col);



private:
    Ui::MainPage *ui;
   //bool WaitingForTarget=0;
};

#endif // MAINPAGE_H

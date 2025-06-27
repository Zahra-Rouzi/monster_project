#ifndef MAINPAGE_H
#define MAINPAGE_H

#include "qpushbutton.h"
#include <QMainWindow>
#include <QObject>
#include "tile.h"

extern QVector<QPushButton*> vec, v1, v2;
//extern tile *cell[8][8] = {};
namespace Ui {
class MainPage;
}

class MainPage : public QMainWindow
{
    Q_OBJECT
    friend class tile;
public:
    explicit MainPage(QWidget *parent = nullptr);
    ~MainPage();

private:
    Ui::MainPage *ui;
};

#endif // MAINPAGE_H

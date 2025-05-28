#ifndef MAINPAGE_H
#define MAINPAGE_H

#include "qpushbutton.h"
#include <QMainWindow>
#include <QObject>

extern QVector<QPushButton*> vec, v1, v2;

namespace Ui {
class MainPage;
}

class MainPage : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainPage(QWidget *parent = nullptr);
    ~MainPage();

private:
    Ui::MainPage *ui;
};

#endif // MAINPAGE_H

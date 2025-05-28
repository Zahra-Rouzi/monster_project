#ifndef TILE_H
#define TILE_H

#include "qpushbutton.h"
#include "mainpage.h"
#include <QMainWindow>
#include <QObject>
#include <QQuickItem>
#include <QSharedDataPointer>
#include <QWidget>

class tile : public QPushButton {
    // Q_OBJECT
public:
    tile(double , double , QWidget *, int);

    void pic(int c);

    int getType(){return type;}

private:
    QPushButton *w;
    int type;
};

#endif // TILE_H

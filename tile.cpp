#include "tile.h"
#include "mainpage.h"

tile::tile(double x, double y, QWidget *parent, int t): type(t) {
    w = new QPushButton(parent);
    w->setGeometry(x, y, 100, 86);
    vec.push_back(w);
}

void tile::pic(int c) {
    if (c == 0 || c == 1 || c == 2)
        w->setStyleSheet("image: url(:/new/prefix3/d.png); background-color: transparent");
    else if (c == 3)
        w->setStyleSheet("image: url(:/new/prefix4/water.png); background-color: transparent");
    else
        w->setStyleSheet("image: url(:/new/prefix5/rock.png); background-color: transparent");

    w->show();
}

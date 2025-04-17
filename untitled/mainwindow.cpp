#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QPixmap>

class Tile : public QGraphicsPixmapItem {
public:
    Tile(const QPixmap &normal, const QPixmap &hovered)
        : normalPixmap(normal), hoverPixmap(hovered) {
        setPixmap(normalPixmap);
        setAcceptHoverEvents(true);
    }

protected:
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event) override {
        setPixmap(hoverPixmap);
        //QGraphicsPixmapItem::hoverEnterEvent(event);
    }

    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event) override {
        setPixmap(normalPixmap);
        //QGraphicsPixmapItem::hoverLeaveEvent(event);
    }

private:
    QPixmap normalPixmap;
    QPixmap hoverPixmap;
};

class grass {
public:
    grass() {
        pixG.load(":/new/prefix1/grass.png");
        Hpix.load(":/new/prefix4/GH.png");
    }

    void Add(QGraphicsScene *scene, int x, int y) {
        Tile *item = new Tile(pixG, Hpix);
        scene->addItem(item);
        item->setPos(x, y);
    }

private:
    QPixmap pixG;
    QPixmap Hpix;
};


class rock {
public:
    rock() {
        pixR.load(":/new/prefix2/rock.png");
        Hpix.load(":/new/prefix5/RH.png");
    }

    void Add(QGraphicsScene *scene, int x, int y) {
        Tile *item = new Tile(pixR, Hpix);
        scene->addItem(item);
        item->setPos(x, y);
    }

private:
    QPixmap pixR;
    QPixmap Hpix;
};


class water {
public:
    water() {
        pixW.load(":/new/prefix3/water.png");
        Hpix.load(":/new/prefix6/WH.png");
    }

    void Add(QGraphicsScene *scene, int x, int y) {
        Tile *item = new Tile(pixW, Hpix);
        scene->addItem(item);
        item->setPos(x, y);
    }

private:
    QPixmap pixW;
    QPixmap Hpix;
};

grass *cellG[8][8] = {};
rock  *cellR[8][8] = {};
water *cellW[8][8] = {};

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    // ایجاد صحنه و اتصال به QGraphicsView داخل فرم
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setSceneRect(0, 0, ui->graphicsView->width(), ui->graphicsView->height());

    // مقداردهی آیتم‌ها در صحنه (مانند کد شما)
    int tileWidth = 140;
    int tileHeight = 70;
    int boardSize = 8;

    for (int row = 0; row < boardSize; ++row) {
        for (int col = 0; col < boardSize; ++col) {
            QString type = "grass";
            if ((row == 1 && col == 1) || (row == 6 && col == 6))
                type = "rock";
            else if ((row == 3 && col == 4) || (row == 4 && col == 3))
                type = "water";

            int x = (col - row) * (tileWidth / 2);
            int y = (col + row) * (tileHeight / 2);

            if (type == "grass") {
                grass *cellG = new grass;
                cellG->Add(scene, x + boardSize * (tileWidth / 2), y);
            } else if (type == "rock") {
                rock *cellR = new rock;
                cellR->Add(scene, x + boardSize * (tileWidth / 2), y);
            } else if (type == "water") {
                water *cellW = new water;
                cellW->Add(scene, x + boardSize * (tileWidth / 2), y);
            }
        }
    }
   // ui->graphicsView->setGeometry(0, 0, width(), height());


}

MainWindow::~MainWindow() {
    delete ui;
}

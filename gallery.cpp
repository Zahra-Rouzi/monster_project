#include "gallery.h"
#include "ui_gallery.h"
#include "startPage.h"
Gallery::Gallery(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Gallery)
{
    ui->setupUi(this);
}

Gallery::~Gallery()
{
    delete ui;
}

void Gallery::on_pushButton_clicked()
{
    startPage *w2 = new startPage;
    w2->showFullScreen();
    this->close();
}


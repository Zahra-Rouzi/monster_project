#include "gallery.h"
#include "ui_gallery.h"

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

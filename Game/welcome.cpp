#include "welcome.h"
#include "startPage.h"
#include "ui_welcome.h"

Welcome::Welcome(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Welcome)
{
    ui->setupUi(this);

}

Welcome::~Welcome()
{
    delete ui;
}

void Welcome::on_pushButton_clicked()
{
    startPage *w2 = new startPage;
    w2->showFullScreen();
    this->close();
}


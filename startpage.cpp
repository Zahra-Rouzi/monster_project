#include "startpage.h"
#include "ui_startpage.h"
#include "QMessageBox"
#include "mainpage.h"
#include "gallery.h"

startPage::startPage(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::startPage)
{
    ui->setupUi(this);
    ui->lineEdit->hide();
    ui->label->hide();
    ui->ok->hide();
    ui->pushButton->hide();
}


startPage::~startPage()
{
    delete ui;
}

void startPage::on_exit_clicked()
{
    this->close();
}


void startPage::on_start_clicked()
{
    ui->label->show();
    ui->lineEdit->show();
    ui->ok->show();
    ui->Gallery->hide();
    ui->exit->hide();
    ui->start->hide();
}


void startPage::on_ok_clicked()
{
    QString s = ui->lineEdit->text();

    if(s != ""){
        ui->label->setText("                Player 2:");
        ui->lineEdit->setText("");
        ui->ok->hide();
        ui->pushButton->show();
    }
    else{
        QMessageBox::warning(this, "Warning!", "Please Enter Your Name");
    }
}


void startPage::on_pushButton_clicked()
{
    QString s = ui->lineEdit->text();
    if(s == ""){
        QMessageBox::warning(this, "Warning!", "Please Enter Your Name");
    }
    else{
        MainPage *w3 = new MainPage;
        w3->showFullScreen();
        this->close();
    }
}


void startPage::on_Gallery_clicked()
{
    Gallery *w4 = new Gallery;
    w4->show();
    this->close();
}


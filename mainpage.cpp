#include "mainpage.h"
#include "ui_mainpage.h"
#include <QApplication>
#include <QLabel>
#include <QWidget>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <vector>

class tile{

    public:
    tile(double x, double y, QWidget *p){
        w = new QLabel(p);
     //   w->lower();
        w->setGeometry(x, y, 100, 86);
    }
    void pic(int c){

        if(c == 0 || c == 1 || c == 2)
            w->setStyleSheet("image: url(:/new/prefix3/d.png); "
                             "background-color: transparent");
        else if(c == 3)
            w->setStyleSheet("image: url(:/new/prefix4/water.png);"
                             "background-color: transparent");
        else
            w->setStyleSheet("image: url(:/new/prefix5/rock.png);"
                             "background-color: transparent");
        w->show();
    }

    private:
        QLabel *w;
};

tile *cell[8][8] = {};

MainPage::MainPage(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainPage)
{
    ui->setupUi(this);


    std::vector<int> hex;

    // نام فایل را مشخص کنید
    QString fileName = ":/new/prefix1/board/grid1.txt";

    // ایجاد یک شی QFile
    QFile file(fileName);

    // بررسی اینکه آیا فایل باز می‌شود یا خیر
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Cannot open file for reading:" << file.errorString();
        exit;
    }

    // ایجاد یک QTextStream برای خواندن محتویات فایل
    QTextStream in(&file);

    // خواندن خط به خط
    while (!in.atEnd()) {
        QString line = in.readLine();
        int startIndex = 0;
        // جستجوی کاراکترها بین / و \

        while (true) {
            startIndex = line.indexOf('/', startIndex);
            if (startIndex == -1) break; // اگر / پیدا نشد، جستجو را متوقف کنید

            int endIndex = line.indexOf('\\', startIndex);
            if (endIndex == -1) break; // اگر \ پیدا نشد، جستجو را متوقف کنید
            QString content = line.mid(startIndex + 1, endIndex - startIndex - 1);
            // استخراج محتوای بین / و \


            // بررسی شرایط





            if (content.isEmpty()) {
                // اگر دو تا اسپیس بود، هیچ کاری نکنید
                //qDebug() << "Found empty content between slashes.";
                hex.push_back(0);

            } else {
                // اگر چیز دیگه‌ای بود، ذخیره کنید
                qDebug() << "Found content:" << content;
                if(content[0]=='~'){
                    hex.push_back(3);
                }
                if(content[0]=='#'){
                    hex.push_back(4);
                }
                if(content[0]=='1'){
                    hex.push_back(1);
                }
                if(content[0]=='2'){
                    hex.push_back(2);
              }

        }

            // ادامه جستجو
        startIndex = endIndex + 1;
    }
 }


    // بستن فایل
    file.close();
    float size = 20; // اندازه هر شش‌ضلعی
    float height = sqrt(3) * size;

    int cnt = 0;
    for (int row = 0; row < 5; ++row) {
        for (int col = 0; col < 9; ++col) {
            double x = (size * 3.0/2 + 55.0) * col;
            double y = (height + 55.0) * (row + 0.5 * (col % 2));
            if(row == 2 && col == 4)
                ui->label_2->setGeometry(x+200, y+100, 271, 181);
            if(row == 4 && col == 8)
                ui->label_3->setGeometry(x+200, y+100, 271, 181);
            if(col % 2 && row == 4) continue;
            cell[row][col] = new tile(x + 280, y + 150, this);
            cell[row][col]->pic( hex[cnt++] );

        }
    }
    ui->label->setGeometry(200, 100, 271, 181);

    ui->centralwidget->raise();
    ui->centralwidget->setStyleSheet("background-color: transparent");
    ui->centralwidget->hide();

 //   ui->graphicsView->rotate(-90);
}

MainPage::~MainPage()
{
    delete ui;
}

/********************************************************************************
** Form generated from reading UI file 'mainpage.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINPAGE_H
#define UI_MAINPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainPage
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton_6;
    QListWidget *listWidget_2;
    QPushButton *pushButton_5;
    QLabel *label_5;
    QLabel *label_6;
    QPushButton *pushButton_4;
    QLabel *label_4;
    QLabel *label_2;
    QLabel *label_3;
    QListWidget *listWidget;
    QLabel *label;
    QPushButton *pushButton_3;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainPage)
    {
        if (MainPage->objectName().isEmpty())
            MainPage->setObjectName("MainPage");
        MainPage->resize(1388, 1074);
        MainPage->setStyleSheet(QString::fromUtf8("background-color: white;"));
        centralwidget = new QWidget(MainPage);
        centralwidget->setObjectName("centralwidget");
        pushButton_6 = new QPushButton(centralwidget);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(1200, 660, 75, 24));
        listWidget_2 = new QListWidget(centralwidget);
        listWidget_2->setObjectName("listWidget_2");
        listWidget_2->setGeometry(QRect(1120, 0, 231, 741));
        listWidget_2->setStyleSheet(QString::fromUtf8("\n"
"  background-color: rgba(255, 239, 200, 0.5);\n"
"    border: 2px solid #D8B47D;\n"
"    border-radius: 10px;\n"
"    margin-top: 20px;\n"
"    padding: 10px;\n"
"    color: #3E3A39;\n"
"   \n"
"\n"
""));
        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(1200, 430, 75, 24));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(1150, 310, 181, 121));
        label_5->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix7/a2.png);\n"
"background-color: transparent;"));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(1170, 530, 151, 141));
        label_6->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix8/a3.png);\n"
"background-color: transparent;"));
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(1190, 170, 75, 24));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(1160, 60, 141, 121));
        label_4->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix6/a1.png);\n"
"background-color: transparent;"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(40, 310, 181, 121));
        label_2->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix7/a2.png);\n"
"background-color: transparent;"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(60, 530, 151, 141));
        label_3->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix8/a3.png);\n"
"background-color: transparent;"));
        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName("listWidget");
        listWidget->setGeometry(QRect(10, 0, 231, 741));
        listWidget->setStyleSheet(QString::fromUtf8("\n"
"  background-color: rgba(255, 239, 200, 0.5);\n"
"    border: 2px solid #D8B47D;\n"
"    border-radius: 10px;\n"
"    margin-top: 20px;\n"
"    padding: 10px;\n"
"    color: #3E3A39;\n"
"   \n"
"\n"
""));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(50, 60, 141, 121));
        label->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix6/a1.png);\n"
"background-color: transparent;"));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(90, 660, 75, 24));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(80, 170, 75, 24));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(90, 430, 75, 24));
        MainPage->setCentralWidget(centralwidget);
        listWidget_2->raise();
        pushButton_5->raise();
        label_5->raise();
        label_6->raise();
        pushButton_4->raise();
        label_4->raise();
        pushButton_6->raise();
        listWidget->raise();
        label->raise();
        pushButton->raise();
        label_2->raise();
        label_3->raise();
        pushButton_2->raise();
        pushButton_3->raise();
        menubar = new QMenuBar(MainPage);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1388, 25));
        MainPage->setMenuBar(menubar);
        statusbar = new QStatusBar(MainPage);
        statusbar->setObjectName("statusbar");
        MainPage->setStatusBar(statusbar);

        retranslateUi(MainPage);

        QMetaObject::connectSlotsByName(MainPage);
    } // setupUi

    void retranslateUi(QMainWindow *MainPage)
    {
        MainPage->setWindowTitle(QCoreApplication::translate("MainPage", "MainWindow", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainPage", "PushButton", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainPage", "PushButton", nullptr));
        label_5->setText(QString());
        label_6->setText(QString());
        pushButton_4->setText(QCoreApplication::translate("MainPage", "PushButton", nullptr));
        label_4->setText(QString());
        label_2->setText(QString());
        label_3->setText(QString());
        label->setText(QString());
        pushButton_3->setText(QCoreApplication::translate("MainPage", "PushButton", nullptr));
        pushButton->setText(QCoreApplication::translate("MainPage", "PushButton", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainPage", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainPage: public Ui_MainPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINPAGE_H

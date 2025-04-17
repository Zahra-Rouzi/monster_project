/********************************************************************************
** Form generated from reading UI file 'welcome.ui'
**
** Created by: Qt User Interface Compiler version 6.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WELCOME_H
#define UI_WELCOME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Welcome
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QLabel *label;
    QLabel *label_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Welcome)
    {
        if (Welcome->objectName().isEmpty())
            Welcome->setObjectName("Welcome");
        Welcome->resize(729, 484);
        Welcome->setStyleSheet(QString::fromUtf8("QMainWindow{\n"
"	\n"
"	background-image: url(:/new/prefix1/Welcome.png);\n"
"	background-size: cover;\n"
"	baclground-repeat: no repeat;\n"
"}\n"
"QWidget {	\n"
"    font-family: \"Black Ops One\", \"Arial Black\", sans-serif;\n"
"    font-size: 14px;\n"
"    border: none;\n"
"}\n"
"\n"
"QPushButton {\n"
"    background-color: #6a415e;\n"
"    color: #fcefe9;\n"
"    border: 2px solid #e8a6a1;\n"
"    border-radius: 0px;\n"
"    padding: 6px 12px;\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #8c5678;\n"
"    border-color: #ffd1c1;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #a8547b;\n"
"    border-color: #ff9c8f;\n"
"}\n"
"\n"
"QLabel {\n"
"    font-size: 24px;\n"
"    font-weight: bold;\n"
"    color: #ffe3d3;\n"
"    border-bottom: 4px solid #6a415e;\n"
"    padding-bottom: 4px;\n"
"}\n"
"\n"
"QProgressBar {\n"
"    background-color: #4b2e45;\n"
"    border: 1px solid #c18187;\n"
"    text-align: center;\n"
"    color: #f"
                        "fece6;\n"
"    border-radius: 0px;\n"
"    font-size: 12px;\n"
"}\n"
"\n"
"QProgressBar::chunk {\n"
"    background-color: #e69da7;\n"
"    width: 10px;\n"
"    margin: 0.5px;\n"
"}\n"
"\n"
"QScrollBar:vertical {\n"
"    border: none;\n"
"    background: #3e2d3e;\n"
"    width: 10px;\n"
"}\n"
"\n"
"QScrollBar::handle:vertical {\n"
"    background: #e8a6a1;\n"
"    min-height: 20px;\n"
"}\n"
"\n"
"QListView, QTableView {\n"
"    background-color: #2a1e2b;\n"
"    alternate-background-color: #3b2a3a;\n"
"    selection-background-color: #d48997;\n"
"    selection-color: #fff0f0;\n"
"}\n"
""));
        centralwidget = new QWidget(Welcome);
        centralwidget->setObjectName("centralwidget");
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(210, 290, 171, 51));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(200, 230, 191, 51));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(110, 100, 431, 81));
        label_2->setStyleSheet(QString::fromUtf8("QLabel#label_2{\n"
"font-size: 40px;\n"
"border: none;\n"
"color: rgb(77, 43, 57);\n"
"}"));
        Welcome->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Welcome);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 729, 24));
        Welcome->setMenuBar(menubar);
        statusbar = new QStatusBar(Welcome);
        statusbar->setObjectName("statusbar");
        Welcome->setStatusBar(statusbar);

        retranslateUi(Welcome);

        QMetaObject::connectSlotsByName(Welcome);
    } // setupUi

    void retranslateUi(QMainWindow *Welcome)
    {
        Welcome->setWindowTitle(QCoreApplication::translate("Welcome", "Welcome", nullptr));
        pushButton->setText(QCoreApplication::translate("Welcome", "start", nullptr));
        label->setText(QCoreApplication::translate("Welcome", "    welcome", nullptr));
        label_2->setText(QCoreApplication::translate("Welcome", "GAME OF SAMURAI", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Welcome: public Ui_Welcome {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WELCOME_H

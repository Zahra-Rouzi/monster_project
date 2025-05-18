/********************************************************************************
** Form generated from reading UI file 'startpage.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STARTPAGE_H
#define UI_STARTPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_startPage
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QPushButton *Gallery;
    QPushButton *start;
    QPushButton *exit;
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *ok;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *startPage)
    {
        if (startPage->objectName().isEmpty())
            startPage->setObjectName("startPage");
        startPage->resize(760, 533);
        startPage->setStyleSheet(QString::fromUtf8("QMainWindow{\n"
"	\n"
"	background-image: url(:/new/prefix2/IMG_20250416_025855.png);\n"
"	background-position: center;\n"
"	background-repeat: no-repeat;\n"
"}\n"
"\n"
"QLabel {\n"
"    color: #3E3A39; \n"
"    font-family: \"Black Ops One\";\n"
"    font-size: 20px;\n"
"    letter-spacing: 1px;\n"
"    background: transparent; \n"
"    border-bottom: 4px solid #6a415e;\n"
"	padding-bottom: 4px;\n"
"}\n"
"\n"
"QMessageBox{\n"
"    \n"
"	background-color: rgb(240, 228, 218);\n"
"    padding: 6px 12px;\n"
"    font-family: \"Black Ops One\";\n"
"    font-size: 17px;\n"
"    letter-spacing: 1px;\n"
"}\n"
"QPushButton {\n"
"    background-color: #D6C2B2; \n"
"    color: #3E3A39; \n"
"    border: 2px solid #C8A974; \n"
"    border-radius: 8px;\n"
"    padding: 6px 12px;\n"
"    font-family: \"Black Ops One\";\n"
"    font-size: 20px;\n"
"    letter-spacing: 1px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #E9D6C0; \n"
"    border: 2px solid #DABF85;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    bac"
                        "kground-color: #BBA89A;  \n"
"    border: 2px solid #A68756;\n"
"    color: #2C2A28;\n"
"}\n"
""));
        centralwidget = new QWidget(startPage);
        centralwidget->setObjectName("centralwidget");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(450, 160, 381, 371));
        groupBox->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"    /*background-color: qlineargradient(\n"
"		x1:0, y1:0, x2:0, y2:1,\n"
"		stop:0 rgb(197, 164, 156),\n"
"		stop:0.5 rgb(146, 126, 131),\n"
"		stop:1 rgb(118, 116, 134)\n"
"	);*/\n"
"    border: 2px solid #D8B47D; /* \330\261\331\206\332\257 \330\267\331\204\330\247\333\214\333\214-\330\256\331\210\330\261\330\264\333\214\330\257\333\214 */\n"
"    border-radius: 10px;\n"
"    margin-top: 20px;\n"
"    padding: 10px;\n"
"    color: #3E3A39; /* \331\205\330\252\331\206 \330\252\333\214\330\261\331\207 \331\210\331\204\333\214 \331\206\331\207 \330\256\333\214\331\204\333\214 \331\205\330\264\332\251\333\214 */\n"
"    font-family: \"Black Ops One\";\n"
"    font-size: 16px;\n"
"    letter-spacing: 1px;\n"
"}\n"
"\n"
"QGroupBox::title {\n"
"    subcontrol-origin: margin;\n"
"    subcontrol-position: top center;\n"
"    padding: 16px 32px;\n"
"    background-color: rgba(255, 239, 200, 0.5); /* \330\261\331\206\332\257 \332\257\330\261\331\205 \331\210 \330\264\331\201\330\247\331\201 \331\205\330"
                        "\253\331\204 \331\206\331\210\330\261 \330\256\331\210\330\261\330\264\333\214\330\257 \330\257\330\261 \331\205\331\207 */\n"
"    color: #5C4634; /* \330\252\333\214\330\261\331\207 \331\210 \330\254\331\206\332\257\333\214 */\n"
"    font-size: 18px;\n"
"    font-weight: bold;\n"
"    border: 1px solid #CBA86E;\n"
"    border-radius: 6px;\n"
"}\n"
""));
        Gallery = new QPushButton(groupBox);
        Gallery->setObjectName("Gallery");
        Gallery->setGeometry(QRect(30, 110, 321, 61));
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(Gallery->sizePolicy().hasHeightForWidth());
        Gallery->setSizePolicy(sizePolicy1);
        Gallery->setStyleSheet(QString::fromUtf8("\n"
"\n"
"QPushButton {\n"
"    background-color: #D6C2B2; /* \331\276\330\263\342\200\214\330\262\331\205\333\214\331\206\331\207\342\200\214\330\247\333\214 \331\205\331\204\330\247\333\214\331\205 \331\210 \330\261\331\210\330\264\331\206\330\214 \330\250\330\261\332\257\330\261\331\201\330\252\331\207 \330\247\330\262 \331\206\331\210\330\261 \330\242\331\201\330\252\330\247\330\250 \330\257\330\261 \331\205\331\207 */\n"
"    color: #3E3A39; /* \330\261\331\206\332\257 \331\205\330\252\331\206\330\214 \330\252\333\214\330\261\331\207 \331\210\331\204\333\214 \332\257\330\261\331\205 */\n"
"    border: 2px solid #C8A974; /* \330\255\330\247\330\264\333\214\331\207 \330\267\331\204\330\247\333\214\333\214 */\n"
"    border-radius: 8px;\n"
"    padding: 6px 12px;\n"
"    font-family: \"Black Ops One\";\n"
"    font-size: 20px;\n"
"    letter-spacing: 1px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #E9D6C0; /* \332\251\331\205\333\214 \330\261\331\210\330\264\331\206\342\200\214\330\252\330\261"
                        " \331\210 \332\257\330\261\331\205\342\200\214\330\252\330\261 \331\207\331\206\332\257\330\247\331\205 \331\207\330\247\331\210\330\261 */\n"
"    border: 2px solid #DABF85;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #BBA89A; /* \330\255\330\247\331\204\330\252 \331\201\330\264\330\247\330\261 \330\257\330\247\330\257\331\207 \330\264\330\257\331\207\330\214 \332\251\331\205\333\214 \330\252\333\214\330\261\331\207\342\200\214\330\252\330\261 \330\250\330\261\330\247\333\214 \330\255\330\263 \331\210\330\262\331\206 */\n"
"    border: 2px solid #A68756;\n"
"    color: #2C2A28;\n"
"}\n"
""));
        start = new QPushButton(groupBox);
        start->setObjectName("start");
        start->setGeometry(QRect(30, 190, 321, 71));
        sizePolicy1.setHeightForWidth(start->sizePolicy().hasHeightForWidth());
        start->setSizePolicy(sizePolicy1);
        start->setMinimumSize(QSize(0, 0));
        start->setStyleSheet(QString::fromUtf8("\n"
"\n"
"QPushButton {\n"
"    background-color: #D6C2B2; /* \331\276\330\263\342\200\214\330\262\331\205\333\214\331\206\331\207\342\200\214\330\247\333\214 \331\205\331\204\330\247\333\214\331\205 \331\210 \330\261\331\210\330\264\331\206\330\214 \330\250\330\261\332\257\330\261\331\201\330\252\331\207 \330\247\330\262 \331\206\331\210\330\261 \330\242\331\201\330\252\330\247\330\250 \330\257\330\261 \331\205\331\207 */\n"
"    color: #3E3A39; /* \330\261\331\206\332\257 \331\205\330\252\331\206\330\214 \330\252\333\214\330\261\331\207 \331\210\331\204\333\214 \332\257\330\261\331\205 */\n"
"    border: 2px solid #C8A974; /* \330\255\330\247\330\264\333\214\331\207 \330\267\331\204\330\247\333\214\333\214 */\n"
"    border-radius: 8px;\n"
"    padding: 6px 12px;\n"
"    font-family: \"Black Ops One\";\n"
"    font-size: 20px;\n"
"    letter-spacing: 1px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #E9D6C0; /* \332\251\331\205\333\214 \330\261\331\210\330\264\331\206\342\200\214\330\252\330\261"
                        " \331\210 \332\257\330\261\331\205\342\200\214\330\252\330\261 \331\207\331\206\332\257\330\247\331\205 \331\207\330\247\331\210\330\261 */\n"
"    border: 2px solid #DABF85;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #BBA89A; /* \330\255\330\247\331\204\330\252 \331\201\330\264\330\247\330\261 \330\257\330\247\330\257\331\207 \330\264\330\257\331\207\330\214 \332\251\331\205\333\214 \330\252\333\214\330\261\331\207\342\200\214\330\252\330\261 \330\250\330\261\330\247\333\214 \330\255\330\263 \331\210\330\262\331\206 */\n"
"    border: 2px solid #A68756;\n"
"    color: #2C2A28;\n"
"}\n"
""));
        exit = new QPushButton(groupBox);
        exit->setObjectName("exit");
        exit->setGeometry(QRect(30, 280, 321, 61));
        sizePolicy1.setHeightForWidth(exit->sizePolicy().hasHeightForWidth());
        exit->setSizePolicy(sizePolicy1);
        exit->setStyleSheet(QString::fromUtf8("\n"
"\n"
"QPushButton {\n"
"    background-color: #D6C2B2; /* \331\276\330\263\342\200\214\330\262\331\205\333\214\331\206\331\207\342\200\214\330\247\333\214 \331\205\331\204\330\247\333\214\331\205 \331\210 \330\261\331\210\330\264\331\206\330\214 \330\250\330\261\332\257\330\261\331\201\330\252\331\207 \330\247\330\262 \331\206\331\210\330\261 \330\242\331\201\330\252\330\247\330\250 \330\257\330\261 \331\205\331\207 */\n"
"    color: #3E3A39; /* \330\261\331\206\332\257 \331\205\330\252\331\206\330\214 \330\252\333\214\330\261\331\207 \331\210\331\204\333\214 \332\257\330\261\331\205 */\n"
"    border: 2px solid #C8A974; /* \330\255\330\247\330\264\333\214\331\207 \330\267\331\204\330\247\333\214\333\214 */\n"
"    border-radius: 8px;\n"
"    padding: 6px 12px;\n"
"    font-family: \"Black Ops One\";\n"
"    font-size: 20px;\n"
"    letter-spacing: 1px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #E9D6C0; /* \332\251\331\205\333\214 \330\261\331\210\330\264\331\206\342\200\214\330\252\330\261"
                        " \331\210 \332\257\330\261\331\205\342\200\214\330\252\330\261 \331\207\331\206\332\257\330\247\331\205 \331\207\330\247\331\210\330\261 */\n"
"    border: 2px solid #DABF85;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #BBA89A; /* \330\255\330\247\331\204\330\252 \331\201\330\264\330\247\330\261 \330\257\330\247\330\257\331\207 \330\264\330\257\331\207\330\214 \332\251\331\205\333\214 \330\252\333\214\330\261\331\207\342\200\214\330\252\330\261 \330\250\330\261\330\247\333\214 \330\255\330\263 \331\210\330\262\331\206 */\n"
"    border: 2px solid #A68756;\n"
"    color: #2C2A28;\n"
"}\n"
""));
        label = new QLabel(groupBox);
        label->setObjectName("label");
        label->setGeometry(QRect(30, 110, 321, 61));
        label->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: #3E3A39; /* \330\261\331\206\332\257 \331\205\330\252\331\206 \332\257\330\261\331\205 \331\210 \330\252\333\214\330\261\331\207 */\n"
"    font-family: \"Black Ops One\";\n"
"    font-size: 20px;\n"
"    letter-spacing: 1px;\n"
"    background: transparent; /* \331\204\333\214\330\250\331\204 \330\264\331\201\330\247\331\201 \330\250\331\205\331\210\331\206\331\207 */\n"
"}"));
        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(30, 190, 321, 71));
        lineEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #F0E4DA;\n"
"    color: #3E3A39;\n"
"    border: 2px solid #C8A974;\n"
"    border-radius: 6px;\n"
"    padding: 4px 8px;\n"
"    font-family: \"Black Ops One\";\n"
"    font-size: 20px;\n"
"    letter-spacing: 1px;\n"
"    qproperty-alignment: 'AlignCenter'; /* \332\251\331\204\333\214\330\257 \332\251\330\247\330\261 \330\247\333\214\331\206 \330\256\330\267\331\207 */\n"
"}"));
        ok = new QPushButton(groupBox);
        ok->setObjectName("ok");
        ok->setGeometry(QRect(130, 280, 121, 51));
        ok->setStyleSheet(QString::fromUtf8("\n"
"\n"
"QPushButton {\n"
"    background-color: #D6C2B2; /* \331\276\330\263\342\200\214\330\262\331\205\333\214\331\206\331\207\342\200\214\330\247\333\214 \331\205\331\204\330\247\333\214\331\205 \331\210 \330\261\331\210\330\264\331\206\330\214 \330\250\330\261\332\257\330\261\331\201\330\252\331\207 \330\247\330\262 \331\206\331\210\330\261 \330\242\331\201\330\252\330\247\330\250 \330\257\330\261 \331\205\331\207 */\n"
"    color: #3E3A39; /* \330\261\331\206\332\257 \331\205\330\252\331\206\330\214 \330\252\333\214\330\261\331\207 \331\210\331\204\333\214 \332\257\330\261\331\205 */\n"
"    border: 2px solid #C8A974; /* \330\255\330\247\330\264\333\214\331\207 \330\267\331\204\330\247\333\214\333\214 */\n"
"    border-radius: 8px;\n"
"    padding: 6px 12px;\n"
"    font-family: \"Black Ops One\";\n"
"    font-size: 20px;\n"
"    letter-spacing: 1px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #E9D6C0; /* \332\251\331\205\333\214 \330\261\331\210\330\264\331\206\342\200\214\330\252\330\261"
                        " \331\210 \332\257\330\261\331\205\342\200\214\330\252\330\261 \331\207\331\206\332\257\330\247\331\205 \331\207\330\247\331\210\330\261 */\n"
"    border: 2px solid #DABF85;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #BBA89A; /* \330\255\330\247\331\204\330\252 \331\201\330\264\330\247\330\261 \330\257\330\247\330\257\331\207 \330\264\330\257\331\207\330\214 \332\251\331\205\333\214 \330\252\333\214\330\261\331\207\342\200\214\330\252\330\261 \330\250\330\261\330\247\333\214 \330\255\330\263 \331\210\330\262\331\206 */\n"
"    border: 2px solid #A68756;\n"
"    color: #2C2A28;\n"
"}\n"
""));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(130, 280, 121, 51));
        pushButton->setStyleSheet(QString::fromUtf8("\n"
"\n"
"QPushButton {\n"
"    background-color: #D6C2B2; /* \331\276\330\263\342\200\214\330\262\331\205\333\214\331\206\331\207\342\200\214\330\247\333\214 \331\205\331\204\330\247\333\214\331\205 \331\210 \330\261\331\210\330\264\331\206\330\214 \330\250\330\261\332\257\330\261\331\201\330\252\331\207 \330\247\330\262 \331\206\331\210\330\261 \330\242\331\201\330\252\330\247\330\250 \330\257\330\261 \331\205\331\207 */\n"
"    color: #3E3A39; /* \330\261\331\206\332\257 \331\205\330\252\331\206\330\214 \330\252\333\214\330\261\331\207 \331\210\331\204\333\214 \332\257\330\261\331\205 */\n"
"    border: 2px solid #C8A974; /* \330\255\330\247\330\264\333\214\331\207 \330\267\331\204\330\247\333\214\333\214 */\n"
"    border-radius: 8px;\n"
"    padding: 6px 12px;\n"
"    font-family: \"Black Ops One\";\n"
"    font-size: 20px;\n"
"    letter-spacing: 1px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #E9D6C0; /* \332\251\331\205\333\214 \330\261\331\210\330\264\331\206\342\200\214\330\252\330\261"
                        " \331\210 \332\257\330\261\331\205\342\200\214\330\252\330\261 \331\207\331\206\332\257\330\247\331\205 \331\207\330\247\331\210\330\261 */\n"
"    border: 2px solid #DABF85;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #BBA89A; /* \330\255\330\247\331\204\330\252 \331\201\330\264\330\247\330\261 \330\257\330\247\330\257\331\207 \330\264\330\257\331\207\330\214 \332\251\331\205\333\214 \330\252\333\214\330\261\331\207\342\200\214\330\252\330\261 \330\250\330\261\330\247\333\214 \330\255\330\263 \331\210\330\262\331\206 */\n"
"    border: 2px solid #A68756;\n"
"    color: #2C2A28;\n"
"}\n"
""));
        startPage->setCentralWidget(centralwidget);
        menubar = new QMenuBar(startPage);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 760, 25));
        startPage->setMenuBar(menubar);
        statusbar = new QStatusBar(startPage);
        statusbar->setObjectName("statusbar");
        startPage->setStatusBar(statusbar);

        retranslateUi(startPage);

        QMetaObject::connectSlotsByName(startPage);
    } // setupUi

    void retranslateUi(QMainWindow *startPage)
    {
        startPage->setWindowTitle(QCoreApplication::translate("startPage", "MainWindow", nullptr));
        groupBox->setTitle(QCoreApplication::translate("startPage", "Game of Samurai", nullptr));
        Gallery->setText(QCoreApplication::translate("startPage", "Gallery", nullptr));
        start->setText(QCoreApplication::translate("startPage", "Start a Sync PVP Match", nullptr));
        exit->setText(QCoreApplication::translate("startPage", "Exit", nullptr));
        label->setText(QCoreApplication::translate("startPage", "                Player 1:", nullptr));
        ok->setText(QCoreApplication::translate("startPage", "OK", nullptr));
        pushButton->setText(QCoreApplication::translate("startPage", "Start", nullptr));
    } // retranslateUi

};

namespace Ui {
    class startPage: public Ui_startPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STARTPAGE_H

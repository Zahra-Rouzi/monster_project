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
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainPage
{
public:
    QWidget *centralwidget;
    QLabel *label_3;
    QLabel *label_8;
    QLabel *label_7;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label_9;
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton_3;
    QListWidget *listWidget_3;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QPushButton *pushButton_8;
    QPushButton *pushButton_7;
    QPushButton *pushButton_14;
    QPushButton *pushButton_9;
    QLabel *label_20;
    QLabel *label_16;
    QPushButton *pushButton_12;
    QLabel *label_17;
    QPushButton *pushButton_10;
    QPushButton *pushButton_11;
    QLabel *label_19;
    QLabel *label_18;
    QPushButton *pushButton_13;
    QLabel *label_15;
    QLabel *label_13;
    QLabel *label_14;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainPage)
    {
        if (MainPage->objectName().isEmpty())
            MainPage->setObjectName("MainPage");
        MainPage->resize(1388, 1074);
        MainPage->setStyleSheet(QString::fromUtf8("/*background-color: white;\n"
"*/QMainWindow{\n"
"	background-image: url(:/new/prefix15/bg9.jpg);\n"
"}"));
        centralwidget = new QWidget(MainPage);
        centralwidget->setObjectName("centralwidget");
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(60, 530, 151, 141));
        label_3->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix8/a3.png);\n"
"background-color: transparent;"));
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(80, 290, 101, 171));
        label_8->setStyleSheet(QString::fromUtf8("\n"
"  background-color: transparent;\n"
"    border: 2px solid #D8B47D;\n"
"    border-radius: 10px;\n"
"    margin-top: 20px;\n"
"    padding: 10px;\n"
"    color: #3E3A39;"));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(70, 30, 101, 171));
        label_7->setStyleSheet(QString::fromUtf8("\n"
"  background-color: transparent;\n"
"    border: 2px solid #D8B47D;\n"
"    border-radius: 10px;\n"
"    margin-top: 20px;\n"
"    padding: 10px;\n"
"    color: #3E3A39;"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(80, 170, 75, 24));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(90, 430, 75, 24));
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(80, 520, 101, 171));
        label_9->setStyleSheet(QString::fromUtf8("\n"
"  background-color: transparent;\n"
"    border: 2px solid #D8B47D;\n"
"    border-radius: 10px;\n"
"    margin-top: 20px;\n"
"    padding: 10px;\n"
"    color: #3E3A39;"));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(50, 60, 141, 121));
        label->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix6/a1.png);\n"
"background-color: transparent;"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(40, 310, 181, 121));
        label_2->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix7/a2.png);\n"
"background-color: transparent;"));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(90, 660, 75, 24));
        listWidget_3 = new QListWidget(centralwidget);
        listWidget_3->setObjectName("listWidget_3");
        listWidget_3->setGeometry(QRect(10, 0, 231, 741));
        listWidget_3->setStyleSheet(QString::fromUtf8("\n"
"  background-color: rgba(255, 239, 200, 0.5);\n"
"    border: 2px solid #D8B47D;\n"
"    border-radius: 10px;\n"
"    margin-top: 20px;\n"
"    padding: 10px;\n"
"    color: #3E3A39;\n"
"   \n"
"\n"
""));
        scrollArea = new QScrollArea(centralwidget);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(1130, 60, 231, 621));
        scrollArea->setStyleSheet(QString::fromUtf8("QScrollArea {\n"
"   background-color: rgba(170, 170, 127, 0.4);\n"
"    border: 4px solid rgb(187, 128, 68);\n"
"    border-radius: 12px;\n"
"    padding: 6px;\n"
"}\n"
"\n"
"QScrollBar:vertical {\n"
"    background: rgb(163, 213, 252);\n"
"    width: 14px;\n"
"    margin: 2px;\n"
"    border-radius: 5px;\n"
"}\n"
"QScrollBar::handle:vertical {\n"
"    background: rgb(163, 213, 252);\n"
"    border-radius: 5px;\n"
"}\n"
"/*QScrollBar::add-line:vertical, QScrollBar::sub-line:vertical {\n"
"    background: none;\n"
"}\n"
"\n"
"QScrollBar:horizontal {\n"
"    background: #f9c5d1;\n"
"    height: 10px;\n"
"    margin: 2px;\n"
"    border-radius: 5px;\n"
"}\n"
"QScrollBar::handle:horizontal {\n"
"    background: #f48fb1;\n"
"    border-radius: 5px;\n"
"}\n"
"QScrollBar::add-line:horizontal, QScrollBar::sub-line:horizontal {\n"
"    background: none;\n"
"}*/"));
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAsNeeded);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, -270, 197, 2350));
        scrollAreaWidgetContents->setMinimumSize(QSize(0, 2350));
        pushButton_8 = new QPushButton(scrollAreaWidgetContents);
        pushButton_8->setObjectName("pushButton_8");
        pushButton_8->setGeometry(QRect(11, 515, 171, 31));
        QSizePolicy sizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_8->sizePolicy().hasHeightForWidth());
        pushButton_8->setSizePolicy(sizePolicy);
        pushButton_8->setMinimumSize(QSize(0, 31));
        pushButton_8->setStyleSheet(QString::fromUtf8("QPushButton{\n"
" background-color: rgba(255, 255, 255, 0.3);\n"
"border: 2px solid rgb(187, 128, 68);\n"
"font: 9pt \"Black Ops One\";\n"
"}\n"
"QPushButton:hover{\n"
" background-color: rgba(255, 255, 255, 0.5);\n"
"}\n"
"QPushButton:pressed{\n"
" background-color: rgba(255, 255, 255, 0.7);\n"
"}"));
        pushButton_7 = new QPushButton(scrollAreaWidgetContents);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setGeometry(QRect(10, 230, 171, 31));
        sizePolicy.setHeightForWidth(pushButton_7->sizePolicy().hasHeightForWidth());
        pushButton_7->setSizePolicy(sizePolicy);
        pushButton_7->setMinimumSize(QSize(0, 31));
        pushButton_7->setStyleSheet(QString::fromUtf8("QPushButton{\n"
" background-color: rgba(255, 255, 255, 0.3);\n"
"border: 2px solid rgb(187, 128, 68);\n"
"font: 9pt \"Black Ops One\";\n"
"}\n"
"QPushButton:hover{\n"
" background-color: rgba(255, 255, 255, 0.5);\n"
"}\n"
"QPushButton:pressed{\n"
" background-color: rgba(255, 255, 255, 0.7);\n"
"}"));
        pushButton_14 = new QPushButton(scrollAreaWidgetContents);
        pushButton_14->setObjectName("pushButton_14");
        pushButton_14->setGeometry(QRect(11, 2297, 171, 31));
        sizePolicy.setHeightForWidth(pushButton_14->sizePolicy().hasHeightForWidth());
        pushButton_14->setSizePolicy(sizePolicy);
        pushButton_14->setMinimumSize(QSize(0, 31));
        pushButton_14->setStyleSheet(QString::fromUtf8("QPushButton{\n"
" background-color: rgba(255, 255, 255, 0.3);\n"
"border: 2px solid rgb(187, 128, 68);\n"
"font: 9pt \"Black Ops One\";\n"
"}\n"
"QPushButton:hover{\n"
" background-color: rgba(255, 255, 255, 0.5);\n"
"}\n"
"QPushButton:pressed{\n"
" background-color: rgba(255, 255, 255, 0.7);\n"
"}"));
        pushButton_9 = new QPushButton(scrollAreaWidgetContents);
        pushButton_9->setObjectName("pushButton_9");
        pushButton_9->setGeometry(QRect(11, 812, 171, 31));
        sizePolicy.setHeightForWidth(pushButton_9->sizePolicy().hasHeightForWidth());
        pushButton_9->setSizePolicy(sizePolicy);
        pushButton_9->setMinimumSize(QSize(0, 31));
        pushButton_9->setStyleSheet(QString::fromUtf8("QPushButton{\n"
" background-color: rgba(255, 255, 255, 0.3);\n"
"border: 2px solid rgb(187, 128, 68);\n"
"font: 9pt \"Black Ops One\";\n"
"}\n"
"QPushButton:hover{\n"
" background-color: rgba(255, 255, 255, 0.5);\n"
"}\n"
"QPushButton:pressed{\n"
" background-color: rgba(255, 255, 255, 0.7);\n"
"}"));
        label_20 = new QLabel(scrollAreaWidgetContents);
        label_20->setObjectName("label_20");
        label_20->setGeometry(QRect(11, 1486, 171, 211));
        label_20->setMinimumSize(QSize(0, 0));
        label_20->setMaximumSize(QSize(171, 211));
        label_20->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix16/agents/Screenshot_2025-04-19-18-12-23-074_com.android.chrome-edit (11).png);\n"
" background-color: rgba(255, 255, 255, 0.3);\n"
"border: 2px solid rgb(187, 128, 68);"));
        label_16 = new QLabel(scrollAreaWidgetContents);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(11, 892, 171, 211));
        label_16->setMinimumSize(QSize(0, 0));
        label_16->setMaximumSize(QSize(171, 211));
        label_16->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix16/agents/Screenshot_2025-04-19-18-12-23-074_com.android.chrome-edit (7).png);\n"
" background-color: rgba(255, 255, 255, 0.3);\n"
"border: 2px solid rgb(187, 128, 68);"));
        pushButton_12 = new QPushButton(scrollAreaWidgetContents);
        pushButton_12->setObjectName("pushButton_12");
        pushButton_12->setGeometry(QRect(11, 1703, 171, 31));
        sizePolicy.setHeightForWidth(pushButton_12->sizePolicy().hasHeightForWidth());
        pushButton_12->setSizePolicy(sizePolicy);
        pushButton_12->setMinimumSize(QSize(0, 31));
        pushButton_12->setStyleSheet(QString::fromUtf8("QPushButton{\n"
" background-color: rgba(255, 255, 255, 0.3);\n"
"border: 2px solid rgb(187, 128, 68);\n"
"font: 9pt \"Black Ops One\";\n"
"}\n"
"QPushButton:hover{\n"
" background-color: rgba(255, 255, 255, 0.5);\n"
"}\n"
"QPushButton:pressed{\n"
" background-color: rgba(255, 255, 255, 0.7);\n"
"}"));
        label_17 = new QLabel(scrollAreaWidgetContents);
        label_17->setObjectName("label_17");
        label_17->setGeometry(QRect(11, 1189, 171, 211));
        label_17->setMinimumSize(QSize(0, 0));
        label_17->setMaximumSize(QSize(171, 211));
        label_17->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix16/agents/Screenshot_2025-04-19-18-12-23-074_com.android.chrome-edit (8).png);\n"
" background-color: rgba(255, 255, 255, 0.3);\n"
"border: 2px solid rgb(187, 128, 68);\n"
""));
        pushButton_10 = new QPushButton(scrollAreaWidgetContents);
        pushButton_10->setObjectName("pushButton_10");
        pushButton_10->setGeometry(QRect(11, 1109, 171, 31));
        sizePolicy.setHeightForWidth(pushButton_10->sizePolicy().hasHeightForWidth());
        pushButton_10->setSizePolicy(sizePolicy);
        pushButton_10->setMinimumSize(QSize(0, 31));
        pushButton_10->setStyleSheet(QString::fromUtf8("QPushButton{\n"
" background-color: rgba(255, 255, 255, 0.3);\n"
"border: 2px solid rgb(187, 128, 68);\n"
"font: 9pt \"Black Ops One\";\n"
"}\n"
"QPushButton:hover{\n"
" background-color: rgba(255, 255, 255, 0.5);\n"
"}\n"
"QPushButton:pressed{\n"
" background-color: rgba(255, 255, 255, 0.7);\n"
"}"));
        pushButton_11 = new QPushButton(scrollAreaWidgetContents);
        pushButton_11->setObjectName("pushButton_11");
        pushButton_11->setGeometry(QRect(11, 1406, 171, 31));
        sizePolicy.setHeightForWidth(pushButton_11->sizePolicy().hasHeightForWidth());
        pushButton_11->setSizePolicy(sizePolicy);
        pushButton_11->setMinimumSize(QSize(0, 31));
        pushButton_11->setStyleSheet(QString::fromUtf8("QPushButton{\n"
" background-color: rgba(255, 255, 255, 0.3);\n"
"border: 2px solid rgb(187, 128, 68);\n"
"font: 9pt \"Black Ops One\";\n"
"}\n"
"QPushButton:hover{\n"
" background-color: rgba(255, 255, 255, 0.5);\n"
"}\n"
"QPushButton:pressed{\n"
" background-color: rgba(255, 255, 255, 0.7);\n"
"}"));
        label_19 = new QLabel(scrollAreaWidgetContents);
        label_19->setObjectName("label_19");
        label_19->setGeometry(QRect(11, 2080, 171, 211));
        label_19->setMinimumSize(QSize(171, 211));
        label_19->setMaximumSize(QSize(171, 211));
        label_19->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix16/agents/Screenshot_2025-04-19-18-12-23-074_com.android.chrome-edit (10).png);\n"
" background-color: rgba(255, 255, 255, 0.3);\n"
"border: 2px solid rgb(187, 128, 68);\n"
""));
        label_18 = new QLabel(scrollAreaWidgetContents);
        label_18->setObjectName("label_18");
        label_18->setGeometry(QRect(11, 1783, 171, 211));
        label_18->setMinimumSize(QSize(0, 0));
        label_18->setMaximumSize(QSize(171, 211));
        label_18->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix16/agents/Screenshot_2025-04-19-18-12-23-074_com.android.chrome-edit (9).png);\n"
"background-color: rgba(255, 255, 255, 0.3);\n"
"border: 2px solid rgb(187, 128, 68);"));
        pushButton_13 = new QPushButton(scrollAreaWidgetContents);
        pushButton_13->setObjectName("pushButton_13");
        pushButton_13->setGeometry(QRect(11, 2000, 171, 31));
        sizePolicy.setHeightForWidth(pushButton_13->sizePolicy().hasHeightForWidth());
        pushButton_13->setSizePolicy(sizePolicy);
        pushButton_13->setMinimumSize(QSize(0, 31));
        pushButton_13->setStyleSheet(QString::fromUtf8("QPushButton{\n"
" background-color: rgba(255, 255, 255, 0.3);\n"
"border: 2px solid rgb(187, 128, 68);\n"
"font: 9pt \"Black Ops One\";\n"
"}\n"
"QPushButton:hover{\n"
" background-color: rgba(255, 255, 255, 0.5);\n"
"}\n"
"QPushButton:pressed{\n"
" background-color: rgba(255, 255, 255, 0.7);\n"
"}"));
        label_15 = new QLabel(scrollAreaWidgetContents);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(10, 10, 171, 211));
        label_15->setMinimumSize(QSize(0, 0));
        label_15->setMaximumSize(QSize(171, 211));
        label_15->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix16/agents/Screenshot_2025-04-19-18-12-23-074_com.android.chrome-edit (11).png);\n"
" background-color: rgba(255, 255, 255, 0.3);\n"
"border: 2px solid rgb(187, 128, 68);"));
        label_13 = new QLabel(scrollAreaWidgetContents);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(10, 290, 171, 211));
        label_13->setMinimumSize(QSize(0, 0));
        label_13->setMaximumSize(QSize(171, 211));
        label_13->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix16/agents/Screenshot_2025-04-19-18-12-23-074_com.android.chrome-edit (4).png);\n"
" background-color: rgba(255, 255, 255, 0.3);\n"
"border: 2px solid rgb(187, 128, 68);"));
        label_14 = new QLabel(scrollAreaWidgetContents);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(10, 590, 171, 211));
        label_14->setMinimumSize(QSize(0, 0));
        label_14->setMaximumSize(QSize(171, 211));
        label_14->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix16/agents/Screenshot_2025-04-19-18-12-23-074_com.android.chrome-edit (10).png);\n"
" background-color: rgba(255, 255, 255, 0.3);\n"
"border: 2px solid rgb(187, 128, 68);"));
        scrollArea->setWidget(scrollAreaWidgetContents);
        MainPage->setCentralWidget(centralwidget);
        listWidget_3->raise();
        pushButton_3->raise();
        pushButton_2->raise();
        pushButton->raise();
        label->raise();
        label_2->raise();
        label_3->raise();
        label_9->raise();
        label_8->raise();
        label_7->raise();
        scrollArea->raise();
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
        label_3->setText(QString());
        label_8->setText(QString());
        label_7->setText(QString());
        pushButton->setText(QCoreApplication::translate("MainPage", "PushButton", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainPage", "PushButton", nullptr));
        label_9->setText(QString());
        label->setText(QString());
        label_2->setText(QString());
        pushButton_3->setText(QCoreApplication::translate("MainPage", "PushButton", nullptr));
        pushButton_8->setText(QCoreApplication::translate("MainPage", "PushButton", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainPage", "PushButton", nullptr));
        pushButton_14->setText(QCoreApplication::translate("MainPage", "PushButton", nullptr));
        pushButton_9->setText(QCoreApplication::translate("MainPage", "PushButton", nullptr));
        label_20->setText(QString());
        label_16->setText(QString());
        pushButton_12->setText(QCoreApplication::translate("MainPage", "PushButton", nullptr));
        label_17->setText(QString());
        pushButton_10->setText(QCoreApplication::translate("MainPage", "PushButton", nullptr));
        pushButton_11->setText(QCoreApplication::translate("MainPage", "PushButton", nullptr));
        label_19->setText(QString());
        label_18->setText(QString());
        pushButton_13->setText(QCoreApplication::translate("MainPage", "PushButton", nullptr));
        label_15->setText(QString());
        label_13->setText(QString());
        label_14->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainPage: public Ui_MainPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINPAGE_H

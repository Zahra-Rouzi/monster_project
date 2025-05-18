/********************************************************************************
** Form generated from reading UI file 'gallery.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GALLERY_H
#define UI_GALLERY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Gallery
{
public:
    QWidget *centralwidget;
    QWidget *widget;
    QGroupBox *groupBox;
    QLabel *label_2;
    QLabel *label;
    QLabel *label_3;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Gallery)
    {
        if (Gallery->objectName().isEmpty())
            Gallery->setObjectName("Gallery");
        Gallery->resize(1143, 825);
        Gallery->setStyleSheet(QString::fromUtf8("QMainWindow{\n"
"	background-image: url(:/new/prefix13/Game/galleri_bg.jpg);\n"
"	background-color: qlineargradient(spread:reflect, x1:0.493052, y1:0.505, x2:1, y2:0, stop:0.352113 rgba(191, 124, 158, 255), stop:0.553991 rgba(195, 111, 141, 255), stop:1 rgba(255, 255, 255, 255));\n"
"	\n"
"	\n"
"	background-color: rgb(182, 113, 131);\n"
"	background-size: cover;\n"
"	baclground-repeat: no repeat;\n"
"}"));
        centralwidget = new QWidget(Gallery);
        centralwidget->setObjectName("centralwidget");
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(410, 480, 120, 80));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(320, 80, 751, 571));
        groupBox->setStyleSheet(QString::fromUtf8("    border: 2px solid #D8B47D; \n"
"    border-radius: 10px;\n"
"    margin-top: 20px;\n"
"    padding: 10px;\n"
"background-color: rgb(190, 98, 99);\n"
"background-color: rgb(190, 142, 146);\n"
"background-color: transparent;\n"
"\n"
"font:20px;\n"
"color: rgb(206, 171, 120);\n"
"color: rgb(216, 186, 125);"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(400, 40, 211, 221));
        label_2->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix7/a2.png);\n"
"background-color: rgb(214, 194, 178);"));
        label = new QLabel(groupBox);
        label->setObjectName("label");
        label->setGeometry(QRect(70, 40, 221, 221));
        label->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix6/a1.png);\n"
"background-color: rgb(214, 194, 178);\n"
"width:50%;"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(250, 280, 221, 211));
        label_3->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix8/a3.png);\n"
"background-color: rgb(214, 194, 178);"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(630, 680, 121, 41));
        pushButton->setStyleSheet(QString::fromUtf8("  \n"
"\n"
"\n"
"QPushButton {\n"
"    background-color: #6a415e;\n"
"    color: #fcefe9;\n"
"    border: 2px solid #e8a6a1;\n"
"    border-radius: 0px;\n"
"    padding: 6px 12px;\n"
"	font-family: 'Black Ops One' ;\n"
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
"}"));
        Gallery->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Gallery);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1143, 22));
        Gallery->setMenuBar(menubar);
        statusbar = new QStatusBar(Gallery);
        statusbar->setObjectName("statusbar");
        Gallery->setStatusBar(statusbar);

        retranslateUi(Gallery);

        QMetaObject::connectSlotsByName(Gallery);
    } // setupUi

    void retranslateUi(QMainWindow *Gallery)
    {
        Gallery->setWindowTitle(QCoreApplication::translate("Gallery", "MainWindow", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Gallery", "Gallary", nullptr));
        label_2->setText(QString());
        label->setText(QString());
        label_3->setText(QString());
        pushButton->setText(QCoreApplication::translate("Gallery", "back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Gallery: public Ui_Gallery {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GALLERY_H

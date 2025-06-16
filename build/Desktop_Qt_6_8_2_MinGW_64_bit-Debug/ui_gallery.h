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
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Gallery
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox_2;
    QGroupBox *groupBox_3;
    QLabel *label_13;
    QLabel *label_12;
    QGroupBox *groupBox_5;
    QLabel *label_21;
    QLabel *label_10;
    QGroupBox *groupBox_4;
    QLabel *label_22;
    QLabel *label_9;
    QGroupBox *groupBox_27;
    QLabel *label_14;
    QLabel *label_15;
    QGroupBox *groupBox_6;
    QGroupBox *groupBox_7;
    QLabel *label_23;
    QLabel *label_20;
    QGroupBox *groupBox_8;
    QLabel *label_24;
    QLabel *label_19;
    QGroupBox *groupBox_9;
    QLabel *label_25;
    QLabel *label_26;
    QGroupBox *groupBox_28;
    QLabel *label_16;
    QLabel *label_17;
    QGroupBox *groupBox_10;
    QGroupBox *groupBox_11;
    QLabel *label_27;
    QLabel *label_28;
    QGroupBox *groupBox_12;
    QLabel *label_29;
    QLabel *label_30;
    QGroupBox *groupBox_13;
    QLabel *label_31;
    QLabel *label_32;
    QGroupBox *groupBox_29;
    QLabel *label_53;
    QLabel *label_51;
    QGroupBox *groupBox_14;
    QGroupBox *groupBox_15;
    QLabel *label_33;
    QLabel *label_34;
    QGroupBox *groupBox_16;
    QLabel *label_35;
    QLabel *label_36;
    QGroupBox *groupBox_17;
    QLabel *label_37;
    QLabel *label_38;
    QGroupBox *groupBox_21;
    QLabel *label_43;
    QLabel *label_44;
    QGroupBox *groupBox_18;
    QGroupBox *groupBox_19;
    QLabel *label_39;
    QLabel *label_40;
    QGroupBox *groupBox_20;
    QLabel *label_41;
    QLabel *label_42;
    QGroupBox *groupBox_25;
    QLabel *label_49;
    QLabel *label_50;
    QGroupBox *groupBox_24;
    QLabel *label_47;
    QLabel *label_56;
    QGroupBox *groupBox_22;
    QGroupBox *groupBox_23;
    QLabel *label_45;
    QLabel *label_55;
    QGroupBox *groupBox_34;
    QLabel *label_63;
    QLabel *label_52;
    QGroupBox *groupBox_35;
    QLabel *label_66;
    QLabel *label_54;
    QLabel *label;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Gallery)
    {
        if (Gallery->objectName().isEmpty())
            Gallery->setObjectName("Gallery");
        Gallery->resize(1597, 1005);
        QFont font;
        font.setBold(true);
        Gallery->setFont(font);
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
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(110, 90, 1100, 921));
        groupBox->setStyleSheet(QString::fromUtf8("    border: 2px solid #D8B47D; \n"
"    border-radius: 10px;\n"
"    margin-top: 20px;\n"
"    padding: 10px;\n"
"background-color: rgb(190, 98, 99);\n"
"background-color: rgb(190, 142, 146);\n"
"background-color: transparent;\n"
"color: #FFD700   ;\n"
"    font-family: \"Black Ops One\";\n"
"    font-size: 20px;\n"
"    letter-spacing: 1px;"));
        scrollArea = new QScrollArea(groupBox);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(90, 40, 941, 811));
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
"\n"
"    color: #3E3A39; /* \330\261\331\206\332\257 \331\205\330\252\331\206 \332\257\330\261\331\205 \331\210 \330\252\333\214\330\261\331\207 */\n"
"    font-family: \"Black Ops One\";\n"
"    font-size: 20px;\n"
"    letter-spacing: 1px;\n"
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
        scrollArea->setWidgetResizable(false);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 907, 2000));
        scrollAreaWidgetContents->setMinimumSize(QSize(0, 1000));
        layoutWidget = new QWidget(scrollAreaWidgetContents);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(20, 20, 873, 1863));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        groupBox_2 = new QGroupBox(layoutWidget);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setMinimumSize(QSize(871, 301));
        groupBox_3 = new QGroupBox(groupBox_2);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setGeometry(QRect(430, 10, 191, 281));
        label_13 = new QLabel(groupBox_3);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(10, 10, 174, 194));
        label_13->setMinimumSize(QSize(174, 194));
        label_13->setMaximumSize(QSize(174, 194));
        label_13->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/newagents/grounded15.png);\n"
" background-color: rgba(255, 255, 255, 0.3);\n"
"border: 2px solid rgb(187, 128, 68);\n"
"min-width: 150px; max-width: 150px; min-height: 150px; max-height: 150px;\n"
""));
        label_12 = new QLabel(groupBox_3);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(10, 190, 171, 81));
        label_12->setStyleSheet(QString::fromUtf8("    color:#F0EAD6; \n"
" font-size: 14px;\n"
"font-weight: bold;\n"
"qproperty-alignment: 'AlignCenter';\n"
"letter-spacing:3px;\n"
"   "));
        label_12->setTextFormat(Qt::TextFormat::AutoText);
        groupBox_5 = new QGroupBox(groupBox_2);
        groupBox_5->setObjectName("groupBox_5");
        groupBox_5->setGeometry(QRect(230, 10, 191, 281));
        label_21 = new QLabel(groupBox_5);
        label_21->setObjectName("label_21");
        label_21->setGeometry(QRect(10, 10, 174, 194));
        label_21->setMinimumSize(QSize(174, 194));
        label_21->setMaximumSize(QSize(174, 194));
        label_21->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/newagents/waterwalking5.png);\n"
" background-color: rgba(255, 255, 255, 0.3);\n"
"border: 2px solid rgb(187, 128, 68);\n"
"min-width: 150px; max-width: 150px; min-height: 150px; max-height: 150px;\n"
""));
        label_10 = new QLabel(groupBox_5);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(10, 190, 171, 81));
        label_10->setStyleSheet(QString::fromUtf8("    color:#F0EAD6; \n"
" font-size: 14px;\n"
"font-weight: bold;\n"
"qproperty-alignment: 'AlignCenter';\n"
"letter-spacing:3px;\n"
"   "));
        label_10->setTextFormat(Qt::TextFormat::AutoText);
        groupBox_4 = new QGroupBox(groupBox_2);
        groupBox_4->setObjectName("groupBox_4");
        groupBox_4->setGeometry(QRect(20, 10, 191, 281));
        groupBox_4->setStyleSheet(QString::fromUtf8(" font-size: 30px;\n"
""));
        label_22 = new QLabel(groupBox_4);
        label_22->setObjectName("label_22");
        label_22->setGeometry(QRect(10, 10, 174, 194));
        label_22->setMinimumSize(QSize(174, 194));
        label_22->setMaximumSize(QSize(174, 194));
        label_22->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/newagents/grounded1.png);\n"
" background-color: rgba(255, 255, 255, 0.3);\n"
"border: 2px solid rgb(187, 128, 68);\n"
"min-width: 150px; max-width: 150px; min-height: 150px; max-height: 150px;\n"
""));
        label_9 = new QLabel(groupBox_4);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(10, 190, 171, 81));
        label_9->setStyleSheet(QString::fromUtf8("    color:#F0EAD6; \n"
" font-size: 14px;\n"
"font-weight: bold;\n"
"qproperty-alignment: 'AlignCenter';\n"
"letter-spacing:3px;\n"
"   "));
        label_9->setTextFormat(Qt::TextFormat::AutoText);
        groupBox_27 = new QGroupBox(groupBox_2);
        groupBox_27->setObjectName("groupBox_27");
        groupBox_27->setGeometry(QRect(650, 10, 191, 281));
        label_14 = new QLabel(groupBox_27);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(10, 10, 174, 194));
        label_14->setMinimumSize(QSize(174, 194));
        label_14->setMaximumSize(QSize(174, 194));
        label_14->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/newagents/flying1.png);\n"
" background-color: rgba(255, 255, 255, 0.3);\n"
"border: 2px solid rgb(187, 128, 68);\n"
"min-width: 150px; max-width: 150px; min-height: 150px; max-height: 150px;\n"
""));
        label_15 = new QLabel(groupBox_27);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(10, 190, 171, 81));
        label_15->setStyleSheet(QString::fromUtf8("    color:#F0EAD6; \n"
" font-size: 14px;\n"
"font-weight: bold;\n"
"qproperty-alignment: 'AlignCenter';\n"
"letter-spacing:3px;\n"
"   "));
        label_15->setTextFormat(Qt::TextFormat::AutoText);

        verticalLayout->addWidget(groupBox_2);

        groupBox_6 = new QGroupBox(layoutWidget);
        groupBox_6->setObjectName("groupBox_6");
        groupBox_6->setMinimumSize(QSize(871, 301));
        groupBox_7 = new QGroupBox(groupBox_6);
        groupBox_7->setObjectName("groupBox_7");
        groupBox_7->setGeometry(QRect(430, 10, 191, 281));
        label_23 = new QLabel(groupBox_7);
        label_23->setObjectName("label_23");
        label_23->setGeometry(QRect(10, 10, 174, 194));
        label_23->setMinimumSize(QSize(174, 194));
        label_23->setMaximumSize(QSize(174, 194));
        label_23->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/newagents/grounded10.png);\n"
" background-color: rgba(255, 255, 255, 0.3);\n"
"border: 2px solid rgb(187, 128, 68);\n"
"min-width: 150px; max-width: 150px; min-height: 150px; max-height: 150px;\n"
""));
        label_20 = new QLabel(groupBox_7);
        label_20->setObjectName("label_20");
        label_20->setGeometry(QRect(10, 190, 171, 81));
        label_20->setStyleSheet(QString::fromUtf8("    color:#F0EAD6; \n"
" font-size: 14px;\n"
"font-weight: bold;\n"
"qproperty-alignment: 'AlignCenter';\n"
"letter-spacing:3px;\n"
"   "));
        label_20->setTextFormat(Qt::TextFormat::AutoText);
        groupBox_8 = new QGroupBox(groupBox_6);
        groupBox_8->setObjectName("groupBox_8");
        groupBox_8->setGeometry(QRect(230, 10, 191, 281));
        label_24 = new QLabel(groupBox_8);
        label_24->setObjectName("label_24");
        label_24->setGeometry(QRect(10, 10, 174, 194));
        label_24->setMinimumSize(QSize(174, 194));
        label_24->setMaximumSize(QSize(174, 194));
        label_24->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/newagents/grounded2.png);\n"
" background-color: rgba(255, 255, 255, 0.3);\n"
"border: 2px solid rgb(187, 128, 68);\n"
"min-width: 150px; max-width: 150px; min-height: 150px; max-height: 150px;\n"
""));
        label_19 = new QLabel(groupBox_8);
        label_19->setObjectName("label_19");
        label_19->setGeometry(QRect(10, 190, 171, 81));
        label_19->setStyleSheet(QString::fromUtf8("    color:#F0EAD6; \n"
" font-size: 14px;\n"
"font-weight: bold;\n"
"qproperty-alignment: 'AlignCenter';\n"
"letter-spacing:3px;\n"
"   "));
        label_19->setTextFormat(Qt::TextFormat::AutoText);
        groupBox_9 = new QGroupBox(groupBox_6);
        groupBox_9->setObjectName("groupBox_9");
        groupBox_9->setGeometry(QRect(20, 10, 191, 281));
        label_25 = new QLabel(groupBox_9);
        label_25->setObjectName("label_25");
        label_25->setGeometry(QRect(10, 10, 174, 194));
        label_25->setMinimumSize(QSize(174, 194));
        label_25->setMaximumSize(QSize(174, 194));
        label_25->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/newagents/waterwalking6.png);\n"
" background-color: rgba(255, 255, 255, 0.3);\n"
"border: 2px solid rgb(187, 128, 68);\n"
"min-width: 150px; max-width: 150px; min-height: 150px; max-height: 150px;\n"
""));
        label_26 = new QLabel(groupBox_9);
        label_26->setObjectName("label_26");
        label_26->setGeometry(QRect(10, 190, 171, 81));
        label_26->setStyleSheet(QString::fromUtf8("    color:#F0EAD6; \n"
" font-size: 14px;\n"
"font-weight: bold;\n"
"qproperty-alignment: 'AlignCenter';\n"
"letter-spacing:3px;\n"
"   "));
        label_26->setTextFormat(Qt::TextFormat::AutoText);
        groupBox_28 = new QGroupBox(groupBox_6);
        groupBox_28->setObjectName("groupBox_28");
        groupBox_28->setGeometry(QRect(640, 10, 191, 281));
        label_16 = new QLabel(groupBox_28);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(10, 10, 174, 194));
        label_16->setMinimumSize(QSize(174, 194));
        label_16->setMaximumSize(QSize(174, 194));
        label_16->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/newagents/waterwalking3.png);\n"
" background-color: rgba(255, 255, 255, 0.3);\n"
"border: 2px solid rgb(187, 128, 68);\n"
"min-width: 150px; max-width: 150px; min-height: 150px; max-height: 150px;\n"
""));
        label_17 = new QLabel(groupBox_28);
        label_17->setObjectName("label_17");
        label_17->setGeometry(QRect(10, 190, 171, 81));
        label_17->setStyleSheet(QString::fromUtf8("    color:#F0EAD6; \n"
" font-size: 14px;\n"
"font-weight: bold;\n"
"qproperty-alignment: 'AlignCenter';\n"
"letter-spacing:3px;\n"
"   "));
        label_17->setTextFormat(Qt::TextFormat::AutoText);

        verticalLayout->addWidget(groupBox_6);

        groupBox_10 = new QGroupBox(layoutWidget);
        groupBox_10->setObjectName("groupBox_10");
        groupBox_10->setMinimumSize(QSize(871, 301));
        groupBox_11 = new QGroupBox(groupBox_10);
        groupBox_11->setObjectName("groupBox_11");
        groupBox_11->setGeometry(QRect(430, 10, 191, 281));
        label_27 = new QLabel(groupBox_11);
        label_27->setObjectName("label_27");
        label_27->setGeometry(QRect(10, 10, 174, 194));
        label_27->setMinimumSize(QSize(174, 194));
        label_27->setMaximumSize(QSize(174, 194));
        label_27->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/newagents/grounded7.png);\n"
" background-color: rgba(255, 255, 255, 0.3);\n"
"border: 2px solid rgb(187, 128, 68);\n"
"min-width: 150px; max-width: 150px; min-height: 150px; max-height: 150px;\n"
""));
        label_28 = new QLabel(groupBox_11);
        label_28->setObjectName("label_28");
        label_28->setGeometry(QRect(10, 190, 171, 81));
        label_28->setStyleSheet(QString::fromUtf8("    color:#F0EAD6; \n"
" font-size: 14px;\n"
"font-weight: bold;\n"
"qproperty-alignment: 'AlignCenter';\n"
"letter-spacing:3px;\n"
"   "));
        label_28->setTextFormat(Qt::TextFormat::AutoText);
        groupBox_12 = new QGroupBox(groupBox_10);
        groupBox_12->setObjectName("groupBox_12");
        groupBox_12->setGeometry(QRect(230, 10, 191, 281));
        label_29 = new QLabel(groupBox_12);
        label_29->setObjectName("label_29");
        label_29->setGeometry(QRect(10, 10, 174, 194));
        label_29->setMinimumSize(QSize(174, 194));
        label_29->setMaximumSize(QSize(174, 194));
        label_29->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/newagents/grounded5.png);\n"
" background-color: rgba(255, 255, 255, 0.3);\n"
"border: 2px solid rgb(187, 128, 68);\n"
"min-width: 150px; max-width: 150px; min-height: 150px; max-height: 150px;\n"
""));
        label_30 = new QLabel(groupBox_12);
        label_30->setObjectName("label_30");
        label_30->setGeometry(QRect(10, 190, 171, 81));
        label_30->setStyleSheet(QString::fromUtf8("    color:#F0EAD6; \n"
" font-size: 14px;\n"
"font-weight: bold;\n"
"qproperty-alignment: 'AlignCenter';\n"
"letter-spacing:3px;\n"
"   "));
        label_30->setTextFormat(Qt::TextFormat::AutoText);
        groupBox_13 = new QGroupBox(groupBox_10);
        groupBox_13->setObjectName("groupBox_13");
        groupBox_13->setGeometry(QRect(20, 10, 191, 281));
        label_31 = new QLabel(groupBox_13);
        label_31->setObjectName("label_31");
        label_31->setGeometry(QRect(10, 10, 174, 194));
        label_31->setMinimumSize(QSize(174, 194));
        label_31->setMaximumSize(QSize(174, 194));
        label_31->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/newagents/grounded9.png);\n"
" background-color: rgba(255, 255, 255, 0.3);\n"
"border: 2px solid rgb(187, 128, 68);\n"
"min-width: 150px; max-width: 150px; min-height: 150px; max-height: 150px;\n"
""));
        label_32 = new QLabel(groupBox_13);
        label_32->setObjectName("label_32");
        label_32->setGeometry(QRect(10, 190, 171, 81));
        label_32->setStyleSheet(QString::fromUtf8("    color:#F0EAD6; \n"
" font-size: 14px;\n"
"font-weight: bold;\n"
"qproperty-alignment: 'AlignCenter';\n"
"letter-spacing:3px;\n"
"   "));
        label_32->setTextFormat(Qt::TextFormat::AutoText);
        groupBox_29 = new QGroupBox(groupBox_10);
        groupBox_29->setObjectName("groupBox_29");
        groupBox_29->setGeometry(QRect(650, 10, 191, 281));
        label_53 = new QLabel(groupBox_29);
        label_53->setObjectName("label_53");
        label_53->setGeometry(QRect(10, 10, 174, 194));
        label_53->setMinimumSize(QSize(174, 194));
        label_53->setMaximumSize(QSize(174, 194));
        label_53->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/newagents/waterwalking1.png);\n"
" background-color: rgba(255, 255, 255, 0.3);\n"
"border: 2px solid rgb(187, 128, 68);\n"
"min-width: 150px; max-width: 150px; min-height: 150px; max-height: 150px;\n"
""));
        label_51 = new QLabel(groupBox_29);
        label_51->setObjectName("label_51");
        label_51->setGeometry(QRect(10, 190, 171, 81));
        label_51->setStyleSheet(QString::fromUtf8("    color:#F0EAD6; \n"
" font-size: 14px;\n"
"font-weight: bold;\n"
"qproperty-alignment: 'AlignCenter';\n"
"letter-spacing:3px;\n"
"   "));
        label_51->setTextFormat(Qt::TextFormat::AutoText);

        verticalLayout->addWidget(groupBox_10);

        groupBox_14 = new QGroupBox(layoutWidget);
        groupBox_14->setObjectName("groupBox_14");
        groupBox_14->setMinimumSize(QSize(871, 301));
        groupBox_15 = new QGroupBox(groupBox_14);
        groupBox_15->setObjectName("groupBox_15");
        groupBox_15->setGeometry(QRect(430, 10, 191, 281));
        label_33 = new QLabel(groupBox_15);
        label_33->setObjectName("label_33");
        label_33->setGeometry(QRect(10, 10, 174, 194));
        label_33->setMinimumSize(QSize(174, 194));
        label_33->setMaximumSize(QSize(174, 194));
        label_33->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/newagents/waterwalking7.png);\n"
" background-color: rgba(255, 255, 255, 0.3);\n"
"border: 2px solid rgb(187, 128, 68);\n"
"min-width: 150px; max-width: 150px; min-height: 150px; max-height: 150px;\n"
""));
        label_34 = new QLabel(groupBox_15);
        label_34->setObjectName("label_34");
        label_34->setGeometry(QRect(10, 190, 171, 81));
        label_34->setStyleSheet(QString::fromUtf8("    color:#F0EAD6; \n"
" font-size: 14px;\n"
"font-weight: bold;\n"
"qproperty-alignment: 'AlignCenter';\n"
"letter-spacing:3px;\n"
"   "));
        label_34->setTextFormat(Qt::TextFormat::AutoText);
        groupBox_16 = new QGroupBox(groupBox_14);
        groupBox_16->setObjectName("groupBox_16");
        groupBox_16->setGeometry(QRect(230, 10, 191, 281));
        label_35 = new QLabel(groupBox_16);
        label_35->setObjectName("label_35");
        label_35->setGeometry(QRect(10, 10, 174, 194));
        label_35->setMinimumSize(QSize(174, 194));
        label_35->setMaximumSize(QSize(174, 194));
        label_35->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/newagents/grounded14.png);\n"
" background-color: rgba(255, 255, 255, 0.3);\n"
"border: 2px solid rgb(187, 128, 68);\n"
"min-width: 150px; max-width: 150px; min-height: 150px; max-height: 150px;\n"
""));
        label_36 = new QLabel(groupBox_16);
        label_36->setObjectName("label_36");
        label_36->setGeometry(QRect(10, 190, 171, 81));
        label_36->setStyleSheet(QString::fromUtf8("    color:#F0EAD6; \n"
" font-size: 14px;\n"
"font-weight: bold;\n"
"qproperty-alignment: 'AlignCenter';\n"
"letter-spacing:3px;\n"
"   "));
        label_36->setTextFormat(Qt::TextFormat::AutoText);
        groupBox_17 = new QGroupBox(groupBox_14);
        groupBox_17->setObjectName("groupBox_17");
        groupBox_17->setGeometry(QRect(20, 10, 191, 281));
        label_37 = new QLabel(groupBox_17);
        label_37->setObjectName("label_37");
        label_37->setGeometry(QRect(10, 10, 174, 194));
        label_37->setMinimumSize(QSize(174, 194));
        label_37->setMaximumSize(QSize(174, 194));
        label_37->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/newagents/grounded3.png);\n"
" background-color: rgba(255, 255, 255, 0.3);\n"
"border: 2px solid rgb(187, 128, 68);\n"
"min-width: 150px; max-width: 150px; min-height: 150px; max-height: 150px;\n"
""));
        label_38 = new QLabel(groupBox_17);
        label_38->setObjectName("label_38");
        label_38->setGeometry(QRect(10, 190, 171, 81));
        label_38->setStyleSheet(QString::fromUtf8("    color:#F0EAD6; \n"
" font-size: 14px;\n"
"font-weight: bold;\n"
"qproperty-alignment: 'AlignCenter';\n"
"letter-spacing:3px;\n"
"   "));
        label_38->setTextFormat(Qt::TextFormat::AutoText);
        groupBox_21 = new QGroupBox(groupBox_14);
        groupBox_21->setObjectName("groupBox_21");
        groupBox_21->setGeometry(QRect(640, 10, 191, 281));
        label_43 = new QLabel(groupBox_21);
        label_43->setObjectName("label_43");
        label_43->setGeometry(QRect(10, 10, 174, 194));
        label_43->setMinimumSize(QSize(174, 194));
        label_43->setMaximumSize(QSize(174, 194));
        label_43->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/newagents/grounded6.png);\n"
" background-color: rgba(255, 255, 255, 0.3);\n"
"border: 2px solid rgb(187, 128, 68);\n"
"min-width: 150px; max-width: 150px; min-height: 150px; max-height: 150px;\n"
""));
        label_44 = new QLabel(groupBox_21);
        label_44->setObjectName("label_44");
        label_44->setGeometry(QRect(10, 190, 171, 81));
        label_44->setStyleSheet(QString::fromUtf8("    color:#F0EAD6; \n"
" font-size: 14px;\n"
"font-weight: bold;\n"
"qproperty-alignment: 'AlignCenter';\n"
"letter-spacing:3px;\n"
"   "));
        label_44->setTextFormat(Qt::TextFormat::AutoText);

        verticalLayout->addWidget(groupBox_14);

        groupBox_18 = new QGroupBox(layoutWidget);
        groupBox_18->setObjectName("groupBox_18");
        groupBox_18->setMinimumSize(QSize(871, 301));
        groupBox_19 = new QGroupBox(groupBox_18);
        groupBox_19->setObjectName("groupBox_19");
        groupBox_19->setGeometry(QRect(430, 10, 191, 281));
        label_39 = new QLabel(groupBox_19);
        label_39->setObjectName("label_39");
        label_39->setGeometry(QRect(10, 10, 174, 194));
        label_39->setMinimumSize(QSize(174, 194));
        label_39->setMaximumSize(QSize(174, 194));
        label_39->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/newagents/grounded13.png);\n"
" background-color: rgba(255, 255, 255, 0.3);\n"
"border: 2px solid rgb(187, 128, 68);\n"
"min-width: 150px; max-width: 150px; min-height: 150px; max-height: 150px;\n"
""));
        label_40 = new QLabel(groupBox_19);
        label_40->setObjectName("label_40");
        label_40->setGeometry(QRect(10, 190, 171, 81));
        label_40->setStyleSheet(QString::fromUtf8("    color:#F0EAD6; \n"
" font-size: 14px;\n"
"font-weight: bold;\n"
"qproperty-alignment: 'AlignCenter';\n"
"letter-spacing:3px;\n"
"   "));
        label_40->setTextFormat(Qt::TextFormat::AutoText);
        groupBox_20 = new QGroupBox(groupBox_18);
        groupBox_20->setObjectName("groupBox_20");
        groupBox_20->setGeometry(QRect(230, 10, 191, 281));
        label_41 = new QLabel(groupBox_20);
        label_41->setObjectName("label_41");
        label_41->setGeometry(QRect(10, 10, 174, 194));
        label_41->setMinimumSize(QSize(174, 194));
        label_41->setMaximumSize(QSize(174, 194));
        label_41->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/newagents/grounded12.png);\n"
" background-color: rgba(255, 255, 255, 0.3);\n"
"border: 2px solid rgb(187, 128, 68);\n"
"min-width: 150px; max-width: 150px; min-height: 150px; max-height: 150px;\n"
""));
        label_42 = new QLabel(groupBox_20);
        label_42->setObjectName("label_42");
        label_42->setGeometry(QRect(10, 190, 171, 81));
        label_42->setStyleSheet(QString::fromUtf8("    color:#F0EAD6; \n"
" font-size: 14px;\n"
"font-weight: bold;\n"
"qproperty-alignment: 'AlignCenter';\n"
"letter-spacing:3px;\n"
"   "));
        label_42->setTextFormat(Qt::TextFormat::AutoText);
        groupBox_25 = new QGroupBox(groupBox_18);
        groupBox_25->setObjectName("groupBox_25");
        groupBox_25->setGeometry(QRect(10, 10, 191, 281));
        label_49 = new QLabel(groupBox_25);
        label_49->setObjectName("label_49");
        label_49->setGeometry(QRect(10, 10, 174, 194));
        label_49->setMinimumSize(QSize(174, 194));
        label_49->setMaximumSize(QSize(174, 194));
        label_49->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/newagents/waterwalking2.png);\n"
" background-color: rgba(255, 255, 255, 0.3);\n"
"border: 2px solid rgb(187, 128, 68);\n"
"min-width: 150px; max-width: 150px; min-height: 150px; max-height: 150px;\n"
""));
        label_50 = new QLabel(groupBox_25);
        label_50->setObjectName("label_50");
        label_50->setGeometry(QRect(10, 190, 171, 81));
        label_50->setStyleSheet(QString::fromUtf8("    color:#F0EAD6; \n"
" font-size: 14px;\n"
"font-weight: bold;\n"
"qproperty-alignment: 'AlignCenter';\n"
"letter-spacing:3px;\n"
"   "));
        label_50->setTextFormat(Qt::TextFormat::AutoText);
        groupBox_24 = new QGroupBox(groupBox_18);
        groupBox_24->setObjectName("groupBox_24");
        groupBox_24->setGeometry(QRect(650, 10, 191, 281));
        label_47 = new QLabel(groupBox_24);
        label_47->setObjectName("label_47");
        label_47->setGeometry(QRect(10, 10, 174, 194));
        label_47->setMinimumSize(QSize(174, 194));
        label_47->setMaximumSize(QSize(174, 194));
        label_47->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/newagents/floating2.png);\n"
" background-color: rgba(255, 255, 255, 0.3);\n"
"border: 2px solid rgb(187, 128, 68);\n"
"min-width: 150px; max-width: 150px; min-height: 150px; max-height: 150px;\n"
""));
        label_56 = new QLabel(groupBox_24);
        label_56->setObjectName("label_56");
        label_56->setGeometry(QRect(10, 190, 171, 81));
        label_56->setStyleSheet(QString::fromUtf8("    color:#F0EAD6; \n"
" font-size: 14px;\n"
"font-weight: bold;\n"
"qproperty-alignment: 'AlignCenter';\n"
"letter-spacing:3px;\n"
"   "));
        label_56->setTextFormat(Qt::TextFormat::AutoText);

        verticalLayout->addWidget(groupBox_18);

        groupBox_22 = new QGroupBox(layoutWidget);
        groupBox_22->setObjectName("groupBox_22");
        groupBox_22->setMinimumSize(QSize(851, 321));
        groupBox_23 = new QGroupBox(groupBox_22);
        groupBox_23->setObjectName("groupBox_23");
        groupBox_23->setGeometry(QRect(10, 20, 191, 281));
        label_45 = new QLabel(groupBox_23);
        label_45->setObjectName("label_45");
        label_45->setGeometry(QRect(10, 10, 174, 194));
        label_45->setMinimumSize(QSize(174, 194));
        label_45->setMaximumSize(QSize(174, 194));
        label_45->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/newagents/floating1.png);\n"
" background-color: rgba(255, 255, 255, 0.3);\n"
"border: 2px solid rgb(187, 128, 68);\n"
"min-width: 150px; max-width: 150px; min-height: 150px; max-height: 150px;\n"
""));
        label_55 = new QLabel(groupBox_23);
        label_55->setObjectName("label_55");
        label_55->setGeometry(QRect(10, 190, 171, 81));
        label_55->setStyleSheet(QString::fromUtf8("    color:#F0EAD6; \n"
" font-size: 14px;\n"
"font-weight: bold;\n"
"qproperty-alignment: 'AlignCenter';\n"
"letter-spacing:3px;\n"
"   "));
        label_55->setTextFormat(Qt::TextFormat::AutoText);
        groupBox_34 = new QGroupBox(groupBox_22);
        groupBox_34->setObjectName("groupBox_34");
        groupBox_34->setGeometry(QRect(230, 20, 191, 281));
        label_63 = new QLabel(groupBox_34);
        label_63->setObjectName("label_63");
        label_63->setGeometry(QRect(10, 10, 174, 194));
        label_63->setMinimumSize(QSize(174, 194));
        label_63->setMaximumSize(QSize(174, 194));
        label_63->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/newagents/waterwalking8.png);\n"
" background-color: rgba(255, 255, 255, 0.3);\n"
"border: 2px solid rgb(187, 128, 68);\n"
"min-width: 150px; max-width: 150px; min-height: 150px; max-height: 150px;\n"
""));
        label_52 = new QLabel(groupBox_34);
        label_52->setObjectName("label_52");
        label_52->setGeometry(QRect(10, 190, 171, 81));
        label_52->setStyleSheet(QString::fromUtf8("    color:#F0EAD6; \n"
" font-size: 14px;\n"
"font-weight: bold;\n"
"qproperty-alignment: 'AlignCenter';\n"
"letter-spacing:3px;\n"
"   "));
        label_52->setTextFormat(Qt::TextFormat::AutoText);
        groupBox_35 = new QGroupBox(groupBox_22);
        groupBox_35->setObjectName("groupBox_35");
        groupBox_35->setGeometry(QRect(450, 20, 191, 281));
        label_66 = new QLabel(groupBox_35);
        label_66->setObjectName("label_66");
        label_66->setGeometry(QRect(10, 10, 174, 194));
        label_66->setMinimumSize(QSize(174, 194));
        label_66->setMaximumSize(QSize(174, 194));
        label_66->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/newagents/waterwalking4.png);\n"
" background-color: rgba(255, 255, 255, 0.3);\n"
"border: 2px solid rgb(187, 128, 68);\n"
"min-width: 150px; max-width: 150px; min-height: 150px; max-height: 150px;\n"
""));
        label_54 = new QLabel(groupBox_35);
        label_54->setObjectName("label_54");
        label_54->setGeometry(QRect(10, 190, 171, 81));
        label_54->setStyleSheet(QString::fromUtf8("    color:#F0EAD6; \n"
" font-size: 14px;\n"
"font-weight: bold;\n"
"qproperty-alignment: 'AlignCenter';\n"
"letter-spacing:3px;\n"
"   "));
        label_54->setTextFormat(Qt::TextFormat::AutoText);

        verticalLayout->addWidget(groupBox_22);

        scrollArea->setWidget(scrollAreaWidgetContents);
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(1240, 110, 261, 141));
        label->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: #FFD700; /* \330\267\331\204\330\247\333\214\333\214 \330\250\330\261\330\247\331\202 */\n"
"   /* background-color: rgba(0, 0, 0, 80);  \331\206\333\214\331\205\331\207\342\200\214\330\264\331\201\330\247\331\201 \330\252\333\214\330\261\331\207 */\n"
"    border: 1px solid #FFD700;\n"
"	\n"
"    border-radius: 8px;\n"
"	background-color: transparent;\n"
"    padding: 6px 12px;\n"
"    font-family: \"Vazirmatn\", \"Tahoma\";\n"
"    font-size: 12px;\n"
"    font-weight: bold;\n"
"}\n"
""));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(1320, 310, 121, 41));
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
        menubar->setGeometry(QRect(0, 0, 1597, 25));
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
        groupBox_2->setTitle(QString());
        groupBox_3->setTitle(QString());
        label_13->setText(QString());
        label_12->setText(QCoreApplication::translate("Gallery", "\360\237\221\243 Kabu\n"
"400 2 120  1", nullptr));
        groupBox_5->setTitle(QString());
        label_21->setText(QString());
        label_10->setText(QCoreApplication::translate("Gallery", "\360\237\214\212 Billy\n"
"320 3 90  1", nullptr));
        groupBox_4->setTitle(QString());
        label_22->setText(QString());
        label_9->setText(QCoreApplication::translate("Gallery", "\360\237\221\243 Elsa\n"
"320 2 100  2", nullptr));
        groupBox_27->setTitle(QString());
        label_14->setText(QString());
        label_15->setText(QCoreApplication::translate("Gallery", "\360\237\225\212\357\270\217 Rambo\n"
"320 3 120  1", nullptr));
        groupBox_6->setTitle(QString());
        groupBox_7->setTitle(QString());
        label_23->setText(QString());
        label_20->setText(QCoreApplication::translate("Gallery", "\360\237\221\243 Salih\n"
"400 2 80  1", nullptr));
        groupBox_8->setTitle(QString());
        label_24->setText(QString());
        label_19->setText(QCoreApplication::translate("Gallery", "\360\237\221\243 Karissa\n"
"280 2 140  2", nullptr));
        groupBox_9->setTitle(QString());
        label_25->setText(QString());
        label_26->setText(QCoreApplication::translate("Gallery", "\360\237\214\212 Angus\n"
"400 2 100  1", nullptr));
        groupBox_28->setTitle(QString());
        label_16->setText(QString());
        label_17->setText(QCoreApplication::translate("Gallery", "\360\237\214\212 Medusa\n"
"320 2 90  2", nullptr));
        groupBox_10->setTitle(QString());
        groupBox_11->setTitle(QString());
        label_27->setText(QString());
        label_28->setText(QCoreApplication::translate("Gallery", "\360\237\221\243 Sir Lumark\n"
"320 3 110  1", nullptr));
        groupBox_12->setTitle(QString());
        label_29->setText(QString());
        label_30->setText(QCoreApplication::translate("Gallery", "\360\237\221\243 Kanar\n"
"160 2 100  2", nullptr));
        groupBox_13->setTitle(QString());
        label_31->setText(QString());
        label_32->setText(QCoreApplication::translate("Gallery", "\360\237\221\243 Eloi\n"
"240 2 100  2", nullptr));
        groupBox_29->setTitle(QString());
        label_53->setText(QString());
        label_51->setText(QCoreApplication::translate("Gallery", "\360\237\214\212 Raketon\n"
"320 2 80  2", nullptr));
        groupBox_14->setTitle(QString());
        groupBox_15->setTitle(QString());
        label_33->setText(QString());
        label_34->setText(QCoreApplication::translate("Gallery", "\360\237\214\212 Duraham\n"
"320 2 100  2", nullptr));
        groupBox_16->setTitle(QString());
        label_35->setText(QString());
        label_36->setText(QCoreApplication::translate("Gallery", "\360\237\221\243 Khan\n"
"320 2 90  1", nullptr));
        groupBox_17->setTitle(QString());
        label_37->setText(QString());
        label_38->setText(QCoreApplication::translate("Gallery", "\360\237\221\243 Boi\n"
"400 2 100  1", nullptr));
        groupBox_21->setTitle(QString());
        label_43->setText(QString());
        label_44->setText(QCoreApplication::translate("Gallery", "\360\237\221\243 Tusk\n"
"400 2 100  1", nullptr));
        groupBox_18->setTitle(QString());
        groupBox_19->setTitle(QString());
        label_39->setText(QString());
        label_40->setText(QCoreApplication::translate("Gallery", "\360\237\221\243 SirFilip\n"
"400 2 100  1", nullptr));
        groupBox_20->setTitle(QString());
        label_41->setText(QString());
        label_42->setText(QCoreApplication::translate("Gallery", "\360\237\221\243 Frost\n"
"260 2 80  2", nullptr));
        groupBox_25->setTitle(QString());
        label_49->setText(QString());
        label_50->setText(QCoreApplication::translate("Gallery", "\360\237\214\212 ClonelBaba\n"
"400 2 100  1", nullptr));
        groupBox_24->setTitle(QString());
        label_47->setText(QString());
        label_56->setText(QCoreApplication::translate("Gallery", "\342\230\201\357\270\217 Sabrina\n"
"320 3 100  1", nullptr));
        groupBox_22->setTitle(QString());
        groupBox_23->setTitle(QString());
        label_45->setText(QString());
        label_55->setText(QCoreApplication::translate("Gallery", "\342\230\201\357\270\217 Death\n"
"240 3 120  2", nullptr));
        groupBox_34->setTitle(QString());
        label_63->setText(QString());
        label_52->setText(QCoreApplication::translate("Gallery", "\360\237\214\212 Bunka\n"
"320 3 100  1", nullptr));
        groupBox_35->setTitle(QString());
        label_66->setText(QString());
        label_54->setText(QCoreApplication::translate("Gallery", "\360\237\214\212 Sunka\n"
"320 3 100  1", nullptr));
        label->setText(QCoreApplication::translate("Gallery", "Stats Guide:\n"
" \n"
"HP | Mobility | Damage | AttackRange  \n"
" \n"
"Example: 320 | 2 | 100 | 2\n"
"", nullptr));
        pushButton->setText(QCoreApplication::translate("Gallery", "back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Gallery: public Ui_Gallery {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GALLERY_H

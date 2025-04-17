/********************************************************************************
** Form generated from reading UI file 'gallery.ui'
**
** Created by: Qt User Interface Compiler version 6.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GALLERY_H
#define UI_GALLERY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Gallery
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Gallery)
    {
        if (Gallery->objectName().isEmpty())
            Gallery->setObjectName("Gallery");
        Gallery->resize(800, 600);
        centralwidget = new QWidget(Gallery);
        centralwidget->setObjectName("centralwidget");
        Gallery->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Gallery);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 22));
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
    } // retranslateUi

};

namespace Ui {
    class Gallery: public Ui_Gallery {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GALLERY_H

QT       += core gui \
    quick

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    agent.cpp \
    gallery.cpp \
    main.cpp \
    mainpage.cpp \
    player.cpp \
    startpage.cpp \
    tile.cpp \
    welcome.cpp

HEADERS += \
    agent.h \
    gallery.h \
    mainpage.h \
    player.h \
    startpage.h \
    tile.h \
    welcome.h

FORMS += \
    gallery.ui \
    mainpage.ui \
    startpage.ui \
    welcome.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Fonts.qrc \
    agents.qrc \
    images.qrc \
    text.qrc

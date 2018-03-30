#-------------------------------------------------
#
# Project created by QtCreator 2017-05-16T16:47:22
#
#-------------------------------------------------

QT       += core gui
QT += multimedia
CONFIG+=resources_big

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = migong
TEMPLATE = app


SOURCES += main.cpp\
        migong.cpp \
    victory.cpp \
    chaiqiang.cpp \
    defeatmenu.cpp

HEADERS  += migong.h \
    victory.h \
    chaiqiang.h \
    defeatmenu.h

FORMS    += migong.ui \
    victory.ui \
    chaiqiang.ui \
    defeatmenu.ui

RESOURCES += \
    maze.qrc \
    bgm.qrc

DISTFILES +=

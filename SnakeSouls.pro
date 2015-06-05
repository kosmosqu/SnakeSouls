#-------------------------------------------------
#
# Project created by QtCreator 2015-06-04T23:59:31
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SnakeSouls
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    cherry.cpp \
    gameboard.cpp \
    player.cpp \
    snakebody.cpp \
    snakehead.cpp \
    temp.cpp

HEADERS  += mainwindow.h \
    cherry.h \
    documentation.h \
    gameboard.h \
    player.h \
    snakebody.h \
    snakehead.h \
    temp.h

FORMS    += mainwindow.ui \
    cherry.ui \
    gameboard.ui \
    player.ui \
    snakebody.ui \
    snakehead.ui \
    temp.ui

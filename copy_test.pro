#-------------------------------------------------
#
# Project created by QtCreator 2013-06-22T17:43:33
#
#-------------------------------------------------

QT       += core gui
QT += network
QT+=webkit webview
LIBS += -L/usr/local/lib -lqjson
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = copy_test
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    qtdownload.cpp \
    json.cpp

HEADERS  += mainwindow.h \
    qtdownload.h \
    json.h

FORMS    += mainwindow.ui

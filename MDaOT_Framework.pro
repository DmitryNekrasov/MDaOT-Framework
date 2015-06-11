#-------------------------------------------------
#
# Project created by QtCreator 2015-06-10T23:15:45
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MDaOT_Framework
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    core.cpp \
    video.cpp \
    frame.cpp

HEADERS  += mainwindow.h \
    core.h \
    video.h \
    frame.h

FORMS    += mainwindow.ui

LIBS += -L/opt/local/lib \
        -lopencv_highgui \
        -lopencv_core \
        -lopencv_video \
        -lopencv_imgproc \
        -lopencv_nonfree

INCLUDEPATH += /opt/local/include

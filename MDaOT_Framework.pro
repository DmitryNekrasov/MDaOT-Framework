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
    frame.cpp \
    detector.cpp \
    detectionmethod.cpp \
    sequentialimages.cpp \
    filter.cpp \
    grayscalefilter.cpp \
    binaryfilter.cpp \
    blurfilter.cpp \
    filterchain.cpp \
    medianfilter.cpp \
    backgroundsubtraction.cpp \
    rectangle.cpp \
    movenmenthandler.cpp \
    mymovenmenthandler.cpp \
    filterhandler.cpp \
    myfilterhandler.cpp \
    outgrayscalefh.cpp \
    outmedianfh.cpp \
    outblurfh.cpp \
    outbinaryfh.cpp \
    recognitionmethod.cpp \
    recognizer.cpp \
    withform.cpp \
    filterdialog.cpp \
    point.cpp \
    mybackgroundsubtraction.cpp

HEADERS  += mainwindow.h \
    core.h \
    video.h \
    frame.h \
    detector.h \
    detectionmethod.h \
    sequentialimages.h \
    filter.h \
    grayscalefilter.h \
    binaryfilter.h \
    blurfilter.h \
    filterchain.h \
    medianfilter.h \
    backgroundsubtraction.h \
    rectangle.h \
    movenmenthandler.h \
    mymovenmenthandler.h \
    filterhandler.h \
    myfilterhandler.h \
    outgrayscalefh.h \
    outmedianfh.h \
    outblurfh.h \
    outbinaryfh.h \
    recognitionmethod.h \
    recognizer.h \
    withform.h \
    filterdialog.h \
    point.h \
    mybackgroundsubtraction.h

FORMS    += mainwindow.ui \
    filterdialog.ui

LIBS += -L/opt/local/lib \
        -lopencv_highgui \
        -lopencv_core \
        -lopencv_video \
        -lopencv_imgproc \
        -lopencv_nonfree

INCLUDEPATH += /opt/local/include

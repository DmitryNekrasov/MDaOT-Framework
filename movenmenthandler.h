#ifndef MOVENMENTHANDLER_H
#define MOVENMENTHANDLER_H
#include "frame.h"
//#include "mainwindow.h"

class MainWindow;

class MovenmentHandler
{
protected:
    MainWindow *window;

public:

    virtual void onMove(Frame frame) = 0;
    void setWindow(MainWindow *win);

    ~MovenmentHandler();
};

#endif // MOVENMENTHANDLER_H

#ifndef MYMOVENMENTHANDLER_H
#define MYMOVENMENTHANDLER_H
#include "movenmenthandler.h"


class MyMovenmentHandler: public MovenmentHandler
{
public:

    virtual void onMove(Frame frame, vector<Rectangle> *rectangles, vector<Point> *mask);

    MyMovenmentHandler();
    ~MyMovenmentHandler();
};

#endif // MYMOVENMENTHANDLER_H

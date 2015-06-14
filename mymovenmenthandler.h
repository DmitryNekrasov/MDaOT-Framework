#ifndef MYMOVENMENTHANDLER_H
#define MYMOVENMENTHANDLER_H
#include "movenmenthandler.h"


class MyMovenmentHandler: public MovenmentHandler
{
public:

    virtual void onMove(Frame frame);

    MyMovenmentHandler();
    ~MyMovenmentHandler();
};

#endif // MYMOVENMENTHANDLER_H

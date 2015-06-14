#ifndef MOVENMENTHANDLER_H
#define MOVENMENTHANDLER_H
#include "frame.h"


class MovenmentHandler
{
public:

    virtual void onMove(Frame frame) = 0;

    ~MovenmentHandler();
};

#endif // MOVENMENTHANDLER_H

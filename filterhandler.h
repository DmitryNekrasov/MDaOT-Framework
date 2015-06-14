#ifndef FILTERHANDLER_H
#define FILTERHANDLER_H
#include "frame.h"


class FilterHandler
{
public:

    virtual void onApplyFilter(Frame frame) = 0;

    ~FilterHandler();
};

#endif // FILTERHANDLER_H

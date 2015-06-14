#ifndef MYFILTERHANDLER_H
#define MYFILTERHANDLER_H
#include "filterhandler.h"


class MyFilterHandler: public FilterHandler
{
public:

    virtual void onApplyFilter(Frame frame);

    MyFilterHandler();
    ~MyFilterHandler();
};

#endif // MYFILTERHANDLER_H

#ifndef FILTERHANDLER_H
#define FILTERHANDLER_H
#include "frame.h"

class FilterDialog;

class FilterHandler
{
protected:
    FilterDialog *window;

public:

    virtual void onApplyFilter(Frame frame) = 0;
    void setWindow(FilterDialog *win);

    ~FilterHandler();
};

#endif // FILTERHANDLER_H

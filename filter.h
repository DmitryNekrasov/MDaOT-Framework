#ifndef FILTER_H
#define FILTER_H
#include "frame.h"
#include "filterhandler.h"
#include "myfilterhandler.h"


class Filter
{
protected:
    FilterHandler *filterHandler;

public:
    virtual Frame apply(Frame originalFrame) = 0;
    void performApplyFilter(Frame frame);
    ~Filter();
};

#endif // FILTER_H

#ifndef FILTER_H
#define FILTER_H
#include "frame.h"
#include "filterhandler.h"
#include "myfilterhandler.h"
#include "outgrayscalefh.h"
#include "outmedianfh.h"
#include "outblurfh.h"
#include "outbinaryfh.h"


class Filter
{
protected:
    FilterHandler *filterHandler;

public:
    virtual Frame apply(Frame originalFrame) = 0;
    void performApplyFilter(Frame frame);

    FilterHandler* getFilterHandler();
    void setFilterHandler(FilterHandler *handler);

    ~Filter();
};

#endif // FILTER_H

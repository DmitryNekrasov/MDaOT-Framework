#ifndef OUTMEDIANFH_H
#define OUTMEDIANFH_H
#include "filterhandler.h"


class OutMedianFH: public FilterHandler
{
public:

    virtual void onApplyFilter(Frame frame);

    OutMedianFH();
    ~OutMedianFH();
};

#endif // OUTMEDIANFH_H

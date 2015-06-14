#ifndef OUTGRAYSCALEFH_H
#define OUTGRAYSCALEFH_H
#include "filterhandler.h"


class OutGrayscaleFH: public FilterHandler
{
public:

    virtual void onApplyFilter(Frame frame);

    OutGrayscaleFH();
    ~OutGrayscaleFH();
};

#endif // OUTGRAYSCALEFH_H

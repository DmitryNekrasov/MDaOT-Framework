#ifndef OUTBLURFH_H
#define OUTBLURFH_H
#include "filterhandler.h"


class OutBlurFH: public FilterHandler
{
public:

    virtual void onApplyFilter(Frame frame);

    OutBlurFH();
    ~OutBlurFH();
};

#endif // OUTBLURFH_H

#ifndef OUTBINARYFH_H
#define OUTBINARYFH_H
#include "filterhandler.h"


class OutBinaryFH: public FilterHandler
{
public:

    virtual void onApplyFilter(Frame frame);

    OutBinaryFH();
    ~OutBinaryFH();
};

#endif // OUTBINARYFH_H

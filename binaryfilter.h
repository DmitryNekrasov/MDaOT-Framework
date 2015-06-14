#ifndef BINARYFILTER_H
#define BINARYFILTER_H
#include "filter.h"
#include "filterhandler.h"


class BinaryFilter: public Filter
{
private:

    int threshold;

public:

    virtual Frame apply(Frame originalFrame);

    int getThreshold();
    void setThreshold(int threshold);

    BinaryFilter(int threshold, FilterHandler *handler);
    BinaryFilter(int threshold);
    ~BinaryFilter();
};

#endif // BINARYFILTER_H

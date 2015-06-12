#ifndef MEDIANFILTER_H
#define MEDIANFILTER_H
#include "filter.h"


class MedianFilter: public Filter
{
private:

    int size;

public:

    virtual Frame apply(Frame originalFrame);

    int getSize();
    void setSize(int size);

    MedianFilter(int size);
    ~MedianFilter();
};

#endif // MEDIANFILTER_H

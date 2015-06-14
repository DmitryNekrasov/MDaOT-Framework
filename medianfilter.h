#ifndef MEDIANFILTER_H
#define MEDIANFILTER_H
#include "filter.h"
#include "filterhandler.h"


class MedianFilter: public Filter
{
private:

    int size;

public:

    virtual Frame apply(Frame originalFrame);

    int getSize();
    void setSize(int size);

    MedianFilter(int size);
    MedianFilter(int size, FilterHandler *handler);
    ~MedianFilter();
};

#endif // MEDIANFILTER_H

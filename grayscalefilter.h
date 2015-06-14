#ifndef GRAYSCALEFILTER_H
#define GRAYSCALEFILTER_H
#include "filter.h"
#include "filterhandler.h"


class GrayscaleFilter: public Filter
{
public:

    virtual Frame apply(Frame originalFrame);

    GrayscaleFilter();
    GrayscaleFilter(FilterHandler *handler);
    ~GrayscaleFilter();
};

#endif // GRAYSCALEFILTER_H

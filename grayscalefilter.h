#ifndef GRAYSCALEFILTER_H
#define GRAYSCALEFILTER_H
#include "filter.h"


class GrayscaleFilter: public Filter
{
public:

    virtual Frame apply(Frame originalFrame);

    GrayscaleFilter();
    ~GrayscaleFilter();
};

#endif // GRAYSCALEFILTER_H

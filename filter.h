#ifndef FILTER_H
#define FILTER_H
#include "frame.h"

class Filter
{
public:
    virtual Frame apply(Frame originalFrame) = 0;
    ~Filter();
};

#endif // FILTER_H

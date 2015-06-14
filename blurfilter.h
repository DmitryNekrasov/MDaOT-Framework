#ifndef BLURFILTER_H
#define BLURFILTER_H
#include "filter.h"
#include "filterhandler.h"


class BlurFilter: public Filter
{
private:

    int widthBlur;
    int heightBlur;

public:

    virtual Frame apply(Frame originalFrame);

    int getWidthBlur();
    void setWidthBlur(int widthBlur);

    int getHeightBlur();
    void setHeightBlur(int heightBlur);

    BlurFilter(int widthBlur, int heightBlur);
    BlurFilter(int widthBlur, int heightBlur, FilterHandler *handler);
    ~BlurFilter();
};

#endif // BLURFILTER_H

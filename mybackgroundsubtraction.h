#ifndef MYBACKGROUNDSUBTRACTION_H
#define MYBACKGROUNDSUBTRACTION_H

#include "detectionmethod.h"


class MyBackgroundSubtraction: public DetectionMethod
{
private:
    Frame background;
    Filter *grayscaleFilter;

public:

    virtual void detect(Video video);
    virtual void init(Video video);

    MyBackgroundSubtraction();
    MyBackgroundSubtraction(MovenmentHandler *handler);
    ~MyBackgroundSubtraction();
};

#endif // MYBACKGROUNDSUBTRACTION_H

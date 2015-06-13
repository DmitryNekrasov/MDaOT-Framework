#ifndef BACKGROUNDSUBTRACTION_H
#define BACKGROUNDSUBTRACTION_H
#include "detectionmethod.h"


class BackgroundSubtraction: public DetectionMethod
{
public:

    virtual void detect(Video video);

    BackgroundSubtraction();
    ~BackgroundSubtraction();
};

#endif // BACKGROUNDSUBTRACTION_H

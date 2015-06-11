#ifndef DETECTIONMETHOD_H
#define DETECTIONMETHOD_H
#include "video.h"

class DetectionMethod
{
public:
    ~DetectionMethod();
    virtual void detect(Video video) = 0;
};

#endif // DETECTIONMETHOD_H

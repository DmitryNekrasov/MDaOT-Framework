#ifndef DETECTIONMETHOD_H
#define DETECTIONMETHOD_H
#include "video.h"
#include "filterchain.h"

class DetectionMethod
{
protected:
    FilterChain filterChain;
public:
    ~DetectionMethod();
    virtual void detect(Video video) = 0;
};

#endif // DETECTIONMETHOD_H

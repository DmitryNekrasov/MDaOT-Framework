#ifndef DETECTOR_H
#define DETECTOR_H
#include "video.h"


class Detector
{
public:
    ~Detector();
    virtual void detect(Video video) = 0;
};

#endif // DETECTOR_H

#ifndef DETECTOR_H
#define DETECTOR_H
#include "video.h"
#include "detectionmethod.h"


class Detector
{
protected:
    DetectionMethod* detectionMethod;

public:

    void setDetectionMethod(DetectionMethod* detectionMethod);
    void execute(Video video);
    void startDetector();

    Detector();
    ~Detector();
};

#endif // DETECTOR_H

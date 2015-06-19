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
    DetectionMethod* getDetectionMethod();
    void execute(Video video);
    void startDetector(Video video);

    Detector();
    ~Detector();
};

#endif // DETECTOR_H

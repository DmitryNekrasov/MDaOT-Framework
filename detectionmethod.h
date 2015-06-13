#ifndef DETECTIONMETHOD_H
#define DETECTIONMETHOD_H
#include "video.h"
#include "filterchain.h"
#include "QDebug"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/video/tracking.hpp>
#include <opencv2/imgproc/imgproc_c.h>
#include <opencv2/opencv.hpp>


class DetectionMethod
{
protected:
    FilterChain filterChain;
public:
    ~DetectionMethod();
    virtual void detect(Video video) = 0;
};

#endif // DETECTIONMETHOD_H

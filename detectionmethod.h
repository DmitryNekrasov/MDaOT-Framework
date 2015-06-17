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
#include "filter.h"
#include "grayscalefilter.h"
#include "binaryfilter.h"
#include "blurfilter.h"
#include "medianfilter.h"
#include "movenmenthandler.h"


class DetectionMethod
{
protected:

    MovenmentHandler *movenmentHandler;
    FilterChain filterChain;
    vector<Rectangle> moveObjectRectangles;
    Rectangle *region;

public:
    ~DetectionMethod();
    virtual void detect(Video video) = 0;
    virtual void init() = 0;
    void performOnMove(Frame frame);
    void setRegion(Rectangle *region);
    FilterChain getFilterChain();
};

#endif // DETECTIONMETHOD_H

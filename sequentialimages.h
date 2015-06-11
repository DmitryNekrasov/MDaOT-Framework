#ifndef SEQUENTIALIMAGES_H
#define SEQUENTIALIMAGES_H
#include "detectionmethod.h"
#include "filter.h"
#include "grayscalefilter.h"
#include "binaryfilter.h"
#include "blurfilter.h"


class SequentialImages: public DetectionMethod
{
public:

    virtual void detect(Video video);
    void searchForMovement(cv::Mat thresholdImage, cv::Mat cameraFeed);

    SequentialImages();
    ~SequentialImages();
};

#endif // SEQUENTIALIMAGES_H

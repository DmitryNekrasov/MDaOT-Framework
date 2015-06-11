#ifndef SEQUENTIALIMAGES_H
#define SEQUENTIALIMAGES_H
#include "detectionmethod.h"
#include "filter.h"
#include "grayscalefilter.h"
#include "binaryfilter.h"


class SequentialImages: public DetectionMethod
{
public:

    virtual void detect(Video video);

    SequentialImages();
    ~SequentialImages();
};

#endif // SEQUENTIALIMAGES_H

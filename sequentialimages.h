#ifndef SEQUENTIALIMAGES_H
#define SEQUENTIALIMAGES_H
#include "detectionmethod.h"


class SequentialImages: public DetectionMethod
{
private:
    Filter *grayscaleFilter;
    void processingFrame(Video &video);

public:

    virtual void detect(Video video);
    virtual void init();

    SequentialImages();
    SequentialImages(MovenmentHandler *handler);
    ~SequentialImages();
};

#endif // SEQUENTIALIMAGES_H

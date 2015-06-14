#ifndef SEQUENTIALIMAGES_H
#define SEQUENTIALIMAGES_H
#include "detectionmethod.h"


class SequentialImages: public DetectionMethod
{



public:

    virtual void detect(Video video);


    SequentialImages();
    SequentialImages(MovenmentHandler *handler);
    ~SequentialImages();
};

#endif // SEQUENTIALIMAGES_H

#include "sequentialimages.h"


void SequentialImages::init(Video video)
{
    qDebug() << "Detection Sequential Images method";

    if (filterChain.getCount() == 0) {

        Filter *binaryFilter = new BinaryFilter(20);
        Filter *blurFilter = new BlurFilter(10, 10);
        Filter *median = new MedianFilter(5);
        Filter *finalBinaryFilter = new BinaryFilter(20);

        filterChain.add(binaryFilter);
        filterChain.add(median);
        filterChain.add(blurFilter);
        filterChain.add(finalBinaryFilter);

        grayscaleFilter = new GrayscaleFilter();
    }
}

void SequentialImages::processingFrame(Video &video)
{
    if (!video.hasNext())
        return;

    Frame originalFrame1 = video.nextFrame();

    if (!video.hasNext())
        return;

    Frame originalFrame2 = video.nextFrame();

    if (region != NULL) {
        originalFrame1 = Frame(originalFrame1.getCvMat()(region->getCvRect()));
        originalFrame2 = Frame(originalFrame2.getCvMat()(region->getCvRect()));
    }

    Frame grayFrame1 = grayscaleFilter->apply(originalFrame1);

    Frame grayFrame2 = grayscaleFilter->apply(originalFrame2);

    Frame diffFrame = Frame::difference(grayFrame1, grayFrame2);

    // применяем цепочку фильтров
    Frame blurBinaryFrame = filterChain.apply(diffFrame);

    vector<Point> mask;
    moveObjectRectangles = Frame::searchForMovement(blurBinaryFrame.getCvMat(), &mask);

    if (movenmentHandler != NULL) {
        performOnMove(originalFrame1, &moveObjectRectangles, &mask);
    }
}

void SequentialImages::detect(Video video)
{
    processingFrame(video);
}

SequentialImages::SequentialImages()
{
    movenmentHandler = NULL;
    region = NULL;
}

SequentialImages::SequentialImages(MovenmentHandler *handler)
{
    movenmentHandler = handler;
    region = NULL;
}

SequentialImages::~SequentialImages() {

}


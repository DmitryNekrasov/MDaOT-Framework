#include "sequentialimages.h"


void SequentialImages::init()
{
    qDebug() << "Detection Sequential Images method";

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

void SequentialImages::processingFrame(Video &video)
{
    string mainWindowName = "Motion";

    Frame originalFrame1 = video.nextFrame();

//        if (!video.hasNext())
//            break;

    Frame originalFrame2 = video.nextFrame();

    if (region != NULL) {
        originalFrame1 = Frame(originalFrame1.getCvMat()(region->getCvRect()));
        originalFrame2 = Frame(originalFrame2.getCvMat()(region->getCvRect()));
    }

    Frame grayFrame1 = grayscaleFilter->apply(originalFrame1);

    Frame grayFrame2 = grayscaleFilter->apply(originalFrame2);

    Frame diffFrame = Frame::difference(grayFrame1, grayFrame2);

    Frame blurBinaryFrame = filterChain.apply(diffFrame);
//        blurBinaryFrame.show("qqq");

    vector<Point> mask;
    moveObjectRectangles = Frame::searchForMovement(blurBinaryFrame.getCvMat(), &mask);

    if (movenmentHandler != NULL) {
        performOnMove(originalFrame1, &moveObjectRectangles, &mask);
    }

    if (!moveObjectRectangles.empty())
        for (int i = 0; i < moveObjectRectangles.size(); i++) {
            int area = moveObjectRectangles.at(i).getArea();
//                if (area > 10000) {
                originalFrame1.drawRectangle(moveObjectRectangles.at(i));
//                    qDebug() << area;
//                }
        }


    Frame::destroyWindow(mainWindowName);
}

void SequentialImages::detect(Video video) {
    processingFrame(video);
}

SequentialImages::SequentialImages() {
    movenmentHandler = NULL;
    region = NULL;
}

SequentialImages::SequentialImages(MovenmentHandler *handler) {
    movenmentHandler = handler;
    region = NULL;
}

SequentialImages::~SequentialImages() {

}


#include "sequentialimages.h"


void SequentialImages::detect(Video video) {
    qDebug() << "Detection Sequential Images method";

    string mainWindowName = "Motion";

    Filter *grayscaleFilter = new GrayscaleFilter();
    Filter *binaryFilter = new BinaryFilter(20);
    Filter *blurFilter = new BlurFilter(7, 7);

    filterChain.add(binaryFilter);
    filterChain.add(blurFilter);
    filterChain.add(binaryFilter);

    Frame originalFrame1, grayFrame1, originalFrame2, grayFrame2, diffFrame, blurBinaryFrame;

    vector<Rectangle> rectangles;

    while (video.hasNext()) {
        originalFrame1 = video.nextFrame();

        grayFrame1 = grayscaleFilter->apply(originalFrame1);

        if (!video.hasNext())
            break;

        originalFrame2 = video.nextFrame();
        grayFrame2 = grayscaleFilter->apply(originalFrame2);

        diffFrame = Frame::difference(grayFrame1, grayFrame2);

        blurBinaryFrame = filterChain.apply(diffFrame);

        rectangles = Frame::searchForMovement(blurBinaryFrame.getCvMat(), originalFrame1.getCvMat());

        originalFrame1.drawRectangle(rectangles.at(0));

        bool isContinue = originalFrame1.show(mainWindowName);
        if (!isContinue)
            break;
    }


    Frame::destroyWindow(mainWindowName);
}

SequentialImages::SequentialImages() {

}

SequentialImages::~SequentialImages() {

}


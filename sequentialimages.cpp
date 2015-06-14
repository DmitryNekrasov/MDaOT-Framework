#include "sequentialimages.h"


void SequentialImages::detect(Video video) {
    qDebug() << "Detection Sequential Images method";

    string mainWindowName = "Motion";

    Filter *grayscaleFilter = new GrayscaleFilter();
    Filter *binaryFilter = new BinaryFilter(20);
    Filter *blurFilter = new BlurFilter(10, 10);
    Filter *bin = new BinaryFilter(1, new OutBinaryFH());

    filterChain.add(binaryFilter);
    filterChain.add(blurFilter);
    filterChain.add(binaryFilter);
    filterChain.add(blurFilter);
    filterChain.add(bin);

    Frame originalFrame1, grayFrame1, originalFrame2, grayFrame2, diffFrame, blurBinaryFrame;

    while (video.hasNext()) {
        originalFrame1 = video.nextFrame();

        if (!video.hasNext())
            break;

        originalFrame2 = video.nextFrame();

        if (region != NULL) {
            originalFrame1 = Frame(originalFrame1.getCvMat()(region->getCvRect()));
            originalFrame2 = Frame(originalFrame2.getCvMat()(region->getCvRect()));
        }

        grayFrame1 = grayscaleFilter->apply(originalFrame1);

        grayFrame2 = grayscaleFilter->apply(originalFrame2);

        diffFrame = Frame::difference(grayFrame1, grayFrame2);

        blurBinaryFrame = filterChain.apply(diffFrame);

        moveObjectRectangles = Frame::searchForMovement(blurBinaryFrame.getCvMat(), originalFrame1.getCvMat());

        if (movenmentHandler != NULL) {
            if (!moveObjectRectangles.empty()) {
                performOnMove(Frame(originalFrame1.getCvMat()(moveObjectRectangles.at(0).getCvRect())));
            }
        }

        if (!moveObjectRectangles.empty())
            for (int i = 0; i < moveObjectRectangles.size(); i++) {
                int area = moveObjectRectangles.at(i).getArea();
                if (area > 10000) {
                    originalFrame1.drawRectangle(moveObjectRectangles.at(i));
//                    qDebug() << area;
                }
            }

        bool isContinue = originalFrame1.show(mainWindowName);
        if (!isContinue)
            break;
    }


    Frame::destroyWindow(mainWindowName);
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


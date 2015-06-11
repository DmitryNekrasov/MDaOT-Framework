#include "sequentialimages.h"
#include "QDebug"

void SequentialImages::detect(Video video) {
    qDebug() << "Detection Sequential Images method";

    string mainWindowName = "Motion";
    string grayscaleWindowName = "Grayscale";
    string binaryWindowName = "Binary";
    string blurWindowName = "Blur";
    string blurBinaryWindowName = "Blur binary";

    Filter *grayscaleFilter = new GrayscaleFilter();
    Filter *binaryFilter = new BinaryFilter(20);
    Filter *blurFilter = new BlurFilter(7, 7);

    while (true) {
        Frame originalFrame1 = video.nextFrame();
        bool isContinue = originalFrame1.show(mainWindowName);
        Frame grayFrame1 = grayscaleFilter->apply(originalFrame1);

        Frame originalFrame2 = video.nextFrame();
        Frame grayFrame2 = grayscaleFilter->apply(originalFrame2);

        Frame diffFrame = Frame::difference(grayFrame1, grayFrame2);

        Frame binaryFrame = binaryFilter->apply(diffFrame);
        binaryFrame.show(binaryWindowName);

        Frame blurFrame = blurFilter->apply(binaryFrame);
//        blurFrame.show(blurWindowName);

        Frame blurBinaryFrame = binaryFilter->apply(blurFrame);
        blurBinaryFrame.show(blurBinaryWindowName);

        if (!isContinue)
            break;
    }

    Frame::destroyWindow(mainWindowName);
    Frame::destroyWindow(grayscaleWindowName);
    Frame::destroyWindow(binaryWindowName);
    Frame::destroyWindow(blurWindowName);
    Frame::destroyWindow(blurBinaryWindowName);
}

SequentialImages::SequentialImages() {

}

SequentialImages::~SequentialImages() {

}


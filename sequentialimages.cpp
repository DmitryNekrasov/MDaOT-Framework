#include "sequentialimages.h"
#include "QDebug"

void SequentialImages::detect(Video video) {
    qDebug() << "Detection Sequential Images method";

    string mainWindowName = "Motion";
    string grayscaleWindowName = "Grayscale";
    string binaryWindowName = "Binary";
    string blurWindowName = "Blur";

    Filter *grayscaleFilter = new GrayscaleFilter();
    Filter *binaryFilter = new BinaryFilter(128);
    Filter *blurFilter = new BlurFilter(7, 7);

    while (true) {
        Frame originalFrame = video.nextFrame();
        bool isContinue = originalFrame.show(mainWindowName);

        Frame grayFrame = grayscaleFilter->apply(originalFrame);
//        grayFrame.show(grayscaleWindowName);

        Frame binaryFrame = binaryFilter->apply(grayFrame);
//        binaryFrame.show(binaryWindowName);

        Frame blurFrame = blurFilter->apply(binaryFrame);
        blurFrame.show(blurWindowName);

        if (!isContinue)
            break;
    }

    Frame::destroyWindow(mainWindowName);
    Frame::destroyWindow(grayscaleWindowName);
    Frame::destroyWindow(binaryWindowName);
    Frame::destroyWindow(blurWindowName);
}

SequentialImages::SequentialImages() {

}

SequentialImages::~SequentialImages() {

}


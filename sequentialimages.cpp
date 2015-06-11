#include "sequentialimages.h"
#include "QDebug"

void SequentialImages::detect(Video video) {
    qDebug() << "Detection Sequential Images method";

    string mainWindowName = "Motion";
    string grayscaleWindowName = "Grayscale";
    string binaryWindowName = "Binary";

    Filter *grayscale = new GrayscaleFilter();
    Filter *binaryFilter = new BinaryFilter(128);

    while (true) {
        Frame originalFrame = video.nextFrame();
        bool isContinue = originalFrame.show(mainWindowName);

        Frame grayFrame = grayscale->apply(originalFrame);
        grayFrame.show(grayscaleWindowName);

        Frame binaryFrame = binaryFilter->apply(grayFrame);
        binaryFrame.show(binaryWindowName);

        if (!isContinue)
            break;
    }

    Frame::destroyWindow(mainWindowName);
    Frame::destroyWindow(grayscaleWindowName);
    Frame::destroyWindow(binaryWindowName);
}

SequentialImages::SequentialImages() {

}

SequentialImages::~SequentialImages() {

}


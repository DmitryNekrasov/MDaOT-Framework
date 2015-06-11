#include "sequentialimages.h"
#include "QDebug"

void SequentialImages::detect(Video video) {
    qDebug() << "Detection Sequential Images method";

    string mainWindowName = "Motion";
    string grayscaleWindowName = "Grayscale";

    Filter *grayscale = new GrayscaleFilter();
//    Frame grayFrame = grayscale->apply(Frame(cv::Mat()));

    while (true) {
        Frame originalFrame = video.nextFrame();
        bool isContinue = originalFrame.show(mainWindowName);

        Frame grayFrame = grayscale->apply(originalFrame);
        grayFrame.show(grayscaleWindowName);

        if (!isContinue)
            break;
    }

    Frame::destroyWindow(mainWindowName);
    Frame::destroyWindow(grayscaleWindowName);
}

SequentialImages::SequentialImages() {

}

SequentialImages::~SequentialImages() {

}


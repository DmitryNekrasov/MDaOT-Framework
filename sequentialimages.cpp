#include "sequentialimages.h"
#include "QDebug"

void SequentialImages::detect(Video video) {
    qDebug() << "Detection Sequential Images method";

    string mainWindowName = "Motion";

    while (true) {
        bool isContinue = video.nextFrame().show(mainWindowName);

        if (!isContinue)
            break;
    }

    Frame::destroyWindow(mainWindowName);
}

SequentialImages::SequentialImages()
{

}

SequentialImages::~SequentialImages()
{

}


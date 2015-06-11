#include "core.h"
#include <QDebug>

void Core::start() {
    qDebug() << "done!";

    Video video = Video(0);

    Detector detector = Detector();
    detector.setDetectionMethod(new SequentialImages());
    detector.execute(video);

    while (true) {

        bool isContinue = video.nextFrame().show("Motion");



        if (!isContinue)
            break;
    }

    Frame::destroyWindow("Motion");

}

Core::Core()
{

}

Core::~Core()
{

}


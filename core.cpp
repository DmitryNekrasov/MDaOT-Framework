#include "core.h"
#include <QDebug>

void Core::start() {
    qDebug() << "done!";

    Video video = Video(0);

    Detector detector = Detector();
    detector.setDetectionMethod(new SequentialImages());
    detector.execute(video);
}

Core::Core()
{

}

Core::~Core()
{

}


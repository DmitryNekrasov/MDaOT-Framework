#include "core.h"
#include <QDebug>

Core *Core::instance;

void Core::start() {

    Video video = Video(0);

    Detector detector = Detector();
    detector.setDetectionMethod(new SequentialImages());
    detector.execute(video);
}

Core::Core()
{

}

Core *Core::getInstance() {
    if (instance == NULL) {
        instance = new Core();
    }
    return instance;
}

Core::~Core()
{

}


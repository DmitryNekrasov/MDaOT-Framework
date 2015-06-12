#include "core.h"
#include <QDebug>

Core *Core::instance;

void Core::start() {

    Video video = Video("/Users/ScanNorOne/Downloads/2.mov");
    video.setWidth(540);
    video.setHeight(360);

    Detector detector = Detector();
    detector.setDetectionMethod(new SequentialImages());
    detector.execute(video);
}

Core::Core() {

}

Core *Core::getInstance() {
    if (instance == NULL) {
        instance = new Core();
    }
    return instance;
}

Core::~Core() {

}


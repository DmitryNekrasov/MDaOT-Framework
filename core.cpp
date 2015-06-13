#include "core.h"
#include <QDebug>

Core *Core::instance;

void Core::start() {

    Video video = Video("/Users/ScanNorOne/Downloads/3.mov");

    Detector detector = Detector();
//    detector.setDetectionMethod(new SequentialImages());
    detector.setDetectionMethod(new BackgroundSubtraction());
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

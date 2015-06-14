#include "core.h"
#include <QDebug>

Core *Core::instance;

void Core::start() {

    Video video = Video("/Users/ScanNorOne/Downloads/3.mov");
//    Video video = Video(0);

    Detector detector = Detector();
//    detector.setDetectionMethod(new SequentialImages(new MyMovenmentHandler()));
    detector.setDetectionMethod(new BackgroundSubtraction(new MyMovenmentHandler()));
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

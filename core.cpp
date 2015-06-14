#include "core.h"
#include <QDebug>

Core *Core::instance;

void Core::start() {

    Video video = Video("/Users/ScanNorOne/Downloads/3.mov");
//    Video video = Video(0);

    Detector detector = Detector();
    DetectionMethod *si = new SequentialImages(new MyMovenmentHandler());
    si->setRegion(new Rectangle(0, 0, 500, 500));
    detector.setDetectionMethod(si);
//    detector.setDetectionMethod(new BackgroundSubtraction(new MyMovenmentHandler()));
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

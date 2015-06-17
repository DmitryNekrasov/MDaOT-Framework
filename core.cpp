#include "core.h"
#include <QDebug>


Core *Core::instance;

void Core::start() {

//    Video video = Video("/Users/ScanNorOne/Desktop/s480.mp4");

//    Detector detector = Detector();

//    MovenmentHandler *myMH = new MyMovenmentHandler();
////    myMH->setWindow(window);
//    DetectionMethod *si = new SequentialImages(myMH);
////    si->setRegion(new Rectangle(0, 0, 500, 500));
//    detector.setDetectionMethod(si);

////    DetectionMethod *bs = new BackgroundSubtraction(myMH);
////    bs->setRegion(new Rectangle(500, 300, 500, 200));
////    detector.setDetectionMethod(bs);

//    detector.execute(video);
}

Core::Core(MainWindow *wnd) {
    this->window = wnd;
}

Core *Core::getInstance(MainWindow *wnd) {
    if (instance == NULL) {
        instance = new Core(wnd);
    }
    return instance;
}

Core::~Core() {

}

#include "detector.h"


void Detector::setDetectionMethod(DetectionMethod *detectionMethod) {
    this->detectionMethod = detectionMethod;
}

void Detector::execute(Video video) {
    detectionMethod->detect(video);
}

void Detector::startDetector()
{
    detectionMethod->init();
}

Detector::Detector() {

}

Detector::~Detector() {

}


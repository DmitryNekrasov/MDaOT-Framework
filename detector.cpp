#include "detector.h"


void Detector::setDetectionMethod(DetectionMethod *detectionMethod) {
    this->detectionMethod = detectionMethod;
}

void Detector::execute(Video video) {
    detectionMethod->detect(video);
}

Detector::Detector() {

}

Detector::~Detector() {

}


#include "detector.h"


void Detector::setDetectionMethod(DetectionMethod *detectionMethod) {
    this->detectionMethod = detectionMethod;
}

DetectionMethod *Detector::getDetectionMethod()
{
    return detectionMethod;
}

void Detector::execute(Video video) {
    detectionMethod->detect(video);
}

void Detector::startDetector(Video video)
{
    detectionMethod->init(video);
}

Detector::Detector() {

}

Detector::~Detector() {

}


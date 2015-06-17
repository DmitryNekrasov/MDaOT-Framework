#include "detectionmethod.h"
#include "QDebug"


DetectionMethod::~DetectionMethod() {

}

void DetectionMethod::performOnMove(Frame frame) {
    movenmentHandler->onMove(frame);
}

void DetectionMethod::setRegion(Rectangle *region) {
    this->region = region;
}

FilterChain *DetectionMethod::getFilterChain()
{
    return &filterChain;
}

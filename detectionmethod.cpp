#include "detectionmethod.h"


DetectionMethod::~DetectionMethod() {

}

void DetectionMethod::performOnMove(Frame frame) {
    movenmentHandler->onMove(frame);
}


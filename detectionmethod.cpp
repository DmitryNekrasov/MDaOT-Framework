#include "detectionmethod.h"
#include "QDebug"


void DetectionMethod::performOnMove(Frame frame, vector<Rectangle> *rectangles, vector<Point> *mask)
{
    movenmentHandler->onMove(frame, rectangles, mask);
}

void DetectionMethod::setRegion(Rectangle *region)
{
    this->region = region;
}

FilterChain *DetectionMethod::getFilterChain()
{
    return &filterChain;
}

void DetectionMethod::setFilterChain(FilterChain chain)
{
    filterChain = chain;
}

DetectionMethod::~DetectionMethod()
{

}

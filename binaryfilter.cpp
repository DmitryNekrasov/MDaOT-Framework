#include "binaryfilter.h"
#include "QDebug"


Frame BinaryFilter::apply(Frame originalFrame)
{
    cv::Mat thresholdMat;
    cv::Mat originalMat = originalFrame.getCvMat();
    cv::threshold(originalMat, thresholdMat, threshold, 255, cv::THRESH_BINARY);
    Frame result = Frame(thresholdMat);

    if (filterHandler != NULL) {
        performApplyFilter(result);
    }

    return result;
}

int BinaryFilter::getThreshold()
{
    return threshold;
}

void BinaryFilter::setThreshold(int threshold)
{
    this->threshold = threshold;
}

BinaryFilter::BinaryFilter(int threshold, FilterHandler *handler)
{
    this->threshold = threshold;
    filterHandler = handler;
    name = "Binary";
}

BinaryFilter::BinaryFilter(int threshold)
{
    this->threshold = threshold;
    filterHandler = NULL;
    name = "Binary";
}

BinaryFilter::~BinaryFilter()
{

}

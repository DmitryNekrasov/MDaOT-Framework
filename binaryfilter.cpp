#include "binaryfilter.h"

Frame BinaryFilter::apply(Frame originalFrame) {
    cv::Mat thresholdMat;
    cv::Mat originalMat = originalFrame.getCvMat();
    cv::threshold(originalMat, thresholdMat, threshold, 255, cv::THRESH_BINARY);
    return Frame(thresholdMat);
}

BinaryFilter::BinaryFilter(int threshold) {
    this->threshold = threshold;
}

BinaryFilter::~BinaryFilter() {

}

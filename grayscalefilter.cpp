#include "grayscalefilter.h"
#include "QDebug"

Frame GrayscaleFilter::apply(Frame originalFrame) {
    cv::Mat grayMat;
    cv::Mat originalMat = originalFrame.getCvMat();
    cv::cvtColor(originalMat, grayMat, CV_BGR2GRAY);
    return Frame(grayMat);
}

GrayscaleFilter::GrayscaleFilter() {

}

GrayscaleFilter::~GrayscaleFilter() {

}


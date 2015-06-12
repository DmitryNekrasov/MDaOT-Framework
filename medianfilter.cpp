#include "medianfilter.h"

Frame MedianFilter::apply(Frame originalFrame) {
    cv::Mat medianMat;
    cv::Mat originalMat = originalFrame.getCvMat();
    cv::medianBlur(originalMat, medianMat, size);
    return Frame(medianMat);
}

int MedianFilter::getSize() {
    return size;
}

void MedianFilter::setSize(int size) {
    this->size = size;
}

MedianFilter::MedianFilter(int size) {
    this->size = size;
}

MedianFilter::~MedianFilter() {

}


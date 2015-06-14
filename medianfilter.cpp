#include "medianfilter.h"

Frame MedianFilter::apply(Frame originalFrame) {
    cv::Mat medianMat;
    cv::Mat originalMat = originalFrame.getCvMat();
    cv::medianBlur(originalMat, medianMat, size);
    Frame result = Frame(medianMat);

    if (filterHandler != NULL) {
        performApplyFilter(result);
    }

    return result;
}

int MedianFilter::getSize() {
    return size;
}

void MedianFilter::setSize(int size) {
    this->size = size;
}

MedianFilter::MedianFilter(int size) {
    this->size = size;
    filterHandler = NULL;
}

MedianFilter::MedianFilter(int size, FilterHandler *handler) {
    this->size = size;
    filterHandler = handler;
}

MedianFilter::~MedianFilter() {

}


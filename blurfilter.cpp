#include "blurfilter.h"

Frame BlurFilter::apply(Frame originalFrame) {
    cv::Mat blurMat;
    cv::Mat originalMat = originalFrame.getCvMat();
    cv::blur(originalMat, blurMat, cv::Size(widthBlur, heightBlur));
    return Frame(blurMat);
}

int BlurFilter::getWidthBlur() {
    return widthBlur;
}

void BlurFilter::setWidthBlur(int widthBlur) {
    this->widthBlur = widthBlur;
}

int BlurFilter::getHeightBlur() {
    return heightBlur;
}

void BlurFilter::setHeightBlur(int heightBlur) {
    this->heightBlur = heightBlur;
}

BlurFilter::BlurFilter(int widthBlur, int heightBlur) {
    this->widthBlur = widthBlur;
    this->heightBlur = heightBlur;
}

BlurFilter::~BlurFilter() {

}


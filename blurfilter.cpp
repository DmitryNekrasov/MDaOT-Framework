#include "blurfilter.h"

Frame BlurFilter::apply(Frame originalFrame) {
    cv::Mat blurMat;
    cv::Mat originalMat = originalFrame.getCvMat();
    cv::blur(originalMat, blurMat, cv::Size(widthBlur, heightBlur));
    return Frame(blurMat);
}

BlurFilter::BlurFilter(int widthBlur, int heightBlur) {
    this->widthBlur = widthBlur;
    this->heightBlur = heightBlur;
}

BlurFilter::~BlurFilter() {

}


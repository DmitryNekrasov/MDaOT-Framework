#include "blurfilter.h"


Frame BlurFilter::apply(Frame originalFrame)
{
    cv::Mat blurMat;
    cv::Mat originalMat = originalFrame.getCvMat();
    cv::blur(originalMat, blurMat, cv::Size(widthBlur, heightBlur));
    Frame result = Frame(blurMat);

    if (filterHandler != NULL) {
        performApplyFilter(result);
    }

    return result;
}

int BlurFilter::getWidthBlur()
{
    return widthBlur;
}

void BlurFilter::setWidthBlur(int widthBlur)
{
    this->widthBlur = widthBlur;
}

int BlurFilter::getHeightBlur()
{
    return heightBlur;
}

void BlurFilter::setHeightBlur(int heightBlur)
{
    this->heightBlur = heightBlur;
}

BlurFilter::BlurFilter(int widthBlur, int heightBlur)
{
    this->widthBlur = widthBlur;
    this->heightBlur = heightBlur;
    filterHandler = NULL;
    name = "Blur";
}

BlurFilter::BlurFilter(int widthBlur, int heightBlur, FilterHandler *handler)
{
    this->widthBlur = widthBlur;
    this->heightBlur = heightBlur;
    filterHandler = handler;
    name = "Blur";
}

BlurFilter::~BlurFilter()
{

}

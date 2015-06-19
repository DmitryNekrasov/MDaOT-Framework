#include "grayscalefilter.h"
#include "QDebug"

Frame GrayscaleFilter::apply(Frame originalFrame)
{
    cv::Mat grayMat;
    cv::Mat originalMat = originalFrame.getCvMat();
    cv::cvtColor(originalMat, grayMat, CV_BGR2GRAY);

    Frame result = Frame(grayMat);

    if (filterHandler != NULL) {
        performApplyFilter(result);
    }

    return result;
}

GrayscaleFilter::GrayscaleFilter()
{
    filterHandler = NULL;
    name = "Grayscale";
}

GrayscaleFilter::GrayscaleFilter(FilterHandler *handler)
{
    filterHandler = handler;
    name = "Grayscale";
}

GrayscaleFilter::~GrayscaleFilter()
{

}


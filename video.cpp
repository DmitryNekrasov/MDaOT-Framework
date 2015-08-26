#include "video.h"


Frame Video::nextFrame()
{
    cv::Mat next;
    capture >> next;
    return Frame(next);
}

Video::Video()
{

}

void Video::setWidth(int width)
{
    capture.set(CV_CAP_PROP_FRAME_WIDTH, width);
}

void Video::setHeight(int height)
{
    capture.set(CV_CAP_PROP_FRAME_HEIGHT, height);
}

bool Video::hasNext()
{
    if (isFileOpen)
        return capture.get(CV_CAP_PROP_POS_FRAMES) < capture.get(CV_CAP_PROP_FRAME_COUNT) - 1;
    return true;
}

Video::Video(int device)
{
    capture = cv::VideoCapture(device);
    isFileOpen = false;
}

Video::Video(std::string filePath)
{
    capture = cv::VideoCapture(filePath);
    isFileOpen = true;
}

Video::~Video()
{

}

#include "video.h"

Frame Video::nextFrame() {
    cv::Mat next;
    capture >> next;
    return Frame(next);
}

Video::Video(int device) {
    capture = cv::VideoCapture(device);
}

Video::~Video()
{

}


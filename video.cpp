#include "video.h"

Frame Video::nextFrame() {
    cv::Mat next;
    capture >> next;
    return Frame(next);
}

void Video::setWidth(int width) {
    capture.set(CV_CAP_PROP_FRAME_WIDTH, width);
}

void Video::setHeight(int height) {
    capture.set(CV_CAP_PROP_FRAME_HEIGHT, height);
}

Video::Video(int device) {
    capture = cv::VideoCapture(device);
}

Video::~Video() {

}


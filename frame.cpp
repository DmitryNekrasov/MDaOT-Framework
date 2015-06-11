#include "frame.h"

bool Frame::show(string windowFrame) {
    cv::imshow(windowFrame, mat);
    int keyCode = cv::waitKey(10);
    return keyCode < 0;
}

void Frame::destroyWindow(string windowName) {
    cv::destroyWindow(windowName);
}

Frame::Frame(cv::Mat mat) {
    this->mat = mat;
}

Frame::~Frame() {

}


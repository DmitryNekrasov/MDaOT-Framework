#include "frame.h"

bool Frame::show(string windowFrame) {
    cv::imshow(windowFrame, mat);
    int keyCode = cv::waitKey(10);
    return keyCode < 0;
}

void Frame::destroyWindow(string windowName) {
    cv::destroyWindow(windowName);
}

cv::Mat Frame::getCvMat() {
    return mat;
}

Frame Frame::difference(Frame frame1, Frame frame2) {
    cv::Mat mat1 = frame1.getCvMat();
    cv::Mat mat2 = frame2.getCvMat();
    cv::Mat resultMat;
    cv::absdiff(mat1, mat2, resultMat);
    return Frame(resultMat);
}

Frame::Frame(cv::Mat mat) {
    this->mat = mat;
}

Frame::Frame() {

}

Frame::~Frame() {

}


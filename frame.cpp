#include "frame.h"
#include "QDebug"
#include <QtGui>

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

vector<Rectangle> Frame::searchForMovement(cv::Mat thresholdImage, cv::Mat cameraFeed) {
    bool objectDetected = false;
    cv::Mat temp;
    thresholdImage.copyTo(temp);

    vector< vector<cv::Point> > contours;
    vector<cv::Vec4i> hierarchy;

    cv::findContours(temp, contours, hierarchy, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_SIMPLE);

    if (contours.size() > 0) {
        objectDetected = true;
    } else {
        objectDetected = false;
    }

    cv::Rect objectBoundingRectangle = cv::Rect(0, 0, 0, 0);

    vector<Rectangle> rectangles;

    if (objectDetected) {
        vector< vector<cv::Point> > largestContourVec;
        largestContourVec.push_back(contours.at(0));

        objectBoundingRectangle = cv::boundingRect(largestContourVec.at(0));

        rectangles.push_back(Rectangle(objectBoundingRectangle));
    }

    return rectangles;
}

void Frame::drawRectangle(Rectangle rectangle) {
    cv::rectangle(mat, rectangle.getCvRect(), cv::Scalar(255, 0, 0), 3);
}

QImage Frame::toQImage() {
    cv::Mat temp(mat.cols, mat.rows, mat.type());
    cvtColor(mat, temp, CV_BGR2RGB);
    QImage dest = QImage((uchar*) temp.data, temp.cols, temp.rows, temp.step, QImage::Format_RGBA8888);
    return dest;
}

Frame::Frame(cv::Mat mat) {
    this->mat = mat;
}

Frame::Frame() {

}

Frame::~Frame() {

}


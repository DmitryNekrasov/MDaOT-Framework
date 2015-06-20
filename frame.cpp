#include "frame.h"
#include "QDebug"
#include <QImage>


bool Frame::show(string windowFrame)
{
    cv::imshow(windowFrame, mat);
    int keyCode = cv::waitKey(10);
    return keyCode < 0;
}

void Frame::destroyWindow(string windowName)
{
    cv::destroyWindow(windowName);
}

cv::Mat Frame::getCvMat()
{
    return mat;
}

Frame Frame::difference(Frame frame1, Frame frame2)
{
    cv::Mat mat1 = frame1.getCvMat();
    cv::Mat mat2 = frame2.getCvMat();
    cv::Mat resultMat;
    cv::absdiff(mat1, mat2, resultMat);
    return Frame(resultMat);
}

vector<Rectangle> Frame::searchForMovement(cv::Mat thresholdImage, vector<Point> *points)
{
    points->clear();

    bool objectDetected = false;
    cv::Mat temp;
    thresholdImage.copyTo(temp);

    vector< vector<cv::Point> > contours;  // контуры оьнаруженных объектов
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

        // запомнить точки маски
        for (vector< vector<cv::Point> >::iterator i = contours.begin(); i != contours.end(); i++) {
            vector<cv::Point> pt = *i;
            for (vector<cv::Point>::iterator j = pt.begin(); j != pt.end(); j++){
                cv::Point cvPoint = *j;
                Point point = Point(cvPoint);
                points->push_back(point);
            }
        }

        vector< vector<cv::Point> > largestContourVec;

        for (int i = 0; i < contours.size(); i++) {
            largestContourVec.push_back(contours.at(i));
        }

        for (int i = 0; i < contours.size(); i++) {
            objectBoundingRectangle = cv::boundingRect(largestContourVec.at(i));
            rectangles.push_back(Rectangle(objectBoundingRectangle));
        }
    }

    return rectangles;
}

void Frame::drawRectangle(Rectangle rectangle)
{
    cv::rectangle(mat, rectangle.getCvRect(), cv::Scalar(255, 0, 0), 3);
}

void Frame::drawPoint(Point point)
{
    cv::Rect rec = cv::Rect(point.getX(), point.getY(), 1, 1);
    cv::rectangle(mat, rec, cv::Scalar(0, 0, 255), 3);
}

QImage Frame::toQImage()
{
    cv::cvtColor(mat, mat, CV_BGR2RGB);
    QImage qimg((uchar*)mat.data, mat.cols, mat.rows, mat.step, QImage::Format_RGB888);
    return qimg;
}

QImage Frame::filterToQImage()
{
    cv::cvtColor(mat, mat, CV_GRAY2RGB);
    QImage qimg((uchar*)mat.data, mat.cols, mat.rows, mat.step, QImage::Format_RGB888);
    return qimg;
}

Frame::Frame(cv::Mat mat)
{
    this->mat = mat;
}

Frame::Frame()
{

}

Frame::~Frame()
{

}

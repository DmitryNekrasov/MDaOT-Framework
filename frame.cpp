#include "frame.h"
#include "QDebug"
#include <QImage>


bool Frame::show(std::string _window_name)
{
    cv::imshow(_window_name, m_Mat);
    int keyCode = cv::waitKey(10);
    return keyCode < 0;
}

void Frame::destroyWindow(std::string _window_name)
{
    cv::destroyWindow(_window_name);
}

cv::Mat Frame::getCvMat()
{
    return m_Mat;
}

int Frame::getWidth()
{
    return m_Mat.cols;
}

int Frame::getHeight()
{
    return m_Mat.rows;
}

Frame Frame::difference(Frame _frame1, Frame _frame2)
{
    cv::Mat mat1 = _frame1.getCvMat();
    cv::Mat mat2 = _frame2.getCvMat();
    cv::Mat resultMat;
    cv::absdiff(mat1, mat2, resultMat);
    return Frame(resultMat);
}

std::vector<Rectangle> Frame::searchForMovement(cv::Mat _thresholdImage, std::vector<Point>* _points)
{
    _points->clear();

    bool objectDetected = false;
    cv::Mat temp;
    _thresholdImage.copyTo(temp);

    std::vector< std::vector<cv::Point> > contours;  // контуры обнаруженных объектов
    std::vector<cv::Vec4i> hierarchy;

    cv::findContours(temp, contours, hierarchy, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_SIMPLE);

    if (contours.size() > 0) {
        objectDetected = true;
    } else {
        objectDetected = false;
    }

    cv::Rect objectBoundingRectangle = cv::Rect(0, 0, 0, 0);

    std::vector<Rectangle> rectangles;

    if (objectDetected) {

        // запомнить точки маски
        for (auto point_vector : contours) {
            for (auto cv_point : point_vector) {
                Point point(cv_point);
                _points->push_back(point);
            }
        }

        std::vector< std::vector<cv::Point> > largestContourVec;

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

void Frame::drawRectangle(Rectangle _rectangle)
{
    cv::rectangle(m_Mat, _rectangle.getCvRect(), cv::Scalar(255, 0, 0), 3);
}

void Frame::drawPoint(Point _point)
{
    cv::Rect rec = cv::Rect(_point.getX(), _point.getY(), 1, 1);
    cv::rectangle(m_Mat, rec, cv::Scalar(0, 0, 255), 3);
}

QImage Frame::toQImage()
{
    cv::cvtColor(m_Mat, m_Mat, CV_BGR2RGB);
    QImage qimg((uchar*)m_Mat.data, m_Mat.cols, m_Mat.rows, m_Mat.step, QImage::Format_RGB888);
    return qimg;
}

QImage Frame::filterToQImage()
{
    cv::cvtColor(m_Mat, m_Mat, CV_GRAY2RGB);
    QImage qimg((uchar*)m_Mat.data, m_Mat.cols, m_Mat.rows, m_Mat.step, QImage::Format_RGB888);
    return qimg;
}

void Frame::putText(std::string _text, Point _point)
{
    cv::putText(m_Mat, _text, _point.getCvPoint(), 1, 1, cv::Scalar(0, 255, 0), 2);
}

Frame::Frame(cv::Mat _mat)
{
    m_Mat = _mat;
}

Frame::Frame()
{

}

Frame::~Frame()
{

}

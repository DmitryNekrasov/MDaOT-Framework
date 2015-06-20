#include "point.h"
#include "qdebug.h"


cv::Point Point::getCvPoint()
{
    return cvPoint;
}

int Point::getX()
{
    return cvPoint.x;
}

int Point::getY()
{
    return cvPoint.y;
}

Point::Point()
{

}

Point::Point(cv::Point point)
{
    this->cvPoint = point;
}

Point::~Point()
{

}

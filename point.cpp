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

int Point::getDistance(Point p1, Point p2)
{
    return abs(p1.getY() - p2.getY());
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

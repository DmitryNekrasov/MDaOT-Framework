#include "point.h"

cv::Point Point::getCvPoint()
{
    return cvPoint;
}

Point::Point()
{

}

Point::Point(cv::Point point)
{
    cvPoint = point;
}

Point::~Point()
{

}


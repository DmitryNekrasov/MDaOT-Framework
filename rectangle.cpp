#include "rectangle.h"


cv::Rect Rectangle::getCvRect()
{
    return myRect;
}

int Rectangle::getArea()
{
    return myRect.area();
}

int Rectangle::getLeftBottomCornerX()
{
    return myRect.y + myRect.height;
}

int Rectangle::getLeftBottomCornerY()
{
    return myRect.x;
}

Point Rectangle::getCenterPoint()
{
    int x = myRect.x + myRect.width / 2;
    int y = myRect.y + myRect.height / 2;
    cv::Point p = cv::Point(x, y);
    return Point(p);
}

Rectangle::Rectangle(int x, int y, int width, int height)
{
    myRect = cv::Rect(x, y, width, height);
}

Rectangle::Rectangle(cv::Rect cvRect)
{
    myRect = cvRect;
}

Rectangle::~Rectangle()
{

}

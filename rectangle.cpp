#include "rectangle.h"


cv::Rect Rectangle::getCvRect()
{
    return myRect;
}

int Rectangle::getArea()
{
    return myRect.area();
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


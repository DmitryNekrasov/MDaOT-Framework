#ifndef RECTANGLE_H
#define RECTANGLE_H
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/video/tracking.hpp>
#include <opencv2/imgproc/imgproc_c.h>
#include <opencv2/opencv.hpp>

class Rectangle
{

    cv::Rect myRect;

public:
    Rectangle(int x, int y, int width, int height);
    ~Rectangle();
};

#endif // RECTANGLE_H

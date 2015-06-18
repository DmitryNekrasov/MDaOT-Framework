#ifndef POINT_H
#define POINT_H
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/video/tracking.hpp>
#include <opencv2/imgproc/imgproc_c.h>
#include <opencv2/opencv.hpp>

class Point
{
private:
    cv::Point cvPoint;
public:

    cv::Point getCvPoint();
    int getX();
    int getY();

    Point();
    Point(cv::Point point);
    ~Point();
};

#endif // POINT_H

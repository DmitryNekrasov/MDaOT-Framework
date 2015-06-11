#ifndef VIDEO_H
#define VIDEO_H
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/video/tracking.hpp>
#include <opencv2/imgproc/imgproc_c.h>
#include <opencv2/opencv.hpp>
#include "frame.h"

class Video
{
private:
    cv::VideoCapture capture;

public:

    void setWidth(int width);
    void setHeight(int height);
    Frame nextFrame();

    Video(int device);
    Video(string filePath);
    ~Video();
};

#endif // VIDEO_H

#ifndef FRAME_H
#define FRAME_H
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/video/tracking.hpp>
#include <opencv2/imgproc/imgproc_c.h>
#include <opencv2/opencv.hpp>
#include <string>

using namespace std;



class Frame
{
private:
    cv::Mat mat;

public:

    bool show(string windowName);
    static void destroyWindow(string windowName);

    Frame(cv::Mat mat);
    ~Frame();
};



#endif // FRAME_H

#ifndef FRAME_H
#define FRAME_H
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/video/tracking.hpp>
#include <opencv2/imgproc/imgproc_c.h>
#include <opencv2/opencv.hpp>
#include <string>
#include "rectangle.h"
#include "point.h"
#include <QApplication>


using namespace std;

class Frame
{
private:
    cv::Mat mat;

public:

    bool show(string windowName);
    static void destroyWindow(string windowName);
    cv::Mat getCvMat();
    static Frame difference(Frame frame1, Frame frame2);
    static vector<Rectangle> searchForMovement(cv::Mat thresholdImage, vector<Point> *points);
    void drawRectangle(Rectangle rectangle);
    void drawPoint(Point point);
    QImage toQImage();
    QImage filterToQImage();

    Frame(cv::Mat mat);
    Frame();
    ~Frame();
};

#endif // FRAME_H

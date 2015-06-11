#include "video.h"

Video::Video(int device) {
    capture = cv::VideoCapture(device);
}

Video::~Video()
{

}


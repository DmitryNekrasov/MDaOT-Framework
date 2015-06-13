#include "rectangle.h"


Rectangle::Rectangle(int x, int y, int width, int height) {
    myRect = cv::Rect(x, y, width, height);
}

Rectangle::~Rectangle() {

}


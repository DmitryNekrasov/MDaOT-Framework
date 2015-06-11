#include "sequentialimages.h"
#include "QDebug"

void SequentialImages::detect(Video video) {
    qDebug() << "Detection Sequential Images method";

    string mainWindowName = "Motion";
    string grayscaleWindowName = "Grayscale";
    string binaryWindowName = "Binary";
    string blurWindowName = "Blur";
    string blurBinaryWindowName = "Blur binary";

    Filter *grayscaleFilter = new GrayscaleFilter();
    Filter *binaryFilter = new BinaryFilter(20);
    Filter *blurFilter = new BlurFilter(7, 7);

    while (true) {
        Frame originalFrame1 = video.nextFrame();
        bool isContinue = originalFrame1.show(mainWindowName);
        Frame grayFrame1 = grayscaleFilter->apply(originalFrame1);

        Frame originalFrame2 = video.nextFrame();
        Frame grayFrame2 = grayscaleFilter->apply(originalFrame2);

        Frame diffFrame = Frame::difference(grayFrame1, grayFrame2);

        Frame binaryFrame = binaryFilter->apply(diffFrame);
//        binaryFrame.show(binaryWindowName);

        Frame blurFrame = blurFilter->apply(binaryFrame);
//        blurFrame.show(blurWindowName);

        Frame blurBinaryFrame = binaryFilter->apply(blurFrame);
//        blurBinaryFrame.show(blurBinaryWindowName);

        searchForMovement(blurBinaryFrame.getCvMat(), originalFrame1.getCvMat());

        if (!isContinue)
            break;
    }


    Frame::destroyWindow(mainWindowName);
    Frame::destroyWindow(grayscaleWindowName);
    Frame::destroyWindow(binaryWindowName);
    Frame::destroyWindow(blurWindowName);
    Frame::destroyWindow(blurBinaryWindowName);
}


cv::Rect objectBoundingRectangle = cv::Rect(0,0,0,0);

void SequentialImages::searchForMovement(cv::Mat thresholdImage, cv::Mat cameraFeed) {

    bool objectDetected = false;
    cv::Mat temp;
    thresholdImage.copyTo(temp);

    vector< vector<cv::Point> > contours;
    vector<cv::Vec4i> hierarchy;

    cv::findContours(temp, contours, hierarchy, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_SIMPLE);

    if (contours.size() > 0) {
        objectDetected = true;
    } else {
        objectDetected = false;
//        points.clear();
    }

    if (objectDetected) {
        vector< vector<cv::Point> > largestContourVec;
        largestContourVec.push_back(contours.at(contours.size()-1));

//        qDebug() << largestContourVec.size();

        objectBoundingRectangle = cv::boundingRect(largestContourVec.at(0));
        int x = objectBoundingRectangle.x + objectBoundingRectangle.width / 2;
        int y = objectBoundingRectangle.y + objectBoundingRectangle.height / 2;
        cv::circle(cameraFeed, cv::Point(x,y), 20, cv::Scalar(0, 255, 0), 3);

//        points.push_back(cv::Point(x, y));

//        for (int i = 0; i < points.size() - 1; i++) {
//            cv::line(cameraFeed, points.at(i), points.at(i + 1), cv::Scalar(0, 0, 255), 3);
//        }
    }

    cv::imshow("qqq", cameraFeed);
}

SequentialImages::SequentialImages() {

}

SequentialImages::~SequentialImages() {

}


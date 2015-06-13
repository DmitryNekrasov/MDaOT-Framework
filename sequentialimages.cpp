#include "sequentialimages.h"


void SequentialImages::detect(Video video) {
    qDebug() << "Detection Sequential Images method";

    string mainWindowName = "Motion";

    Filter *grayscaleFilter = new GrayscaleFilter();
    Filter *binaryFilter = new BinaryFilter(20);
    Filter *blurFilter = new BlurFilter(7, 7);

    filterChain.add(binaryFilter);
    filterChain.add(blurFilter);
    filterChain.add(binaryFilter);

    Frame originalFrame1, grayFrame1, originalFrame2, grayFrame2, diffFrame, blurBinaryFrame;

    while (video.hasNext()) {
        originalFrame1 = video.nextFrame();
        bool isContinue = originalFrame1.show(mainWindowName);
        grayFrame1 = grayscaleFilter->apply(originalFrame1);

        originalFrame2 = video.nextFrame();
        grayFrame2 = grayscaleFilter->apply(originalFrame2);

        diffFrame = Frame::difference(grayFrame1, grayFrame2);

        blurBinaryFrame = filterChain.apply(diffFrame);

        searchForMovement(blurBinaryFrame.getCvMat(), originalFrame1.getCvMat());

        if (!isContinue)
            break;
    }


    Frame::destroyWindow(mainWindowName);
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
    }

    if (objectDetected) {
        vector< vector<cv::Point> > largestContourVec;
        largestContourVec.push_back(contours.at(contours.size()-1));

        objectBoundingRectangle = cv::boundingRect(largestContourVec.at(0));
        int x = objectBoundingRectangle.x + objectBoundingRectangle.width / 2;
        int y = objectBoundingRectangle.y + objectBoundingRectangle.height / 2;
//        cv::circle(cameraFeed, cv::Point(x,y), 20, cv::Scalar(0, 255, 0), 3);
        cv::rectangle(cameraFeed, objectBoundingRectangle, cv::Scalar(255, 0, 0), 3);

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


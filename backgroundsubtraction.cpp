#include "backgroundsubtraction.h"

void BackgroundSubtraction::detect(Video video) {
    qDebug() << "Detection Sequential Images method";

    cv::Ptr<cv::BackgroundSubtractor> pMOG, pMOG2;

    pMOG= new cv::BackgroundSubtractorMOG();
    pMOG2 = new cv::BackgroundSubtractorMOG2();

    Frame frame, outFrame;
    cv::Mat cvFrame;
    cv::Mat fgMaskMOG;
    cv::Mat fgMaskMOG2;

    Filter *blur = new BlurFilter(15, 15);
    Filter *binary = new BinaryFilter(10);
    Filter *median = new MedianFilter(5);

    filterChain.add(blur);
    filterChain.add(binary);

    vector<Rectangle> rectangles;

    while (video.hasNext()) {
        frame = video.nextFrame();

        cvFrame = frame.getCvMat();

        pMOG->operator()(cvFrame, fgMaskMOG);
        pMOG2->operator()(cvFrame, fgMaskMOG2);

//        imshow("FG Mask MOG", fgMaskMOG);
//        imshow("FG Mask MOG 2", fgMaskMOG2);

        outFrame = filterChain.apply(Frame(fgMaskMOG));
        outFrame.show("outFrame");

        rectangles = Frame::searchForMovement(outFrame.getCvMat(), cvFrame);

        frame.drawRectangle(rectangles.at(0));

        bool isContinue = frame.show("Motion");
        if (!isContinue)
            break;
    }

    Frame::destroyWindow("Motion");
    Frame::destroyWindow("outFrame");
}

BackgroundSubtraction::BackgroundSubtraction() {

}

BackgroundSubtraction::~BackgroundSubtraction() {

}


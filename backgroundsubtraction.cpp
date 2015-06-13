#include "backgroundsubtraction.h"

void BackgroundSubtraction::detect(Video video) {
    qDebug() << "Detection Sequential Images method";

    cv::Ptr<cv::BackgroundSubtractor> pMOG, pMOG2;

    pMOG= new cv::BackgroundSubtractorMOG();
    pMOG2 = new cv::BackgroundSubtractorMOG2();

    Frame frame;
    cv::Mat cvFrame;
    cv::Mat fgMaskMOG;
    cv::Mat fgMaskMOG2;

    while (video.hasNext()) {
        frame = video.nextFrame();
        bool isContinue = frame.show("Motion");

        cvFrame = frame.getCvMat();

        pMOG->operator()(cvFrame, fgMaskMOG);
        pMOG2->operator()(cvFrame, fgMaskMOG2);

        imshow("FG Mask MOG", fgMaskMOG);
        imshow("FG Mask MOG 2", fgMaskMOG2);

        if (!isContinue)
            break;
    }

    Frame::destroyWindow("Motion");

}

BackgroundSubtraction::BackgroundSubtraction()
{

}

BackgroundSubtraction::~BackgroundSubtraction()
{

}


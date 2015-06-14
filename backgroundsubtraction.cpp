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
    Filter *binary = new BinaryFilter(1);
    Filter *median = new MedianFilter(5);

    filterChain.add(blur);
    filterChain.add(binary);
    filterChain.add(blur);
    filterChain.add(binary);

    vector<Rectangle> rectangles;

    while (video.hasNext()) {
        frame = video.nextFrame();

        cvFrame = frame.getCvMat();

        pMOG->operator()(cvFrame, fgMaskMOG);
        pMOG2->operator()(cvFrame, fgMaskMOG2);

        outFrame = filterChain.apply(Frame(fgMaskMOG));
//        outFrame.show("outFrame");

        rectangles = Frame::searchForMovement(outFrame.getCvMat(), cvFrame);

        if (movenmentHandler != NULL) {
            if (!rectangles.empty()) {
                performOnMove(Frame(cvFrame(rectangles.at(0).getCvRect())));
            }
        }

        if (!rectangles.empty())
            frame.drawRectangle(rectangles.at(0));

        bool isContinue = frame.show("Motion");
        if (!isContinue)
            break;
    }

    Frame::destroyWindow("Motion");
    Frame::destroyWindow("outFrame");
}

BackgroundSubtraction::BackgroundSubtraction() {
    movenmentHandler = NULL;
}

BackgroundSubtraction::BackgroundSubtraction(MovenmentHandler *handler) {
    movenmentHandler = handler;
}

BackgroundSubtraction::~BackgroundSubtraction() {

}


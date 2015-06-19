#include "backgroundsubtraction.h"
#include "point.h"

void BackgroundSubtraction::detect(Video video)
{
    qDebug() << "Detection Background Subtraction method";

    cv::Ptr<cv::BackgroundSubtractor> pMOG, pMOG2;

    pMOG= new cv::BackgroundSubtractorMOG();
    pMOG2 = new cv::BackgroundSubtractorMOG2();

    Frame frame, outFrame;
    cv::Mat cvFrame;
    cv::Mat fgMaskMOG;
    cv::Mat fgMaskMOG2;

    Filter *blur = new BlurFilter(15, 15);
    Filter *binary = new BinaryFilter(1);
    Filter *median = new MedianFilter(5, new OutMedianFH());

    filterChain.add(median);
    filterChain.add(blur);
    filterChain.add(binary);
    filterChain.add(blur);
    filterChain.add(binary);

    while (video.hasNext()) {
        frame = video.nextFrame();

        if (region != NULL) {
            frame = Frame(frame.getCvMat()(region->getCvRect()));
        }

        cvFrame = frame.getCvMat();

        pMOG->operator()(cvFrame, fgMaskMOG);
        pMOG2->operator()(cvFrame, fgMaskMOG2);

        outFrame = filterChain.apply(Frame(fgMaskMOG));

        vector<Point> *mask;
        moveObjectRectangles = Frame::searchForMovement(outFrame.getCvMat(), mask);

        if (!moveObjectRectangles.empty())
            frame.drawRectangle(moveObjectRectangles.at(0));

        bool isContinue = frame.show("Motion");
        if (!isContinue)
            break;
    }

    Frame::destroyWindow("Motion");
    Frame::destroyWindow("outFrame");
}

BackgroundSubtraction::BackgroundSubtraction()
{
    movenmentHandler = NULL;
    region = NULL;
}

BackgroundSubtraction::BackgroundSubtraction(MovenmentHandler *handler)
{
    movenmentHandler = handler;
    region = NULL;
}

BackgroundSubtraction::~BackgroundSubtraction()
{

}


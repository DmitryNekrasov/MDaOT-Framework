#include "mybackgroundsubtraction.h"

void MyBackgroundSubtraction::detect(Video video)
{
    Frame frame = video.nextFrame();
    Frame grayFrame = grayscaleFilter->apply(frame);

    Frame diff = Frame::difference(grayFrame, background);

    Frame finalFrame = filterChain.apply(diff);

    vector<Point> mask;
    moveObjectRectangles = Frame::searchForMovement(finalFrame.getCvMat(), &mask);

    if (movenmentHandler != NULL) {
        performOnMove(frame, &moveObjectRectangles, &mask);
    }
}

void MyBackgroundSubtraction::init(Video video)
{
    qDebug() << "Detection Background Subtraction method";

    if (filterChain.getCount() == 0) {

        // инициализация фона
        Frame frame = video.nextFrame();
        grayscaleFilter = new GrayscaleFilter();
        background = grayscaleFilter->apply(frame);

        // фильтры
        Filter *binary = new BinaryFilter(20);
        Filter *median = new MedianFilter(5);
        Filter *blur = new BlurFilter(5, 5);
        Filter *finalBinary = new BinaryFilter(15);

        // добавляем фильтры в цепочку
        filterChain.add(binary);
        filterChain.add(median);
        filterChain.add(blur);
        filterChain.add(finalBinary);
    }
}

MyBackgroundSubtraction::MyBackgroundSubtraction()
{

}

MyBackgroundSubtraction::MyBackgroundSubtraction(MovenmentHandler *handler)
{
    movenmentHandler = handler;
}

MyBackgroundSubtraction::~MyBackgroundSubtraction()
{

}


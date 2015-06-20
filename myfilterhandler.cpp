#include "myfilterhandler.h"
#include "QDebug"
#include "QImage"
#include "filterdialog.h"


void MyFilterHandler::onApplyFilter(Frame frame)
{
    // получаем из кадра qImage
    QImage *qimg = new QImage(frame.filterToQImage());

    // выводим кадр на форму
    if (window != NULL) {
        window->setQimg(qimg);
        window->repaintSignal();
    }
}

MyFilterHandler::MyFilterHandler()
{

}

MyFilterHandler::~MyFilterHandler()
{

}

#include "mymovenmenthandler.h"
#include "QDebug"
#include "QString"
#include "QImage"
#include "mainwindow.h"

int cnt = 0;
void MyMovenmentHandler::onMove(Frame frame) {
    // здесь нужно писать код обработки обнаруженного движущегося объекта

    // получаем из кадра qImage
    QImage *qimg = new QImage(frame.toQImage());

    // выводим кадр на форму
    if (window != NULL) {
        window->setQimg(qimg);
        window->repaintSignal();
    }

    // сохраняем каждый кадр
    QString path = "/Users/ScanNorOne/Desktop/img/img" + QString::number(cnt) + ".jpg";
    qimg->save(path);
    cnt++;
}

MyMovenmentHandler::MyMovenmentHandler()
{
    window = NULL;
}

MyMovenmentHandler::~MyMovenmentHandler()
{

}


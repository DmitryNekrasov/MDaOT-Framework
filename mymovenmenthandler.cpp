#include "mymovenmenthandler.h"
#include "QDebug"
#include "QString"
#include "QImage"
#include "mainwindow.h"


int cnt = 0;
void MyMovenmentHandler::onMove(Frame frame, vector<Rectangle> *rectangles, vector<Point> *mask)
{
    // здесь нужно писать код обработки обнаруженного движущегося объекта

    // обводим обнаруженные объекты прямоугольниками
    if (window->isOutRect()) {
        for (vector<Rectangle>::iterator it = rectangles->begin(); it != rectangles->end(); it++) {
            Rectangle rect = *it;
            frame.drawRectangle(rect);
        }
    }

    // выводим контуры движущихся объектов
    if (window->isOutMask()) {
        for (vector<Point>::iterator it = mask->begin(); it != mask->end(); it++) {
            Point point = *it;
            frame.drawPoint(point);
        }
    }

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

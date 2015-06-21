#include "mymovenmenthandler.h"
#include "QDebug"
#include "QString"
#include "QImage"
#include "mainwindow.h"


const int okArea = 10000;
const int marking = 230;  // подсчитана аналитически с помощью линейки и отношения дробей

vector<Rectangle> lastRectangles, newRectangles;
int cnt = 0;
bool isFirst = true;
int lastCountLeft = 0, lastCountRight = 0;
int allCountLeft = 0, allCountRight;

void MyMovenmentHandler::onMove(Frame frame, vector<Rectangle> *rectangles, vector<Point> *mask)
{
    // здесь нужно писать код обработки обнаруженного движущегося объекта

    newRectangles.clear();

    // обводим обнаруженные объекты прямоугольниками
    bool oneMore = false;
    for (vector<Rectangle>::iterator it = rectangles->begin(); it != rectangles->end(); it++) {
        Rectangle rect = *it;
        if (rect.getArea() > okArea) {
            if (window->isOutRect()) {
                frame.drawRectangle(rect);
            }

            // формируем newRectangles
            newRectangles.push_back(rect);

            oneMore = true;
        }
    }

    if (isFirst && oneMore) {  // сформировали первый раз lastRectangles
        isFirst = false;
        for (vector<Rectangle>::iterator it = rectangles->begin(); it != rectangles->end(); it++) {
            Rectangle rect = *it;
            if (rect.getArea() > okArea) {
                lastRectangles.push_back(rect);
            }
        }
    } else {
        int newCountLeft = 0;
        int newCountRight = 0;
        for (vector<Rectangle>::iterator it = newRectangles.begin(); it != newRectangles.end(); it++) {
            Rectangle rect = *it;
            if (abs(rect.getLeftBottomCornerX() - frame.getHeight()) <= 1) {
                if (rect.getLeftBottomCornerY() < marking) {
                    newCountLeft++;
                } else {
                    newCountRight++;
                }
            }
        }

        if (newCountLeft > lastCountLeft) {
            int diff = newCountLeft - lastCountLeft;
            allCountLeft += diff;
            window->setCountLeft(window->getCountLeft() + diff);
        }

        if (newCountRight > lastCountRight) {
            int diff = newCountRight - lastCountRight;
            allCountRight += diff;
            window->setCountRight(window->getCountRight() + diff);
        }

        lastCountLeft = newCountLeft;
        lastCountRight = newCountRight;
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

#include "mymovenmenthandler.h"
#include "QDebug"
#include "QString"
#include "QImage"
#include "mainwindow.h"


const int okArea = 10000;  // максимально допустимая площадь ограничивающего прямоугольника обнаруженного объекта
const int marking = 230;  // подсчитана аналитически с помощью линейки и отношения дробей
const int maxDistance = 5;  // максимально допустимое расстояние между одним объектом на разных кадрах
const double heightLineMarkMeter = 0.2;  // ширина сплошной линии разметки в метрах
const int heightLineMarkPixel = 10; // ширина сплошной линии разметки в пикселях
const double msToKmh = 3.6;  // коэффициент для перевода метров в секунду в километры в час
const double timeFrame = 0.03;  // время между кадрами в секундах
const int factor = 5;

vector<Rectangle> lastRectangles, newRectangles;
int cnt = 0;
bool isFirst = true;
int lastCountLeft = 0, lastCountRight = 0;
int allCountLeft = 0, allCountRight;

int getVelocity(int n) {
    double x = (((double) n * heightLineMarkMeter) / heightLineMarkPixel) / timeFrame * msToKmh;
    return x * factor;
}

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

        //считаем скорость объектов
        for (vector<Rectangle>::iterator it = newRectangles.begin(); it != newRectangles.end(); it++) {
            Rectangle rect1 = *it;
            int minDistance = maxDistance;
            for (vector<Rectangle>::iterator lit = lastRectangles.begin(); lit != lastRectangles.end(); lit++) {
                Rectangle rect2 = *lit;
                int tmpDistance = Point::getDistance(rect1.getCenterPoint(), rect2.getCenterPoint());
                minDistance = min(minDistance, tmpDistance);
            }
            if (minDistance < maxDistance && minDistance != 0 && window->isOutVelocity()) {
                frame.putText(to_string(getVelocity(minDistance)) + " km/h", rect1.getCenterPoint());
            }
        }

        // переписываем lastRectangles
        lastRectangles.clear();
        for (vector<Rectangle>::iterator it = newRectangles.begin(); it != newRectangles.end(); it++) {
            Rectangle rect = *it;
            lastRectangles.push_back(rect);
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

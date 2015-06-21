#ifndef POINT_H
#define POINT_H
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/video/tracking.hpp>
#include <opencv2/imgproc/imgproc_c.h>
#include <opencv2/opencv.hpp>


/*!
 * Точка.
 * Используется для рисования контура вокруг обнаруженных объектов.
 * \brief The Point class
 * \author Dmitry Nekrasov
 * \version 0.1
 * \date Июнь 2015
 */
class Point
{
private:

    cv::Point cvPoint;

public:

    /*!
     * Возвращает объект класса cv::Point
     * \brief getCvPoint
     * \return Объект класса cv::Point
     */
    cv::Point getCvPoint();

    /*!
     * Возвращает x-координату точки
     * \brief getX
     * \return X-координата точки
     */
    int getX();

    /*!
     * Возвращает y-координату точки
     * \brief getY
     * \return Y-координата точки
     */
    int getY();

    /*!
     * Возвращает расстояние по y между двумя точками
     * \brief getDistance
     * \param p1 Первая точка
     * \param p2 Вторая точка
     * \return Расстояние по y между двумя точками
     */
    static int getDistance(Point p1, Point p2);

    /*!
     * Конструктор по умолчанию
     * \brief Point
     */
    Point();

    /*!
     * Конструктор
     * \brief Point
     * \param point Объект класса cv::Point
     */
    Point(cv::Point point);

    ~Point();
};

#endif // POINT_H

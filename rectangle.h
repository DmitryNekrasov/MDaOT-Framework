#ifndef RECTANGLE_H
#define RECTANGLE_H
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/video/tracking.hpp>
#include <opencv2/imgproc/imgproc_c.h>
#include <opencv2/opencv.hpp>


/*!
 * Прямоугольник.
 * Используется для выделения обнаруженных объектов.
 * \brief The Rectangle class
 * \author Dmitry Nekrasov
 * \version 0.1
 * \date Июнь 2015
 */
class Rectangle
{

    cv::Rect myRect;

public:

    /*!
     * Возвращает объект класса cv::Rect
     * \brief getCvRect
     * \return Объект класса cv::Rect
     */
    cv::Rect getCvRect();

    /*!
     * Возвращает площадь прямоугольника
     * \brief getArea
     * \return Площадь прямоугольника
     */
    int getArea();

    /*!
     * Возвращает x-координату левого нижнего угла прямоугольника
     * Координатная плоскость:
     *  0|                               X
     * --+------------------------------->
     *   |
     *   |
     *   |
     *   |
     *   |
     *   v Y
     * \brief getLeftBottomCornerX
     * \return X-координата левого нижнего угла прямоугольника
     */
    int getLeftBottomCornerX();

    /*!
     * Возвращает y-координату левого нижнего угла прямоугольника
     * \brief getLeftBottomCornerY
     * \return Y-координата левого нижнего угла прямоугольника
     */
    int getLeftBottomCornerY();

    /*!
     * Конструктор
     * \brief Rectangle
     * \param x Координата x верхнего левого угла прямоугольника
     * \param y Координата y верхнего левого угла прямоугольника
     * \param width Ширина прямоугольника
     * \param height Высота прямоугольника
     */
    Rectangle(int x, int y, int width, int height);

    /*!
     * Конструктор
     * \brief Rectangle
     * \param cvRect Объект класса cv::Rect
     */
    Rectangle(cv::Rect cvRect);

    ~Rectangle();
};

#endif // RECTANGLE_H

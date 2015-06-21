#ifndef FRAME_H
#define FRAME_H
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/video/tracking.hpp>
#include <opencv2/imgproc/imgproc_c.h>
#include <opencv2/opencv.hpp>
#include <string>
#include "rectangle.h"
#include "point.h"
#include <QApplication>


using namespace std;


/*!
 * Класс кадра видео.
 * Содержит необходимые методы для работы с кадром.
 * \brief The Frame class
 * \author Dmitry Nekrasov
 * \version 0.1
 * \date Июнь 2015
 * Кадр
 */
class Frame
{
private:
    cv::Mat mat;

public:

    /*!
     * Выводит кадр в отдельное окно с заданным именем
     * \brief show
     * \param windowName Название окна, в котором будет отображаться кадр
     * \return True, если на активном окне нажата какая-нибудь клавиша, иначе false
     */
    bool show(string windowName);

    /*!
     * Разрушает окно с заданным именем
     * \brief destroyWindow
     * \param windowName Название окна, на которое выводится кадр
     */
    static void destroyWindow(string windowName);

    /*!
     * Возвращает cv::Mat из кадра
     * \brief getCvMat
     * \return cv::Mat
     */
    cv::Mat getCvMat();

    /*!
     * Возвращает ширину кадра
     * \brief getWidth
     * \return Ширина кадра
     */
    int getWidth();

    /*!
     * Возвращает высоту кадра
     * \brief getHeight
     * \return Высота кадра
     */
    int getHeight();

    /*!
     * Находит абсолютную попиксельную разницу между кадрами
     * \brief difference
     * \param frame1 Первый кадр
     * \param frame2 Второй кадр
     * \return Кадр - абсолютная разница между кадрами
     */
    static Frame difference(Frame frame1, Frame frame2);

    /*!
     * Находит контуры светлых объектов на кадре (движущиеся объекты)
     * \brief searchForMovement
     * \param thresholdImage Изображение, на котором производится поиск контуров
     * \param[out] points Точки всех контуров
     * \return Вектор прямоугольников, выделяющих движущиеся объекты
     */
    static vector<Rectangle> searchForMovement(cv::Mat thresholdImage, vector<Point> *points);

    /*!
     * Рисует синий прямоугольник на кадре
     * \brief drawRectangle
     * \param rectangle Прямоугольник
     */
    void drawRectangle(Rectangle rectangle);

    /*!
     * Рисует красную точку на кадре
     * \brief drawPoint
     * \param point Точка
     */
    void drawPoint(Point point);

    /*!
     * Преобразует цветное изображение кадра в QImage
     * \brief toQImage
     * \return Изображение QImage
     */
    QImage toQImage();

    /*!
     * Преобразует изображение кадра в градациях серого в QImage
     * \brief filterToQImage
     * \return Изображение QImage
     */
    QImage filterToQImage();

    /*!
     * Конструктор
     * \brief Frame
     * \param mat Объект cv::Mat
     */
    Frame(cv::Mat mat);

    /*!
     * Конструктор по умолчанию
     * \brief Frame
     */
    Frame();

    ~Frame();
};

#endif // FRAME_H

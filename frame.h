#ifndef FRAME_H
#define FRAME_H

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/video/tracking.hpp>
#include <opencv2/imgproc/imgproc_c.h>
#include <opencv2/opencv.hpp>

#include <string>
#include <QApplication>

#include "point.h"
#include "rectangle.h"


/*!
 * Класс кадра видео.
 * Содержит необходимые методы для работы с кадром.
 * \brief The Frame class
 * \author Dmitry Nekrasov
 * \version 0.1.1
 * \date Июнь 2015
 */
class Frame
{
public:

    /*!
     * Конструктор по умолчанию
     * \brief Frame
     */
    Frame();

    ~Frame();

    /*!
     * Выводит кадр в отдельное окно с заданным именем
     * \brief show
     * \param _window_name Название окна, в котором будет отображаться кадр
     * \return True, если на активном окне нажата какая-нибудь клавиша, иначе false
     */
    bool show(std::string _window_name);

    /*!
     * Разрушает окно с заданным именем
     * \brief destroyWindow
     * \param _window_name Название окна, на которое выводится кадр
     */
    static void destroyWindow(std::string _window_name);

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
     * \param _frame1 Первый кадр
     * \param _frame2 Второй кадр
     * \return Кадр - абсолютная разница между кадрами
     */
    static Frame difference(Frame _frame1, Frame _frame2);

    /*!
     * Находит контуры светлых объектов на кадре (движущиеся объекты)
     * \brief searchForMovement
     * \param _thresholdImage Изображение, на котором производится поиск контуров
     * \param[out] _points Точки всех контуров
     * \return Вектор прямоугольников, выделяющих движущиеся объекты
     */
    static std::vector<Rectangle> searchForMovement(cv::Mat _thresholdImage, std::vector<Point>* _points);

    /*!
     * Рисует синий прямоугольник на кадре
     * \brief drawRectangle
     * \param _rectangle Прямоугольник
     */
    void drawRectangle(Rectangle _rectangle);

    /*!
     * Рисует красную точку на кадре
     * \brief drawPoint
     * \param _point Точка
     */
    void drawPoint(Point _point);

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
     * Выводит текст на кадр
     * \brief putText
     * \param _text Текст
     * \param _point Точка - начало текста
     */
    void putText(std::string _text, Point _point);

    /*!
     * Конструктор
     * \brief Frame
     * \param _mat Объект cv::Mat
     */
    Frame(cv::Mat _mat);

private:

    cv::Mat m_Mat;

};

#endif // FRAME_H

#ifndef DETECTIONMETHOD_H
#define DETECTIONMETHOD_H
#include "video.h"
#include "filterchain.h"
#include "QDebug"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/video/tracking.hpp>
#include <opencv2/imgproc/imgproc_c.h>
#include <opencv2/opencv.hpp>
#include "filter.h"
#include "grayscalefilter.h"
#include "binaryfilter.h"
#include "blurfilter.h"
#include "medianfilter.h"
#include "movenmenthandler.h"


/*!
 * Абстрактный класс стратегии.
 * Метод обнаружения движения.
 * \brief The DetectionMethod class
 * \author Dmitry Nekrasov
 * \version 0.1
 * \date Июнь 2015
 */
class DetectionMethod
{
protected:

    MovenmentHandler *movenmentHandler;
    FilterChain filterChain;
    vector<Rectangle> moveObjectRectangles;
    Rectangle *region;
    vector<Point> *mask;

public:

    /*!
     * Находит движущиеся объекты на видео
     * \brief detect
     * \param video Видео
     */
    virtual void detect(Video video) = 0;

    /*!
     * Инициализирует метод (цепочка фильтров, фон)
     * \brief init
     * \param video Видео
     */
    virtual void init(Video video) = 0;

    /*!
     * Вызывает обработчик движения
     * \brief performOnMove
     * \param frame Кадр, на котором обнаружены движущиеся объекты
     * \param rectangles Прямоугольники, выделяющие движущиеся объекты
     * \param mask Контуры движущихся объектов
     */
    void performOnMove(Frame frame, vector<Rectangle> *rectangles, vector<Point> *mask);

    /*!
     * Устанавливает область, на которой будет производиться определение движения
     * \brief setRegion
     * \param region Область определения движения
     */
    void setRegion(Rectangle *region);

    /*!
     * Возвращает цепочку фильтров для данного метода
     * \brief getFilterChain
     * \return Цепочка фильтров
     */
    FilterChain* getFilterChain();

    /*!
     * Изменяет цепочку фильтров для данного метода
     * \brief setFilterChain
     * \param chain Цепочка фильтров
     */
    void setFilterChain(FilterChain chain);

    ~DetectionMethod();
};

#endif // DETECTIONMETHOD_H

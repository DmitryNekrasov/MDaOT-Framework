#ifndef MYMOVENMENTHANDLER_H
#define MYMOVENMENTHANDLER_H
#include "movenmenthandler.h"


/*!
 * Реализация обработчика движения
 * \brief The MyMovenmentHandler class
 * \author Dmitry Nekrasov
 * \version 0.1
 * \date Июнь 2015
 */
class MyMovenmentHandler: public MovenmentHandler
{
public:

    /*!
     * Выполняет действия с кадром после обнаружения движения
     * \brief onMove
     * \param frame Кадр
     * \param rectangles Прямоугольники, ограничивающие обнаруженные объекты
     * \param mask Контуры движущихся объектов
     */
    virtual void onMove(Frame frame, vector<Rectangle> *rectangles, vector<Point> *mask);

    /*!
     * Конструктор по умолчанию
     * \brief MyMovenmentHandler
     */
    MyMovenmentHandler();

    ~MyMovenmentHandler();
};

#endif // MYMOVENMENTHANDLER_H

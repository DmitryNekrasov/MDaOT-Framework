#ifndef MOVENMENTHANDLER_H
#define MOVENMENTHANDLER_H
#include "frame.h"

class MainWindow;


/*!
 * Абстрактный класс обработчика движения
 * \brief The MovenmentHandler class
 * \author Dmitry Nekrasov
 * \version 0.1
 * \date Июнь 2015
 */
class MovenmentHandler
{
protected:

    MainWindow *window;

public:

    /*!
     * Выполняет действия с кадром после обнаружения движения
     * \brief onMove
     * \param frame Кадр
     * \param rectangles Прямоугольники, ограничивающие обнаруженные объекты
     * \param mask Контуры движущихся объектов
     */
    virtual void onMove(Frame frame, vector<Rectangle> *rectangles, vector<Point> *mask) = 0;

    /*!
     * Изменяет окно, на которое можно отдавать кадр с обнаруженными объектами
     * \brief setWindow
     * \param win Окно
     */
    void setWindow(MainWindow *win);

    ~MovenmentHandler();
};

#endif // MOVENMENTHANDLER_H

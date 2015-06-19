#ifndef FILTERHANDLER_H
#define FILTERHANDLER_H
#include "frame.h"

class FilterDialog;


/*!
 * Абстрактный класс обработчика фильтра
 * \brief FilterHandler class
 * \author Dmitry Nekrasov
 * \version 0.1
 * \date Июнь 2015
 */
class FilterHandler
{
protected:

    FilterDialog *window;

public:

    /*!
     * Выполняет действия с кадром после применения фильтра
     * \brief onApplyFilter
     * \param frame Кадр
     */
    virtual void onApplyFilter(Frame frame) = 0;

    /*!
     * Изменяет окно, на которое можно отдавать отфильтрованное изображение
     * \brief setWindow
     * \param win Окно
     */
    void setWindow(FilterDialog *win);

    ~FilterHandler();
};

#endif // FILTERHANDLER_H

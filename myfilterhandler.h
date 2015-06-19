#ifndef MYFILTERHANDLER_H
#define MYFILTERHANDLER_H
#include "filterhandler.h"


/*!
 * Реализация обработчика фильтра.
 * Отдаёт кадр после применения фильтра на форму.
 * \brief MyFilterHandler class
 * \author Dmitry Nekrasov
 * \version 0.1
 * \date Июнь 2015
 */
class MyFilterHandler: public FilterHandler
{
public:

    /*!
     * Выполняет действия с кадром после применения фильтра.
     * Отдаёт кадр после применения фильтра на форму.
     * \brief onApplyFilter
     * \param frame Кадр
     */
    virtual void onApplyFilter(Frame frame);

    /*!
     * Конструктор по умолчанию
     * \brief MyFilterHandler
     */
    MyFilterHandler();

    ~MyFilterHandler();
};

#endif // MYFILTERHANDLER_H

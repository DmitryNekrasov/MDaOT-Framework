#ifndef OUTGRAYSCALEFH_H
#define OUTGRAYSCALEFH_H
#include "filterhandler.h"


/*!
 * Реализация обработчика фильтра.
 * Вывод кадра после применения фильтра градации серого.
 * \brief OutGrayscaleFH class
 * \author Dmitry Nekrasov
 * \version 0.1
 * \date Июнь 2015
 */
class OutGrayscaleFH: public FilterHandler
{
public:

    /*!
     * Выполняет действия с кадром после применения фильтра.
     * Выводит кадр в отдельном окне.
     * \brief onApplyFilter
     * \param frame Кадр
     */
    virtual void onApplyFilter(Frame frame);

    /*!
     * Конструктор по умолчанию
     * \brief OutGrayscaleFH
     */
    OutGrayscaleFH();

    ~OutGrayscaleFH();
};

#endif // OUTGRAYSCALEFH_H

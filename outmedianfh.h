#ifndef OUTMEDIANFH_H
#define OUTMEDIANFH_H
#include "filterhandler.h"


/*!
 * Реализация обработчика фильтра.
 * Вывод кадра после применения медианного фильтра.
 * \brief The OutMedianFH class
 * \author Dmitry Nekrasov
 * \version 0.1
 * \date Июнь 2015
 */
class OutMedianFH: public FilterHandler
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
     * \brief OutMedianFH
     */
    OutMedianFH();

    ~OutMedianFH();
};

#endif // OUTMEDIANFH_H

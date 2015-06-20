#ifndef OUTBINARYFH_H
#define OUTBINARYFH_H
#include "filterhandler.h"


/*!
 * Реализация обработчика фильтра.
 * Вывод кадра после применения фильтра бинаризация.
 * \brief The OutBinaryFH class
 * \author Dmitry Nekrasov
 * \version 0.1
 * \date Июнь 2015
 */
class OutBinaryFH: public FilterHandler
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
     * \brief OutBinaryFH
     */
    OutBinaryFH();

    ~OutBinaryFH();
};

#endif // OUTBINARYFH_H

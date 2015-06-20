#ifndef OUTBLURFH_H
#define OUTBLURFH_H
#include "filterhandler.h"


/*!
 * Реализация обработчика фильтра.
 * Вывод кадра после применения фильтра размытие.
 * \brief The OutBlurFH class
 * \author Dmitry Nekrasov
 * \version 0.1
 * \date Июнь 2015
 */
class OutBlurFH : public FilterHandler
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
     * \brief OutBlurFH
     */
    OutBlurFH();

    ~OutBlurFH();
};

#endif // OUTBLURFH_H

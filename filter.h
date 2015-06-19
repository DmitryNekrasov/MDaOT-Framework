#ifndef FILTER_H
#define FILTER_H
#include "QString"
#include "frame.h"
#include "filterhandler.h"
#include "myfilterhandler.h"
#include "outgrayscalefh.h"
#include "outmedianfh.h"
#include "outblurfh.h"
#include "outbinaryfh.h"


/*!
 * Абстрактный класс фильтра
 * \brief The Filter class
 * \author Dmitry Nekrasov
 * \version 0.1
 * \date Июнь 2015
 */
class Filter
{
protected:
    FilterHandler *filterHandler;
    QString name;

public:

    /*!
     * Применяет фильтр к кадру
     * \brief apply
     * \param originalFrame Кадр
     * \return Кадр, полученный после применения фильтра
     */
    virtual Frame apply(Frame originalFrame) = 0;

    /*!
     * Вызывает обраюотчик фильтра
     * \brief performApplyFilter
     * \param frame Отфильтрованный кадр
     */
    void performApplyFilter(Frame frame);

    /*!
     * Возвращает обработчик фильтра
     * \brief getFilterHandler
     * \return Обработчик фильтра
     */
    FilterHandler* getFilterHandler();

    /*!
     * Изменяет обработчик фильтра
     * \brief setFilterHandler
     * \param handler Обработчик фильтра
     */
    void setFilterHandler(FilterHandler *handler);

    /*!
     * Возвращает название фильтра
     * \brief getName
     * \return Название фильтра
     */
    QString getName();

    ~Filter();
};

#endif // FILTER_H

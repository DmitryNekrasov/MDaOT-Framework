#ifndef MEDIANFILTER_H
#define MEDIANFILTER_H
#include "filter.h"
#include "filterhandler.h"


/*!
 * Медианный фильтр
 * \brief The MedianFilter class
 * \author Dmitry Nekrasov
 * \version 0.1
 * \date Июнь 2015
 */
class MedianFilter: public Filter
{
private:

    int size;

public:

    /*!
     * Применяет фильтр к кадру
     * \brief apply
     * \param originalFrame Кадр
     * \return Кадр, полученный после применения фильтра
     */
    virtual Frame apply(Frame originalFrame);

    /*!
     * Возвращает размер медианного фильтра
     * \brief getSize
     * \return Размер медианного фильтра
     */
    int getSize();

    /*!
     * Изменяет размер медианного фильтра
     * \brief setSize
     * \param size Размер медианного фильтра
     */
    void setSize(int size);

    /*!
     * Конструктор
     * \brief MedianFilter
     * \param size Размер медианного фильтра
     */
    MedianFilter(int size);

    /*!
     * Конструктор
     * \brief MedianFilter
     * \param size Размер медианного фильтра
     * \param handler Обработчик фильтра
     */
    MedianFilter(int size, FilterHandler *handler);

    ~MedianFilter();
};

#endif // MEDIANFILTER_H

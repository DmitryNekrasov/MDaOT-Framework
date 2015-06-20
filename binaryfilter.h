#ifndef BINARYFILTER_H
#define BINARYFILTER_H
#include "filter.h"
#include "filterhandler.h"


/*!
 * Фильтр бинаризация
 * \brief The BinaryFilter class
 * \author Dmitry Nekrasov
 * \version 0.1
 * \date Июнь 2015
 */
class BinaryFilter : public Filter
{
private:

    int threshold;

public:

    /*!
     * Применяет фильтр к кадру
     * \brief apply
     * \param originalFrame Кадр
     * \return Кадр, полученный после применения фильтра
     */
    virtual Frame apply(Frame originalFrame);

    /*!
     * Возвращает порог бинаризации
     * \brief getThreshold
     * \return Порог бинаризации
     */
    int getThreshold();

    /*!
     * Изменяет порог бинаризации
     * \brief setThreshold
     * \param threshold Порог бинаризации
     */
    void setThreshold(int threshold);

    /*!
     * Конструктор
     * \brief BinaryFilter
     * \param threshold Порог бинаризации
     * \param handler Обработчик фильтра
     */
    BinaryFilter(int threshold, FilterHandler *handler);

    /*!
     * Конструктор
     * \brief BinaryFilter
     * \param threshold Порог бинаризации
     */
    BinaryFilter(int threshold);

    ~BinaryFilter();
};

#endif // BINARYFILTER_H

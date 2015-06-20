#ifndef GRAYSCALEFILTER_H
#define GRAYSCALEFILTER_H
#include "filter.h"
#include "filterhandler.h"


/*!
 * Фильтр градации серого
 * \brief The GrayscaleFilter class
 * \author Dmitry Nekrasov
 * \version 0.1
 * \date Июнь 2015
 */
class GrayscaleFilter : public Filter
{
public:

    /*!
     * Применяет фильтр к кадру
     * \brief apply
     * \param originalFrame Кадр
     * \return Кадр, полученный после применения фильтра
     */
    virtual Frame apply(Frame originalFrame);

    /*!
     * Конструктор по умолчанию
     * \brief GrayscaleFilter
     */
    GrayscaleFilter();

    /*!
     * Конструктор
     * \brief GrayscaleFilter
     * \param handler Обработчик фильтра
     */
    GrayscaleFilter(FilterHandler *handler);

    ~GrayscaleFilter();
};

#endif // GRAYSCALEFILTER_H

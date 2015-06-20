#ifndef BLURFILTER_H
#define BLURFILTER_H
#include "filter.h"
#include "filterhandler.h"


/*!
 * Фильтр размытие
 * \brief The BlurFilter class
 * \author Dmitry Nekrasov
 * \version 0.1
 * \date Июнь 2015
 */
class BlurFilter: public Filter
{
private:

    int widthBlur;
    int heightBlur;

public:

    /*!
     * Применяет фильтр к кадру
     * \brief apply
     * \param originalFrame Кадр
     * \return Кадр, полученный после применения фильтра
     */
    virtual Frame apply(Frame originalFrame);

    /*!
     * Возвращает ширину матрицы свёртки
     * \brief getWidthBlur
     * \return Ширина матрицы свёртки
     */
    int getWidthBlur();

    /*!
     * Изменяет ширину матрицы свёртки
     * \brief setWidthBlur
     * \param widthBlur Ширина матрицы свёртки
     */
    void setWidthBlur(int widthBlur);

    /*!
     * Возвращает высоту матрицы свёртки
     * \brief getHeightBlur
     * \return Высота матрицы свёртки
     */
    int getHeightBlur();

    /*!
     * Изменяет высоту матрицы свёртки
     * \brief setHeightBlur
     * \param heightBlur Высота матрицы свёртки
     */
    void setHeightBlur(int heightBlur);

    /*!
     * Конструктор
     * \brief BlurFilter
     * \param widthBlur Ширина матрицы свёртки
     * \param heightBlur Высота матрицы свёртки
     */
    BlurFilter(int widthBlur, int heightBlur);

    /*!
     * Конструктор
     * \brief BlurFilter
     * \param widthBlur Ширина матрицы свёртки
     * \param heightBlur Высота матрицы свёртки
     * \param handler Обработчик фильтра
     */
    BlurFilter(int widthBlur, int heightBlur, FilterHandler *handler);

    ~BlurFilter();
};

#endif // BLURFILTER_H

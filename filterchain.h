#ifndef FILTERCHAIN_H
#define FILTERCHAIN_H
#include "filter.h"
#include "frame.h"


using namespace std;


/*!
 * Цепочка фильтров
 * \brief FilterChain class
 * \author Dmitry Nekrasov
 * \version 0.1
 * \date Июнь 2015
 */
class FilterChain
{
private:

    vector<Filter*> filters;

public:

    /*!
     * Добавляет фильтр в цепочку
     * \brief add
     * \param filter Фильтр
     */
    void add(Filter *filter);

    /*!
     * Очищает цепочку фильтров
     * \brief clear
     */
    void clear();

    /*!
     * Применяет цепочку фильтров к кадру
     * \brief apply
     * \param startFrame Кадр, к которому применяется цепочка фильтров
     * \return Кадр, который получается после применения цепочки фильтров
     */
    Frame apply(Frame startFrame);

    /*!
     * Возвращает количество фильтров в цепочке
     * \brief getCount
     * \return Количество фильтров в цепочке
     */
    int getCount();

    /*!
     * Возвращает вектор имён фильтров в цепочке
     * \brief getNames
     * \return Вектор имён фильтров в цепочке
     */
    vector<QString> getNames();

    /*!
     * Возвращает фильтр по индексу
     * \brief getOnIndex
     * \param index Индекс
     * \return Фильтр в цепочке с заданным индексом
     */
    Filter* getOnIndex(int index);

    /*!
     * Изменяет фильтр в цепочке с заданным индексом
     * \brief setOnIndex
     * \param index Индекс
     * \param filter Фильтр
     */
    void setOnIndex(int index, Filter* filter);

    /*!
     * Удаляет фильтр из цепочки по индексу
     * \brief deleteOnIndex
     * \param index Индекс
     */
    void deleteOnIndex(int index);

    /*!
     * Меняет местами 2 фильтра в цепочке
     * \brief swapFilters
     * \param i Индекс первого фильтра
     * \param j Индекс второго фильтра
     */
    void swapFilters(int i, int j);

    /*!
     * Конструктор по умолчанию
     * \brief FilterChain
     */
    FilterChain();

    ~FilterChain();
};

#endif // FILTERCHAIN_H

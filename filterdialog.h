#ifndef FILTERDIALOG_H
#define FILTERDIALOG_H

#define MINIMUM_MEDIAN 1
#define MAXIMUM_MEDIAN 15
#define MINIMUM_BLUR 1
#define MAXIMUM_BLUR 25

#include <QDialog>
#include <QDebug>
#include <QImage>

#include "filter.h"
#include "filterhandler.h"
#include "myfilterhandler.h"
#include "binaryfilter.h"
#include "blurfilter.h"
#include "medianfilter.h"
#include "grayscalefilter.h"
#include "mainwindow.h"


namespace Ui {
class FilterDialog;
}


/*!
 * Окно для отображения отфильтрованных кадров,
 * а также редактирования фильтров.
 * \brief The FilterDialog class
 */
class FilterDialog : public QDialog
{
    Q_OBJECT

public:

    /*!
     * Изменяет фильтр, редактируемый на данной форме
     * \brief setFilter
     * \param filter Фильтр
     */
    void setFilter(Filter *filter);

    /*!
     * Перед закрытием формы изменяет обработчик фильтра на NULL
     * \brief closeEvent
     * \param event Событие
     */
    void closeEvent(QCloseEvent *event);

    /*!
     * Изменяет отфильтрованное изображение, выводимое на данной форме.
     * \brief setQimg
     * \param img Изображение
     */
    void setQimg(QImage *img);

    /*!
     * Конструктор
     * \brief FilterDialog
     * \param parent Родительский виджет
     */
    explicit FilterDialog(QWidget *parent = 0);

    ~FilterDialog();

protected:

    /*!
     * Событие на отрисовку изображения на форме
     * \brief paintEvent
     */
    void paintEvent(QPaintEvent *);

private slots:

    /*!
     * При нажатии на кнопку закрытия данное окно закрывается.
     * \brief on_closeButton_clicked
     */
    void on_closeButton_clicked();

    /*!
     * При прокручивании первого слайдера меняютя некоторые параметры фильтров
     * в зависимости от типов фильтров:
     * - Порог бинаризации для фильтра бинаризация
     * - Размер медианного фильтра для медианного фильтра
     * - Ширина матрицы свёртки для фильтра размытие
     * \brief on_horizontalSlider_valueChanged
     * \param value Новое значение соответствующего параметра фильтра
     */
    void on_horizontalSlider_valueChanged(int value);

    /*!
     * При прокручивании второго слайдера меняется высота матрицы свёртки
     * для фильтра размытие.
     * \brief on_horizontalSliderBlur_valueChanged
     * \param value Новое значение высоты матрицы свёртки
     */
    void on_horizontalSliderBlur_valueChanged(int value);

private:

    Ui::FilterDialog *ui;
    Filter *filter;
    BinaryFilter *binaryFilter;
    BlurFilter *blurFilter;
    MedianFilter *medianFilter;
    GrayscaleFilter *grayscaleFilter;
    int filterCode;
    QImage *qimg;

    /*!
     * Вызывается после изменения текущего фильтра.
     * Настраивает слайдеры и спенеры в зависимости от типа фильтра.
     * \brief nextProcessing
     */
    void nextProcessing();

    /*!
     * Скрывает настройки ширины матрицы свёртки, если текущий фильтр -
     * не фильтр размытие.
     * \brief makeFalseBlurSettings
     */
    void makeFalseBlurSettings();

signals:

    /*!
     * Сигнал на переисовку изображения
     * \brief repaintSignal
     */
    void repaintSignal();
};

#endif // FILTERDIALOG_H

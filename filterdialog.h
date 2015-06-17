#ifndef FILTERDIALOG_H
#define FILTERDIALOG_H

#define BINARY_CODE 1
#define BLUR_CODE 2
#define MEDIAN_CODE 3
#define GRAYSCALE_CODE 4

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

namespace Ui {
class FilterDialog;
}

class FilterDialog : public QDialog
{
    Q_OBJECT

public:
    explicit FilterDialog(QWidget *parent = 0);
    ~FilterDialog();

    void setFilter(Filter *filter);
    void closeEvent(QCloseEvent *event);

    void setQimg(QImage *img);

protected:
    void paintEvent(QPaintEvent *);

private slots:
    void on_closeButton_clicked();

    void on_FilterDialog_destroyed();

    void on_horizontalSlider_valueChanged(int value);

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

    void nextProcessing();
    void makeFalseBlurSettings();

signals:
    void repaintSignal();
};

#endif // FILTERDIALOG_H

#ifndef FILTERDIALOG_H
#define FILTERDIALOG_H

#include <QDialog>
#include <QDebug>
#include <QImage>

#include "filter.h"
#include "filterhandler.h"
#include "myfilterhandler.h"

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

private:
    Ui::FilterDialog *ui;
    Filter *filter;

    QImage *qimg;

signals:
    void repaintSignal();
};

#endif // FILTERDIALOG_H

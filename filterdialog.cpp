#include "filterdialog.h"
#include "ui_filterdialog.h"
#include "QPainter"

FilterDialog::FilterDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FilterDialog)
{
    ui->setupUi(this);
    qimg = NULL;
    connect(this, SIGNAL(repaintSignal()), this, SLOT(repaint()));
}

FilterDialog::~FilterDialog()
{
    delete ui;
}

void FilterDialog::setFilter(Filter *filter)
{
    this->filter = filter;
    FilterHandler* fh = new MyFilterHandler();
    fh->setWindow(this);
    filter->setFilterHandler(fh);
    this->setWindowTitle(filter->getName());
}

void FilterDialog::closeEvent(QCloseEvent *event)
{
    filter->setFilterHandler(NULL);
}

void FilterDialog::setQimg(QImage *img)
{
    qimg = img;
}

void FilterDialog::paintEvent(QPaintEvent *)
{
    QPainter painter(this); // определяем объект painter, который обеспечивает рисование

    if (qimg != NULL) {
        painter.drawImage(0, 0, *qimg);
    }
}

void FilterDialog::on_closeButton_clicked()
{
    this->close();

}

void FilterDialog::on_FilterDialog_destroyed()
{}

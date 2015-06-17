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

    if (dynamic_cast<BinaryFilter*>(filter)) {
        filterCode = BINARY_CODE;
        binaryFilter = dynamic_cast<BinaryFilter*>(filter);
    } else if (dynamic_cast<BlurFilter*>(filter)) {
        filterCode = BLUR_CODE;
        blurFilter = dynamic_cast<BlurFilter*>(filter);
    } else if (dynamic_cast<MedianFilter*>(filter)) {
        filterCode = MEDIAN_CODE;
        medianFilter = dynamic_cast<MedianFilter*>(filter);
    } else if (dynamic_cast<GrayscaleFilter*>(filter)) {
        filterCode = GRAYSCALE_CODE;
        grayscaleFilter = dynamic_cast<GrayscaleFilter*>(filter);
    }

    nextProcessing();
}

void FilterDialog::nextProcessing()
{
    if (filterCode == BINARY_CODE) {
        ui->horizontalSlider->setValue(binaryFilter->getThreshold());
        makeFalseBlurSettings();
    } else if (filterCode == MEDIAN_CODE) {

        ui->horizontalSlider->setValue(medianFilter->getSize());

        makeFalseBlurSettings();

        ui->label->setText("Размер:");

        ui->horizontalSlider->setMinimum(MINIMUM_MEDIAN);
        ui->horizontalSlider->setMaximum(MAXIMUM_MEDIAN);
        ui->horizontalSlider->setSingleStep(2);

        ui->spinBox->setMinimum(MINIMUM_MEDIAN);
        ui->spinBox->setMaximum(MAXIMUM_MEDIAN);
        ui->spinBox->setSingleStep(2);

    } else if (filterCode == BLUR_CODE) {

        ui->horizontalSlider->setValue(blurFilter->getWidthBlur());
        ui->horizontalSliderBlur->setValue(blurFilter->getHeightBlur());

        ui->label->setText("Ширина:");

        ui->horizontalSlider->setMinimum(MINIMUM_BLUR);
        ui->horizontalSlider->setMaximum(MAXIMUM_BLUR);

        ui->spinBox->setMinimum(MINIMUM_BLUR);
        ui->spinBox->setMaximum(MAXIMUM_BLUR);

        ui->horizontalSliderBlur->setMinimum(MINIMUM_BLUR);
        ui->horizontalSliderBlur->setMaximum(MAXIMUM_BLUR);

        ui->spinBoxBlur->setMinimum(MINIMUM_BLUR);
        ui->spinBoxBlur->setMaximum(MAXIMUM_BLUR);

    }
}

void FilterDialog::makeFalseBlurSettings()
{
    ui->labelBlur->setVisible(false);
    ui->spinBoxBlur->setVisible(false);
    ui->horizontalSliderBlur->setVisible(false);
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



void FilterDialog::on_horizontalSlider_valueChanged(int value)
{
    if (filterCode == BINARY_CODE) {
        binaryFilter->setThreshold(value);
    } else if (filterCode == MEDIAN_CODE) {
        if (value % 2 == 0) {
            value++;
            ui->horizontalSlider->setValue(value);
        }
        medianFilter->setSize(value);
    } else if (filterCode == BLUR_CODE) {
        blurFilter->setWidthBlur(value);
    }
}

void FilterDialog::on_horizontalSliderBlur_valueChanged(int value)
{
    if (filterCode == BLUR_CODE) {
        blurFilter->setHeightBlur(value);
    }
}

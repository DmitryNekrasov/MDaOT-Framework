#include "mainwindow.h"
#include "ui_mainwindow.h"

#define BINARY_NAME "Binary"
#define BLUR_NAME "Blur"
#define MEDIAN_NAME "Median"
#define GRAYSCALE_NAME "Grayscale"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qimg = NULL;
    connect(this, SIGNAL(repaintSignal()), this, SLOT(repaint()));

    video = Video("/Users/ScanNorOne/Desktop/s480.mp4");

    detector = Detector();

    myMH = new MyMovenmentHandler();
    myMH->setWindow(this);

    si = new SequentialImages(myMH);
    bs = new MyBackgroundSubtraction(myMH);

    detector.setDetectionMethod(bs);

    ui->bsRadio->setChecked(true);
//    ui->siRadio->setEnabled(false);
//    ui->bsRadio->setEnabled(false);

    // инициализация детектора (цепочка фильтров, фон)
    detector.startDetector(video);

    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(sl()));
    timer->start();

    refreshList();

    ui->selectFilterCombo->addItem(BINARY_NAME);
    ui->selectFilterCombo->addItem(BLUR_NAME);
    ui->selectFilterCombo->addItem(MEDIAN_NAME);
}

void MainWindow::sl() {
    detector.execute(video);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setQimg(QImage *img)
{
    qimg = img;
}

bool MainWindow::isOutMask()
{
    return outMask;
}

bool MainWindow::isOutRect()
{
    return outRect;
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);  // определяем объект painter, который обеспечивает рисование

    if (qimg != NULL) {
        painter.drawImage(0, 0, *qimg);
    }
}

void MainWindow::refreshList()
{
    DetectionMethod *dm = detector.getDetectionMethod();
    ui->listName->clear();
    vector<QString> filterNames = dm->getFilterChain()->getNames();
    qDebug() << (dm->getFilterChain()->getCount());
    for (int i = 0; i < filterNames.size(); i++) {
        ui->listName->addItem(filterNames.at(i));
    }
    ui->listName->setCurrentRow(0);
}

void MainWindow::on_pushButton_clicked()
{

}

void MainWindow::on_startPauseButton_clicked()
{
    if (timer->isActive()) {
        timer->stop();
        ui->startPauseButton->setText("▶");
        ui->siRadio->setEnabled(true);
        ui->bsRadio->setEnabled(true);
    } else {
        timer->start();
        ui->startPauseButton->setText("▐▐");
//        ui->siRadio->setEnabled(false);
//        ui->bsRadio->setEnabled(false);
    }
}

void MainWindow::on_listName_doubleClicked(const QModelIndex &index)
{
    DetectionMethod *dm = detector.getDetectionMethod();
    FilterDialog *filterDialogWindow = new FilterDialog();
    filterDialogWindow->setFilter(dm->getFilterChain()->getOnIndex(ui->listName->currentRow()));
    filterDialogWindow->show();
}

void MainWindow::on_closeButton_clicked()
{
    this->close();
}

void MainWindow::on_listName_currentRowChanged(int currentRow)
{
    if (currentRow == 0) {
        ui->bottomButton->setEnabled(true);
        ui->topButton->setEnabled(false);
    } else if (currentRow == si->getFilterChain()->getCount() - 1) {
        ui->topButton->setEnabled(true);
        ui->bottomButton->setEnabled(false);
    } else {
        ui->topButton->setEnabled(true);
        ui->bottomButton->setEnabled(true);
    }

    if (currentRow < 0) {
        ui->deleteFilterButton->setEnabled(false);
    } else {
        ui->deleteFilterButton->setEnabled(true);
    }

    if (ui->listName->count() <= 1) {
        ui->topButton->setEnabled(false);
        ui->bottomButton->setEnabled(false);
    }
}

void MainWindow::on_addFilterButton_clicked()
{
    Filter *filter;
    QString name = ui->selectFilterCombo->currentText();

    if (name == BINARY_NAME) {
        filter = new BinaryFilter(128);
    } else if (name == BLUR_NAME) {
        filter = new BlurFilter(1, 1);
    } else if (name == MEDIAN_NAME) {
        filter = new MedianFilter(1);
    } else {
        filter = new GrayscaleFilter();
    }

    DetectionMethod *dm = detector.getDetectionMethod();
    dm->getFilterChain()->add(filter);

    refreshList();
    ui->listName->setCurrentRow(dm->getFilterChain()->getCount() - 1);
}

void MainWindow::on_deleteFilterButton_clicked()
{
    DetectionMethod *dm = detector.getDetectionMethod();
    int index = ui->listName->currentRow();
    dm->getFilterChain()->deleteOnIndex(index);
    refreshList();
}

void MainWindow::on_bottomButton_clicked()
{
    DetectionMethod *dm = detector.getDetectionMethod();
    int index = ui->listName->currentRow();
    dm->getFilterChain()->swapFilters(index, index + 1);
    refreshList();
    ui->listName->setCurrentRow(index + 1);
}

void MainWindow::on_topButton_clicked()
{
    DetectionMethod *dm = detector.getDetectionMethod();
    int index = ui->listName->currentRow();
    dm->getFilterChain()->swapFilters(index, index - 1);
    refreshList();
    ui->listName->setCurrentRow(index - 1);
}

void MainWindow::on_recCheckBox_clicked()
{
    outRect = ui->recCheckBox->isChecked();
}

void MainWindow::on_pixelCheckBox_clicked()
{
    outMask = ui->pixelCheckBox->isChecked();
}

void MainWindow::on_bsRadio_clicked()
{
    if (ui->bsRadio->isChecked()) {
        detector.setDetectionMethod(bs);
        detector.startDetector(video);
        refreshList();
    }
}

void MainWindow::on_siRadio_clicked()
{
    if (ui->siRadio->isChecked()) {
        detector.setDetectionMethod(si);
        detector.startDetector(video);
        refreshList();
    }
}

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
    dm = new SequentialImages(myMH);
    detector.setDetectionMethod(dm);
    ui->siRadio->setChecked(true);
    ui->siRadio->setEnabled(false);
    ui->bsRadio->setEnabled(false);

    // инициализация детектора (цепочка фильтров)
    detector.startDetector();

//    DetectionMethod *bs = new BackgroundSubtraction(myMH);
//    bs->setRegion(new Rectangle(500, 300, 500, 200));
//    detector.setDetectionMethod(bs);


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

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this); // определяем объект painter, который обеспечивает рисование

    if (qimg != NULL) {
        painter.drawImage(0, 0, *qimg);
    }

}

void MainWindow::refreshList()
{
    ui->listName->clear();
    vector<QString> filterNames = dm->getFilterChain()->getNames();
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
        ui->siRadio->setEnabled(false);
        ui->bsRadio->setEnabled(false);
    }
}

void MainWindow::on_listName_doubleClicked(const QModelIndex &index)
{
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
    } else if (currentRow == dm->getFilterChain()->getCount() - 1) {
        ui->topButton->setEnabled(true);
        ui->bottomButton->setEnabled(false);
    } else {
        ui->topButton->setEnabled(true);
        ui->bottomButton->setEnabled(true);
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

    dm->getFilterChain()->add(filter);

    refreshList();
    ui->listName->setCurrentRow(dm->getFilterChain()->getCount() - 1);
}

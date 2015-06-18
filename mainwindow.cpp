#include "mainwindow.h"
#include "ui_mainwindow.h"


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

    // инициализация детектора (цепочка фильтров)
    detector.startDetector();

//    DetectionMethod *bs = new BackgroundSubtraction(myMH);
//    bs->setRegion(new Rectangle(500, 300, 500, 200));
//    detector.setDetectionMethod(bs);


    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(sl()));
    timer->start();

    vector<QString> filterNames = dm->getFilterChain()->getNames();
    for (int i = 0; i < filterNames.size(); i++) {
        ui->listName->addItem(filterNames.at(i));
    }

    ui->selectFilterCombo->addItem("Binary");
    ui->selectFilterCombo->addItem("Blur");
    ui->selectFilterCombo->addItem("Median");
    ui->selectFilterCombo->addItem("Grayscale");
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

void MainWindow::on_pushButton_clicked()
{

}

void MainWindow::on_startPauseButton_clicked()
{
    if (timer->isActive()) {
        timer->stop();
        ui->startPauseButton->setText("▶");
    } else {
        timer->start();
        ui->startPauseButton->setText("▐▐");
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

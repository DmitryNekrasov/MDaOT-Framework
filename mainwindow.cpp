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

    loadPreset();
    if (ui->chainCombo->count() == 0) {
        ui->applyChainButton->setEnabled(false);
        ui->deleteChainButton->setEnabled(false);
    }

    video = Video("/Users/ScanNorOne/Desktop/s480.mp4");

    detector = Detector();

    myMH = new MyMovenmentHandler();
    myMH->setWindow(this);

    si = new SequentialImages(myMH);
    bs = new MyBackgroundSubtraction(myMH);

    detector.setDetectionMethod(bs);

    ui->bsRadio->setChecked(true);

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
    for (int i = 0; i < filterNames.size(); i++) {
        ui->listName->addItem(filterNames.at(i));
    }
    ui->listName->setCurrentRow(0);
}

void MainWindow::loadPreset()
{
    QFile file(pathToPreset);
    file.open(QIODevice::ReadOnly);
    QTextStream inFile(&file);

    int countFilterChain;
    QString chainName;
    int countFilter;
    int typeFilter;
    int threshold;
    int medianSize;
    int blurWidth;
    int blurHeight;

    inFile >> countFilterChain;

    for (int i = 0; i < countFilterChain; i++) {
        FilterChain filterChain;
        inFile >> chainName;
        filterChain.setChainName(chainName);
        inFile >> countFilter;
        for (int j = 0; j < countFilter; j++) {
            Filter *filter;
            inFile >> typeFilter;
            switch (typeFilter) {
                case BINARY_CODE:
                    inFile >> threshold;
                    filter = new BinaryFilter(threshold);
                    break;
                case BLUR_CODE:
                    inFile >> blurWidth;
                    inFile >> blurHeight;
                    filter = new BlurFilter(blurWidth, blurHeight);
                    break;
                case MEDIAN_CODE:
                    inFile >> medianSize;
                    filter = new MedianFilter(medianSize);
                    break;
                case GRAYSCALE_CODE:
                    filter = new GrayscaleFilter();
                    break;
            }
            filterChain.add(filter);
        }
        preset.push_back(filterChain);
    }

    file.close();

    refreshPresetList();
}

void MainWindow::refreshPresetList()
{
    ui->chainCombo->clear();

    for (vector<FilterChain>::iterator it = preset.begin(); it != preset.end(); it++) {
        FilterChain filterChain = *it;
        ui->chainCombo->addItem(filterChain.getChainName());
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

void MainWindow::on_clearChainButton_clicked()
{
    detector.getDetectionMethod()->getFilterChain()->clear();
    refreshList();
}

void MainWindow::on_applyChainButton_clicked()
{
    int chainIndex = ui->chainCombo->currentIndex();
    detector.getDetectionMethod()->setFilterChain(preset.at(chainIndex));
    refreshList();
}

void MainWindow::on_deleteChainButton_clicked()
{
    int chainIndex = ui->chainCombo->currentIndex();
    preset.erase(preset.begin() + chainIndex);

    QFile file(pathToPreset);
    file.open(QIODevice::WriteOnly);
    QTextStream outFile(&file);

    int chainCount = preset.size();
    int filterCount;
    Filter *filter;
    MedianFilter *median;
    BinaryFilter *binary;
    BlurFilter *blur;
    outFile << chainCount << "\n";

    for (vector<FilterChain>::iterator it = preset.begin(); it != preset.end(); it++) {
        FilterChain filterChain = *it;
        outFile << filterChain.getChainName() << "\n";
        filterCount = filterChain.getCount();
        outFile << filterCount << "\n";
        for (int j = 0; j < filterCount; j++) {
            filter = filterChain.getOnIndex(j);
            if (dynamic_cast<BinaryFilter*>(filter)) {
                outFile << BINARY_CODE << " ";
                binary = dynamic_cast<BinaryFilter*>(filter);
                outFile << binary->getThreshold() << "\n";
            } else if (dynamic_cast<BlurFilter*>(filter)) {
                outFile << BLUR_CODE << " ";
                blur = dynamic_cast<BlurFilter*>(filter);
                outFile << blur->getWidthBlur() << " ";
                outFile << blur->getHeightBlur() << "\n";
            } else if (dynamic_cast<MedianFilter*>(filter)) {
                outFile << MEDIAN_CODE << " ";
                median = dynamic_cast<MedianFilter*>(filter);
                outFile << median->getSize() << "\n";
            } else if (dynamic_cast<GrayscaleFilter*>(filter)) {
                outFile << GRAYSCALE_CODE << "\n";
            }
        }
    }

    file.close();

    refreshPresetList();
}

void MainWindow::on_chainCombo_currentIndexChanged(int index)
{
    if (index < 0) {
        ui->applyChainButton->setEnabled(false);
        ui->deleteChainButton->setEnabled(false);
    } else {
        ui->applyChainButton->setEnabled(true);
        ui->deleteChainButton->setEnabled(true);
    }
}

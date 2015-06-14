#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QImage img("/Users/ScanNorOne/Desktop/1.jpg"); // загружаем картинку


    QPainter painter(this); // определяем объект painter, который обеспечивает рисование


    painter.drawImage(0,0, img.scaled(this->size()));
}

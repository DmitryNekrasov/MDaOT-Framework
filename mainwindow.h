#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QTimer>
#include <QDebug>

#include "video.h"
#include "detector.h"
#include "movenmenthandler.h"
#include "mymovenmenthandler.h"
#include "detectionmethod.h";
#include "sequentialimages.h"
#include "backgroundsubtraction.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void setQimg(QImage *img);

protected:
    void paintEvent(QPaintEvent *);

private:
    Ui::MainWindow *ui;
    QImage *qimg;
    Video video;
    Detector detector;
    MovenmentHandler *myMH;
    DetectionMethod *dm;

    QTimer *timer;

signals:
    void repaintSignal();

private slots:
    void sl();

    void on_pushButton_clicked();
    void on_startPauseButton_clicked();
};


#endif // MAINWINDOW_H

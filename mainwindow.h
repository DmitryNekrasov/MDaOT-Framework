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
#include "filterdialog.h"


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
    bool isOutMask();
    bool isOutRect();

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

    bool outRect = false;
    bool outMask = false;

    void refreshList();

signals:
    void repaintSignal();

private slots:
    void sl();

    void on_pushButton_clicked();
    void on_startPauseButton_clicked();
    void on_listName_doubleClicked(const QModelIndex &index);
    void on_closeButton_clicked();
    void on_listName_currentRowChanged(int currentRow);
    void on_addFilterButton_clicked();
    void on_deleteFilterButton_clicked();
    void on_bottomButton_clicked();
    void on_topButton_clicked();
    void on_recCheckBox_clicked();
    void on_pixelCheckBox_clicked();
};


#endif // MAINWINDOW_H

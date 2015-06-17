#include "mainwindow.h"
#include <QApplication>
#include "core.h"
#include "withform.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow *w = new MainWindow();
    w->show();

//    Core *core = Core::getInstance(w);
//    core->start();

    return a.exec();
}

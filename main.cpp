#include "mainwindow.h"
#include <QApplication>
#include "core.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    Core *core = Core::getInstance();
    core->start();

    return a.exec();
}

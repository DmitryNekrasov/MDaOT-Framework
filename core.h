#ifndef CORE_H
#define CORE_H
#include "video.h"
#include "detector.h"
#include "detectionmethod.h"
#include "sequentialimages.h"
#include "backgroundsubtraction.h"
#include "movenmenthandler.h"
#include "mymovenmenthandler.h"
#include "mainwindow.h"


class Core
{
private:

    MainWindow *window;

    static Core* instance;

    Core(MainWindow *wnd);

public:

    static Core* getInstance(MainWindow *wnd);
    void start();

    ~Core();
};

#endif // CORE_H

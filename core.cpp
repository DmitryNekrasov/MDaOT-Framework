#include "core.h"
#include <QDebug>

void Core::start() {
    qDebug() << "done!";

    Video video = Video(0);

    while (true) {
        if (!video.nextFrame().show("Motion"))
            break;
    }

    Frame::destroyWindow("Motion");

}

Core::Core()
{

}

Core::~Core()
{

}


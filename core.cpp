#include "core.h"
#include <QDebug>


Core *Core::instance;

void Core::start()
{

}

Core::Core(MainWindow *wnd)
{
    this->window = wnd;
}

Core *Core::getInstance(MainWindow *wnd)
{
    if (instance == NULL) {
        instance = new Core(wnd);
    }
    return instance;
}

Core::~Core()
{

}

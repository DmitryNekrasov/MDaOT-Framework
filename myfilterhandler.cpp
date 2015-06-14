#include "myfilterhandler.h"
#include "QDebug"

void MyFilterHandler::onApplyFilter(Frame frame) {
    // здесь нужно писать код обработки отфильтрованного фрейма
    frame.show("Filter");
}

MyFilterHandler::MyFilterHandler()
{

}

MyFilterHandler::~MyFilterHandler()
{

}


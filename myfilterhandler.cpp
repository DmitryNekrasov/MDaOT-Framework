#include "myfilterhandler.h"
#include "QDebug"

void MyFilterHandler::onApplyFilter(Frame frame) {
    frame.show("Filter handler work");
}

MyFilterHandler::MyFilterHandler()
{

}

MyFilterHandler::~MyFilterHandler()
{

}


#include "myfilterhandler.h"
#include "QDebug"


void MyFilterHandler::onApplyFilter(Frame frame)
{
    qDebug() << "Hello World!";
}

MyFilterHandler::MyFilterHandler() {

}

MyFilterHandler::~MyFilterHandler() {

}


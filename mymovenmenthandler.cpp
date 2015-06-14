#include "mymovenmenthandler.h"
#include "QDebug"
#include <QtGui>
#include "QString"

void MyMovenmentHandler::onMove(Frame frame) {
    // здесь нужно писать код обработки обнаруженного движущегося объекта
    frame.show("qaz");
}

MyMovenmentHandler::MyMovenmentHandler()
{

}

MyMovenmentHandler::~MyMovenmentHandler()
{

}


#include "mymovenmenthandler.h"
#include "QDebug"
#include <QtGui>
#include "QString"

int cnt = 0;
void MyMovenmentHandler::onMove(Frame frame) {
    qDebug() << "Move!!!";
    frame.show("qaz");
//    QImage image = frame.toQImage();
//    string path = "/Users/ScanNorOne/Desktop/temp/";
//    string num = std::to_string(cnt);
//    string jpg = ".jpg";
//    string res = path + num + jpg;
//    image.save(QString::fromStdString(res));
//    cnt++;
}

MyMovenmentHandler::MyMovenmentHandler()
{

}

MyMovenmentHandler::~MyMovenmentHandler()
{

}


#include <QCoreApplication>
#include <QThread>
#include "Controller.h"
#include "CThread.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

//    Controller *object = new Controller;
//    object->startThreadRunFunc(100);

    CThread *thread = new CThread;
    thread->calcSum(100);

    return a.exec();
}

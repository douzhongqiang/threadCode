#include <QCoreApplication>
#include "QtMutex.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QtMutexThread thread1;
    QtMutexThread thread2;
    QtMutexThread thread3;

    thread1.start();
    thread2.start();
    thread3.start();

    thread1.wait();
    thread2.wait();
    thread3.wait();

    return a.exec();
}

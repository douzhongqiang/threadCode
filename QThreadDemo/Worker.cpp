#include "Worker.h"
#include <QDebug>
#include <QThread>

Worker::Worker(QObject* parent)
    :QObject(parent)
{

}

Worker::~Worker()
{

}

void Worker::doWork(int count)
{
    int sum = 0;
    for (int i=0; i<=count; ++i)
        sum += i;

    qDebug() << __FUNCTION__ << "Thread ID: " << QThread::currentThreadId() << ", Result is " << sum;

    emit doFinished(sum);
}

#include "Controller.h"
#include "Worker.h"
#include <QDebug>

Controller::Controller(QObject* parent)
    :QObject (parent)
{
    Worker* worker = new Worker;
    worker->moveToThread(&m_thread);

    QObject::connect(this, &Controller::startCalcSum, worker, &Worker::doWork);
    QObject::connect(worker, &Worker::doFinished, this, &Controller::onCalcSumFinished);

    // 当线程退出时，释放工作者内存
    QObject::connect(&m_thread, &QThread::finished, worker, &Worker::deleteLater);

    m_thread.start();
}

Controller::~Controller()
{
    m_thread.quit();
    m_thread.wait();
}

void Controller::startThreadRunFunc(int number)
{
    // 发送开始计算信号
    emit startCalcSum(number);
    qDebug() << __FUNCTION__ << " : Current Thread is " << QThread::currentThreadId();
}

void Controller::onCalcSumFinished(int sum)
{
    // 打印行数名，当前线程ID，计算结果
    qDebug() << __FUNCTION__ \
             << " : Current Thread is " << QThread::currentThreadId() \
             << ", Result is " << sum;
}

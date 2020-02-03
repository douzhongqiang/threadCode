#include "CThread.h"
#include <QDebug>

CThread::CThread(QObject* parent)
    :QThread (parent)
    ,m_startThread(false)
    ,m_number(0)
{
    QObject::connect(this, &CThread::doFinished, this, &CThread::onDoFinished);
    this->start();
}

CThread::~CThread()
{
    this->requestInterruption();
    this->wait();
}

void CThread::run(void)
{
    while (!this->isInterruptionRequested())
    {
        // 判断是否开启线程计算
        if (!m_startThread)
        {
            QThread::msleep(20);
            continue;
        }

        // 计算 0 ~ m_number的和
        int number = m_number;
        int sum = 0;
        for (int i = 0; i<=number; ++i)
            sum += i;

        // 打印函数名，线程ID，结果
        qDebug() << __FUNCTION__ \
                 << " : Current Thread Id is " << QThread::currentThreadId() \
                 << ", Result is " << sum;

        m_startThread = false;

        // 发送信号
        emit doFinished(sum);
    }
}

// 计算前 0 ~ number的和
void CThread::calcSum(int number)
{
    m_number = number;
    m_startThread = true;
}

void CThread::onDoFinished(int sum)
{
    // 打印函数名，线程ID，结果
    qDebug() << __FUNCTION__ \
             << " : Current Thread Id is " << QThread::currentThreadId() \
             << ", Result is " << sum;
}

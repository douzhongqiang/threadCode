#include "CThread.h"

CThread::CThread(CThreadPoolData& data)
    :m_data(data)
{

}

CThread::~CThread()
{

}

void CThread::run(void)
{
    while (m_data.m_isRunning)
    {
        // 加锁并等待被唤醒
        QMutexLocker locker(&m_data.m_mutex);
        m_data.m_waitCondition.wait(&m_data.m_mutex);

        // 判断队列是否为空
        while (!m_data.m_taskList.isEmpty())
        {
            auto runnable = m_data.m_taskList.takeFirst();
            locker.unlock();

            // Do Task(无锁状态执行)
            runnable->run();

            locker.relock();
        }
    }
}

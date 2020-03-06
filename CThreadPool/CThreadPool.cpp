#include "CThreadPool.h"

CThreadPool::CThreadPool()
{
    // 设置线程池数目
    m_nThreadCount = QThread::idealThreadCount();

    // 创建线程池数组，并初始化
    for (int i=0; i<m_nThreadCount; ++i)
    {
        CThread *pThread = new CThread(m_poolData);
        m_threads.push_back(std::shared_ptr<CThread>(pThread));

        pThread->start();
    }
}

CThreadPool::~CThreadPool()
{
    // 等待线程全部退出
    m_poolData.m_isRunning = false;

    // 全部唤醒
    m_poolData.m_waitCondition.wakeAll();

    // 等待所有线程退出
    for (auto iter = m_threads.begin(); iter != m_threads.end(); ++iter)
        (*iter)->wait();
}

void CThreadPool::addTask(CRunnable* runnable)
{
    QMutexLocker locker(&m_poolData.m_mutex);
    // 添加到任务列表
    m_poolData.m_taskList.push_back(std::shared_ptr<CRunnable>(runnable));
    // 唤醒一个线程，如果当前没有休眠线程则该信号会被忽略
    m_poolData.m_waitCondition.wakeOne();
}

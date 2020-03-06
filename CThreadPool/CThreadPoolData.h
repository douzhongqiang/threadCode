#ifndef CTHREADPOOLDATA_H
#define CTHREADPOOLDATA_H

#include <QObject>
#include <QMutex>
#include <QWaitCondition>
#include <memory>
#include <atomic>
#include "CRunnable.h"

// 线程池相关数据类
class CThreadPoolData
{
public:
    CThreadPoolData();
    ~CThreadPoolData();

    // 任务列表
    QList<std::shared_ptr<CRunnable>> m_taskList;
    // 互斥锁和条件变量
    QMutex m_mutex;
    QWaitCondition m_waitCondition;
    // 结束线程控制
    std::atomic<bool> m_isRunning;
};

#endif

#include <QThread>
#include <QObject>
#include <QMutex>
#include <QMutexLocker>
#include "CRunnable.h"
#include "CThreadPoolData.h"
#include "CThread.h"

class CThreadPool
{
public:
    CThreadPool();
    ~CThreadPool();

    // 添加任务
    void addTask(CRunnable* runnable);

private:
    // 线程池
    QVector<std::shared_ptr<CThread>> m_threads;
    // 线程数目
    int m_nThreadCount = 8;

    // 数据
    CThreadPoolData m_poolData;
};

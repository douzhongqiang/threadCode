#ifndef CTHREAD_H
#define CTHREAD_H

#include <QThread>
#include <QWaitCondition>
#include "CThreadPoolData.h"

class CThread : public QThread
{
    Q_OBJECT

public:
    CThread(CThreadPoolData& data);
    ~CThread();

    void run(void) override;

private:
    CThreadPoolData& m_data;
};

#endif

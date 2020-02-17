#ifndef WINMUTEX_H
#define WINMUTEX_H

#include "CThread.h"
#include <QMutex>
class QtMutexThread : public CThread
{
public:
	void run(void) override;

private:
    static QMutex m_mutex;
};

#endif

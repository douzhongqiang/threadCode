#include "QtMutex.h"
#include <iostream>
#include <QMutexLocker>

QMutex QtMutexThread::m_mutex;
int number = 0;

void QtMutexThread::run(void)
{
	while (1)
	{
		{
            QMutexLocker locker(&m_mutex);
			std::cout << "Current Thread: " << ::GetCurrentThreadId() << ", Value: " << number++ << std::endl;
		}

		Sleep(1000);
	}
}

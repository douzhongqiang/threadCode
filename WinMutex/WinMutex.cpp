#include "WinMutex.h"
#include <iostream>

HANDLE WinMutexThread::m_mutexHandle = nullptr;
int number = 0;

void WinMutexThread::run(void)
{
	while (1)
	{
		if (::WaitForSingleObject(m_mutexHandle, INFINITE) == WAIT_OBJECT_0)
		{
			std::cout << "Current Thread: " << ::GetCurrentThreadId() << ", Value: " << number++ << std::endl;

			::ReleaseMutex(m_mutexHandle);
		}

		Sleep(1000);
	}
}

void WinMutexThread::initMutex(void)
{
	m_mutexHandle = ::CreateMutex(nullptr, FALSE, nullptr);
}

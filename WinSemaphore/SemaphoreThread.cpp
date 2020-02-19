#include "SemaphoreThread.h"
#include <iostream>
#include <atomic>

HANDLE g_semphore;
std::atomic<int> number(0);
void SemaphoreThread::run(void)
{
	if (::WaitForSingleObject(g_semphore, INFINITE) == WAIT_OBJECT_0)
	{
		number++;
		std::cout << "Custom " << ::GetCurrentThreadId() << ", Sit Down!" \
			<< " Your are " << number << "th Cunstom." << std::endl;

		::Sleep(300);

		::ReleaseSemaphore(g_semphore, 1, nullptr);
	}
	else
		std::cout << "Error!" << std::endl;
}

void SemaphoreThread::createSemaphore(int number)
{
	g_semphore = ::CreateSemaphore(nullptr, number, number, nullptr);
}

#include "WinAtomic.h"
#include <iostream>

LONG WinAtomic = 0;
void WinAtomicThread::run(void)
{
	while (1) {
		LONG count = ::InterlockedIncrement(&WinAtomic);
		std::cout << "Run in Thread ID " << ::GetCurrentThreadId() \
			      << " , Number is " << count << std::endl;
		
		Sleep(500);
	}
}

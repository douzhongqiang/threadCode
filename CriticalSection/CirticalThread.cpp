#include "CirticalThread.h"
#include "CCirticalSection.h"
#include <iostream>

int testValue = 0;
// 临界区对象
CRITICAL_SECTION g_cs;

void CirticalThread::run(void)
{
	while (1)
	{
		{
			CCirticalSection cs(g_cs);

			std::cout << "Test Value is " << testValue++ \
				<< ", In Thread: " << ::GetCurrentThreadId() \
				<< std::endl;
		}
		

		Sleep(1000);
	}
}

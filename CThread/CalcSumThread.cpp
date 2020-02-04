#include "CalcSumThread.h"
#include <iostream>

CalcSumThread::CalcSumThread()
{

}

CalcSumThread::~CalcSumThread()
{

}

void CalcSumThread::run(void)
{
	int sum = 0;
	for (int i = 0; i <= 100; ++i)
		sum += i;

	std::cout << "Current Thread ID is " << ::GetCurrentThreadId() << ", Result is " << sum << std::endl;
}

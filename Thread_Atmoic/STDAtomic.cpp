#include "STDAtomic.h"
#include <iostream>

std::atomic<int> STDAtomicValue(0);
void STDAtomicThread::run(void)
{
	while (1) {
		std::cout << "Run in Thread ID " << ::GetCurrentThreadId() \
			<< " , Number is " << STDAtomicValue++ << std::endl;

		Sleep(500);
	}
}

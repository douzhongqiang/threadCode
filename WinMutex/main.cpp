#include <iostream>
#include <stdlib.h>
#include "WinMutex.h"

int main(int argc, char** argv)
{
	WinMutexThread::initMutex();

	WinMutexThread thread1;
	WinMutexThread thread2;
	WinMutexThread thread3;

	thread1.start();
	thread2.start();
	thread3.start();

	thread1.wait();
	thread2.wait();
	thread3.wait();

	system("pause");
	return 0;
}

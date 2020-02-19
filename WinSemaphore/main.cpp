#include <iostream>
#include <stdlib.h>
#include "SemaphoreThread.h"

int main(int argc, char** argv)
{
	// 四个资源 - 餐馆4个座位
	SemaphoreThread::createSemaphore(4);

	// 创建6个线程，6个客人排队等待4个座位
	SemaphoreThread thread[6];
	for (int i = 0; i < 6; ++i)
		thread[i].start();

	for (int i = 0; i < 6; ++i)
		thread[i].wait();

	system("pause");
	return 0;
}

#ifndef SEMAPHORETHREAD_H
#define SEMAPHORETHREAD_H

#include "CThread.h"
class SemaphoreThread : public CThread
{
public:
	void run(void) override;

	// 创建信号量
	static void createSemaphore(int number);
};
#endif

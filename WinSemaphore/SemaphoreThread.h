#ifndef SEMAPHORETHREAD_H
#define SEMAPHORETHREAD_H

#include "CThread.h"
class SemaphoreThread : public CThread
{
public:
	void run(void) override;

	// �����ź���
	static void createSemaphore(int number);
};
#endif

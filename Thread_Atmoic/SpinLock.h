#ifndef SPINLOCK_H
#define SPINLOCK_H

#include "CThread.h"
#include <atomic>
#include <iostream>
class SpinLockThread1 : public CThread
{
public:
	void run(void) override;
};

class SpinLockThread2 : public CThread
{
public:
	void run(void) override;
};

#endif

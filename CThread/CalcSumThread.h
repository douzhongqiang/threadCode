#ifndef CALCSUMTHREAD_H
#define CALCSUMTHREAD_H

#include "CThread.h"
class CalcSumThread : public CThread
{
public:
	CalcSumThread();
	~CalcSumThread();

	void run(void) override;
};
#endif

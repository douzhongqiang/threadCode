#ifndef WINMUTEX_H
#define WINMUTEX_H

#include "CThread.h"
#include <Windows.h>
class WinMutexThread : public CThread
{
public:
	void run(void) override;

	// ≥ı ºªØMutex
	static void initMutex(void);

private:
	static HANDLE m_mutexHandle;
};

#endif

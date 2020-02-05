#ifndef WINATOMIC_H
#define WINATOMIC_H

#include "CThread.h"
#include <Windows.h>
class WinAtomicThread : public CThread
{
public:
	void run(void) override;
};

#endif

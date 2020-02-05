#ifndef STDATOMIC_H
#define STDATOMIC_H

#include "CThread.h"
#include <atomic>

class STDAtomicThread : public CThread
{
public:
	void run(void) override;
};
#endif

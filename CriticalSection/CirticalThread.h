#ifndef CIRTICALTHREAD_H
#define CIRTICALTHREAD_H

#include "CThread.h"
#include "Windows.h"

extern CRITICAL_SECTION g_cs;
class CirticalThread : public CThread
{
public:
	void run(void) override;
};
#endif

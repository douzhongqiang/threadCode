#ifndef CCIRTICALSECTION_H
#define CCIRTICALSECTION_H
#include <Windows.h>
class CCirticalSection
{
public:
	CCirticalSection(CRITICAL_SECTION& cs);
	~CCirticalSection();

private:
	CRITICAL_SECTION& m_cs;
};
#endif

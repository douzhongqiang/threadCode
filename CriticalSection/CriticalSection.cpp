#include "CCirticalSection.h"

CCirticalSection::CCirticalSection(CRITICAL_SECTION& cs)
	:m_cs(cs)
{
	// 进入临界区
	::EnterCriticalSection(&m_cs);
}

CCirticalSection::~CCirticalSection()
{
	// 离开临界区
	::LeaveCriticalSection(&m_cs);
}
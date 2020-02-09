#include "CCirticalSection.h"

CCirticalSection::CCirticalSection(CRITICAL_SECTION& cs)
	:m_cs(cs)
{
	// �����ٽ���
	::EnterCriticalSection(&m_cs);
}

CCirticalSection::~CCirticalSection()
{
	// �뿪�ٽ���
	::LeaveCriticalSection(&m_cs);
}
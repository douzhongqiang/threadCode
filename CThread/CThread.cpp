#include "CThread.h"
#include <iostream>

CThread::CThread()
{
	create();
}

CThread::~CThread()
{

}

void CThread::create(void)
{
	// �����߳�
	HANDLE handle = ::CreateThread(nullptr, 0, CThread::threadProc, this, CREATE_SUSPENDED, &m_nThreadId);

	// �ж��Ƿ񴴽��ɹ�
	if (handle)
	{
		m_isCreatedSuccess = true;
		std::cout << "Created Thread Success, Id is " << m_nThreadId << std::endl;
	}
	else
	{
		std::cout << "Created Thread Failed!!!" << std::endl;
		m_isCreatedSuccess = false;
	}

	m_threadHandle = handle;
}

// �����߳�
void CThread::start(void)
{
	if (!m_isCreatedSuccess)
		return;

	// �����߳�
	::ResumeThread(m_threadHandle);
}

// �ȴ��̺߳���
void CThread::wait(void)
{
	if (!m_isCreatedSuccess)
		return;

	::WaitForSingleObject(m_threadHandle, INFINITE);
}

DWORD WINAPI CThread::threadProc(LPVOID lpParameters)
{
	CThread* thisPointer = (CThread*)lpParameters;

	// �ж��߳��Ƿ񴴽��ɹ�
	if (!thisPointer->m_isCreatedSuccess)
		return 1;

	// ִ���Զ�����ں���
	thisPointer->run();
	return 0;
}

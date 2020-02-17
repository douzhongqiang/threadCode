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
	// 创建线程
	HANDLE handle = ::CreateThread(nullptr, 0, CThread::threadProc, this, CREATE_SUSPENDED, &m_nThreadId);

	// 判断是否创建成功
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

// 启动线程
void CThread::start(void)
{
	if (!m_isCreatedSuccess)
		return;

	// 启动线程
	::ResumeThread(m_threadHandle);
}

// 等待线程函数
void CThread::wait(void)
{
	if (!m_isCreatedSuccess)
		return;

	::WaitForSingleObject(m_threadHandle, INFINITE);
}

DWORD WINAPI CThread::threadProc(LPVOID lpParameters)
{
	CThread* thisPointer = (CThread*)lpParameters;

	// 判断线程是否创建成功
	if (!thisPointer->m_isCreatedSuccess)
		return 1;

	// 执行自定义入口函数
	thisPointer->run();
	return 0;
}

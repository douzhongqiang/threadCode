#ifndef CTHREAD_H
#define CTHREAD_H

#include <Windows.h>

class CThread
{
public:
	CThread();
	~CThread();

	// 线程入口函数
	virtual void run(void) = 0;

	// 启动线程
	void start(void);

	// 等待线程函数
	void wait(void);

private:
	static DWORD WINAPI threadProc(LPVOID lpParameters);
	// 创建线程
	void create(void);

	// 线程ID
	DWORD m_nThreadId = 0;
	// 判断线程是否创建成功
	bool m_isCreatedSuccess = true;
	// 线程句柄
	HANDLE m_threadHandle = nullptr;
};
#endif

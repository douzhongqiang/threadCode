#ifndef CTHREAD_H
#define CTHREAD_H

#include <Windows.h>

class CThread
{
public:
	CThread();
	~CThread();

	// �߳���ں���
	virtual void run(void) = 0;

	// �����߳�
	void start(void);

	// �ȴ��̺߳���
	void wait(void);

private:
	static DWORD WINAPI threadProc(LPVOID lpParameters);
	// �����߳�
	void create(void);

	// �߳�ID
	DWORD m_nThreadId = 0;
	// �ж��߳��Ƿ񴴽��ɹ�
	bool m_isCreatedSuccess = true;
	// �߳̾��
	HANDLE m_threadHandle = nullptr;
};
#endif

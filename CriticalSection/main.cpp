#include <iostream>
#include <stdlib.h>
#include <Windows.h>
#include "CirticalThread.h"

int main(int argc, char** argv)
{
	// ��ʼ���ٽ�������
	::InitializeCriticalSection(&g_cs);

	// ���������߳�
	CirticalThread thread1;
	CirticalThread thread2;

	// �����߳�
	thread1.start();
	thread2.start();

	// �ȴ�
	thread1.wait();
	thread2.wait();

	// �����ٽ�������
	::DeleteCriticalSection(&g_cs);

	system("pause");
	return 0;
}

#include <iostream>
#include <stdlib.h>
#include <Windows.h>
#include "CirticalThread.h"

int main(int argc, char** argv)
{
	// 初始化临界区对象
	::InitializeCriticalSection(&g_cs);

	// 创建两个线程
	CirticalThread thread1;
	CirticalThread thread2;

	// 开启线程
	thread1.start();
	thread2.start();

	// 等待
	thread1.wait();
	thread2.wait();

	// 销毁临界区对象
	::DeleteCriticalSection(&g_cs);

	system("pause");
	return 0;
}

#include <iostream>
#include <stdlib.h>
#include "WinAtomic.h"
#include "STDAtomic.h"
#include "SpinLock.h"

int main(int argc, char** argv)
{
	// Win原子操作测试
	/*WinAtomicThread *thread1 = new WinAtomicThread;
	WinAtomicThread *thread2 = new WinAtomicThread;*/

	// STL原子操作
	/*STDAtomicThread *thread1 = new STDAtomicThread;
	STDAtomicThread *thread2 = new STDAtomicThread;*/

	// 自旋锁
	SpinLockThread1 *thread1 = new SpinLockThread1;
	SpinLockThread2 *thread2 = new SpinLockThread2;

	thread1->start();
	thread2->start();

	thread1->wait();
	thread2->wait();

	system("pause");
	return 0;
}

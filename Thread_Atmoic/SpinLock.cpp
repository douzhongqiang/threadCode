#include "SpinLock.h"

std::atomic_flag lock{1};

void SpinLockThread1::run(void)
{
	std::cout << "Start Run Thread1" << std::endl;
	// 自旋等待
	while (lock.test_and_set(std::memory_order_acquire))
		std::cout << "Wait For UnLock" << std::endl;
	std::cout << "End Run Thread1" << std::endl;
}

void SpinLockThread2::run(void)
{
	std::cout << "Start Run Thread2" << std::endl;
	Sleep(20);
	std::cout << "Thread2 Free Lock" << std::endl;
	// 解自旋锁
	lock.clear();
}
#include <iostream>
#include <stdlib.h>
#include "SemaphoreThread.h"

int main(int argc, char** argv)
{
	// �ĸ���Դ - �͹�4����λ
	SemaphoreThread::createSemaphore(4);

	// ����6���̣߳�6�������Ŷӵȴ�4����λ
	SemaphoreThread thread[6];
	for (int i = 0; i < 6; ++i)
		thread[i].start();

	for (int i = 0; i < 6; ++i)
		thread[i].wait();

	system("pause");
	return 0;
}

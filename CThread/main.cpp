#include "CalcSumThread.h"
#include <stdlib.h>

int main(int argc, char *argv[])
{
	CalcSumThread* thread = new CalcSumThread;
	thread->start();	// �����߳�
	thread->wait();		// �ȴ��߳̽���

	system("pause");
	return 0;
}

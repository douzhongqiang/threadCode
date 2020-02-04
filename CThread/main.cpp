#include "CalcSumThread.h"
#include <stdlib.h>

int main(int argc, char *argv[])
{
	CalcSumThread* thread = new CalcSumThread;
	thread->start();	// 开启线程
	thread->wait();		// 等待线程结束

	system("pause");
	return 0;
}

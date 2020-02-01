#include <stdlib.h>
#include <iostream>
#include <thread>
#include <Windows.h>
#include <sstream>

int stdThreadIdToInt(const std::thread::id& id)
{
	std::stringstream oss;
	oss << id;
	std::string string = oss.str();
	int threadId = atol(string.c_str());

	return threadId;
}

// 线程中执行的函数
void threadProc(int count)
{
	bool isRunThread = true;
	while (isRunThread)
	{
		static int number = 0;
		if (number >= count)
		{
			// 仅执行Count次打印
			isRunThread = false;
			break;
		}
		std::cout << "This is Run in Thread ID:" << std::this_thread::get_id() << ", Number is :" << number++ << std::endl;
		std::cout << "This is Run in Thread ID:" << stdThreadIdToInt(std::this_thread::get_id()) << ", Number is :" << number++ << std::endl;

		Sleep(200);
	}
}

// C++11 创建线程
std::thread createWindowsThread(void)
{
	std::thread thread(threadProc, 5);

	return thread;
}

int main(int argc, char** argv)
{
	std::thread thread = createWindowsThread();
	if (thread.joinable())
		thread.join();

	std::cout << "Created Thread Finished!" << std::endl;

	system("pause");
	return 0;
}

#include <stdlib.h>
#include <iostream>
#include <Windows.h>

DWORD WINAPI threadProc(LPVOID lpParameters)
{
	bool isRunThread = true;
	while (isRunThread)
	{
		static int number = 0;
		if (number >= 5)
		{
			// 仅执行5次打印
			isRunThread = false;
			break;
		}
		std::cout << "This is Run in Thread ID:" << ::GetCurrentThreadId() <<  ", Number is :" << number++ << std::endl;

		Sleep(200);
	}
	
	return 0;
}

// Windows API 创建线程
HANDLE createWindowsThread(DWORD *threadId)
{
	HANDLE handle = ::CreateThread(nullptr, 0, threadProc, nullptr, 0, threadId);

	return handle;
}

int main_windowsAPI(int argc, char** argv)
{
	DWORD threadId = 0;
	HANDLE threadHandle = createWindowsThread(&threadId);
	if (threadHandle)
	{
		std::cout << "Create Thread Success! Thread ID is " << threadId << std::endl;
		std::cout << "Main Thread ID is " << ::GetCurrentThreadId() << std::endl;
		::WaitForSingleObject(threadHandle, INFINITE);
	}
	else
		std::cout << "Create Thread Error!" << std::endl;

	system("pause");
	return 0;
}

#include "TestTaskRunnable.h"
#include <iostream>
#include <atomic>
#include <QThread>

std::atomic<int> g_number(0);

void TestTaskRunnable::run(void)
{
    std::cout << "Number is " << g_number++ \
              << ", Thread Id is " << QThread::currentThreadId() \
              << std::endl;
}

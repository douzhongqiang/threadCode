#include <QCoreApplication>
#include "CThreadPool.h"
#include "TestTaskRunnable.h"
#include "stdlib.h"

int main(int argc, char *argv[])
{
    CThreadPool threadpool;
    for (int i = 0; i < 20; ++i)
    {
        TestTaskRunnable* taskRunnable = new TestTaskRunnable;
        threadpool.addTask(taskRunnable);
    }

    system("pause");
    return 0;
}

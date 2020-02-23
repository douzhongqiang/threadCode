#include "Consumer.h"
#include "CustomDataInfo.h"
#include <iostream>
#include <QDebug>

void ConsumerThread::run(void)
{
    while (1)
    {
        g_mutex.lock();
        // 等待
        if (g_nCurrentCreated == 0)
            g_notEmptyCondition.wait(&g_mutex);
        g_mutex.unlock();

        // 消费数据
        std::cout << "Read Value: " << g_data[g_nStartIndex] \
                  << ", Index is " << g_nStartIndex << std::endl;

        g_nStartIndex++;
        if (g_nStartIndex == 20)
            g_nStartIndex = 0;

        ::Sleep(2000);

        // 释放资源
        g_mutex.lock();
        g_nCurrentCreated--;
        g_notFullCondition.wakeAll();
        g_mutex.unlock();
    }
}

#include "Producer.h"
#include "CustomDataInfo.h"
#include <iostream>

void ProducerThread::run(void)
{
    while (1)
    {
        g_mutex.lock();
        if (g_nCurrentCreated == 20)
            g_notFullCondition.wait(&g_mutex);
        g_mutex.unlock();

        // 生产数据
        g_data[g_nEndIndex] = number;
        std::cout << "Created Data: " << number++ << ", Index is " << g_nEndIndex << std::endl;

        g_nEndIndex++;
        if (g_nEndIndex == 20)
            g_nEndIndex = 0;

        ::Sleep(100);

        g_mutex.lock();
        g_nCurrentCreated++;
        g_notEmptyCondition.wakeAll();
        g_mutex.unlock();
    }
}



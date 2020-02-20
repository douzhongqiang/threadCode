#include "Producer.h"
#include "CustomDataInfo.h"
#include <iostream>

void ProducerThread::run(void)
{
    while (1)
    {
        // 请求一个资源
        g_semaphore.acquire(1);

        // 生产数据
        g_data[g_nEndIndex] = number;
        std::cout << "Created Data: " << number++ << ", Index is " << g_nEndIndex << std::endl;

        g_nEndIndex++;
        if (g_nEndIndex == 20)
            g_nEndIndex = 0;

        ::Sleep(100);
        g_nCurrentCreated++;
    }
}



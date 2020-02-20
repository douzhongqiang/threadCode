#include "Consumer.h"
#include "CustomDataInfo.h"
#include <iostream>

void ConsumerThread::run(void)
{
    while (1)
    {
        // 自旋等待
        while (g_nCurrentCreated <= 0);

        // 消费数据
        std::cout << "Read Value: " << g_data[g_nStartIndex] \
                  << ", Index is " << g_nStartIndex << std::endl;

        g_nStartIndex++;
        if (g_nStartIndex == 20)
            g_nStartIndex = 0;

        ::Sleep(2000);

        // 释放资源
        g_nCurrentCreated--;
        g_semaphore.release();
    }
}

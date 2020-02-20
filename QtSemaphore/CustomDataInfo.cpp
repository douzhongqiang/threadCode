#include "CustomDataInfo.h"

int g_data[20] = {-1};
QSemaphore g_semaphore(20);
std::atomic<int> g_nStartIndex(0);
std::atomic<int> g_nEndIndex(0);
std::atomic<int> g_nCurrentCreated(0);

#ifndef CUSTOMDATAINFO_H
#define CUSTOMDATAINFO_H

#include <QSemaphore>
#include <atomic>

extern "C" int g_data[20];
extern "C" QSemaphore g_semaphore;
extern "C" std::atomic<int> g_nStartIndex;
extern "C" std::atomic<int> g_nEndIndex;
extern "C" std::atomic<int> g_nCurrentCreated;

#endif

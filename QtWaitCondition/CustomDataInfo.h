#ifndef CUSTOMDATAINFO_H
#define CUSTOMDATAINFO_H

#include <QSemaphore>
#include <QWaitCondition>
#include <QMutex>
#include <atomic>

extern "C" int g_data[20];
extern "C" int g_nStartIndex;
extern "C" int g_nEndIndex;
extern "C" int g_nCurrentCreated;
extern "C" QWaitCondition g_notFullCondition;
extern "C" QWaitCondition g_notEmptyCondition;
extern "C" QMutex g_mutex;

#endif

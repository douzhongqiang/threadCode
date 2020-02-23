#include "CustomDataInfo.h"

int g_data[20] = {-1};
int g_nStartIndex = 0;
int g_nEndIndex = 0;
int g_nCurrentCreated = 0;
QWaitCondition g_notFullCondition;
QWaitCondition g_notEmptyCondition;
QMutex g_mutex;

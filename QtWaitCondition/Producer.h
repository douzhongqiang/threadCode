#ifndef PRODUCER_H
#define PRODUCER_H

#include "CThread.h"

class ProducerThread : public CThread
{
public:
    // 生产者
    void run(void) override;

private:
    int number = 0;
};

#endif

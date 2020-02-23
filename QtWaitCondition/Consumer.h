#ifndef CONSUMER_H
#define CONSUMER_H

#include "CThread.h"
class ConsumerThread : public CThread
{
public:
    void run(void) override;
};

#endif

#ifndef CRUNNABLE_H
#define CRUNNABLE_H

class CRunnable
{
public:
    CRunnable();
    virtual ~CRunnable();

    virtual void run(void) = 0;
};

#endif

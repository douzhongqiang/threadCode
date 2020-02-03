#ifndef WORKER_H
#define WORKER_H

#include <QObject>
class Worker : public QObject
{
    Q_OBJECT

public:
    Worker(QObject* parent = nullptr);
    ~Worker();

public slots:
    // 计算前count个数的和
    void doWork(int count);

signals:
    // 发送计算完成信号
    void doFinished(int);
};

#endif

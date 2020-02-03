#ifndef CTHREAD_H
#define CTHREAD_H

#include <QThread>
#include <atomic>
class CThread : public QThread
{
    Q_OBJECT

public:
    CThread(QObject* parent = nullptr);
    ~CThread();

    // 线程入口函数
    void run(void) override;

    // 计算前 0 ~ number的和
    void calcSum(int number);

private:
    std::atomic<bool> m_startThread;
    std::atomic<int> m_number;

signals:
    // 发送计算完成信号
    void doFinished(int);

private slots:
    // 相应计算完成结果
    void onDoFinished(int sum);
};

#endif

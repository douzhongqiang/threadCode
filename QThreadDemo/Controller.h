#ifndef MYOBJECT_H
#define MYOBJECT_H

#include <QObject>
#include <QThread>

class Controller : public QObject
{
    Q_OBJECT

public:
    Controller(QObject* parent = nullptr);
    ~Controller();

    // 开启线程计算
    void startThreadRunFunc(int number);

private:
    QThread m_thread;

signals:
    void startCalcSum(int);

private slots:
    // 接受计算完毕后的结果槽函数
    void onCalcSumFinished(int sum);
};

#endif

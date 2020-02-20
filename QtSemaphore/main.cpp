#include <QCoreApplication>
#include "Consumer.h"
#include "Producer.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // 创建生产者和消费者
    ConsumerThread consumer;
    ProducerThread producer;
    consumer.start();
    producer.start();

    consumer.wait();
    producer.wait();

    return a.exec();
}

#include "Consumer.h"
#include "Producer.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    ConsumerThread consumerThread;
    ProducerThread producerThread;

    consumerThread.start();
    producerThread.start();

    consumerThread.wait();
    producerThread.wait();

    return a.exec();
}

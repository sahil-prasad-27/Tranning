#ifndef WORKER_H
#define WORKER_H

#include <QObject>
#include <QThread>
#include <QDebug>

class Worker : public QObject
{
    Q_OBJECT
public:
    explicit Worker(QObject *parent = nullptr) : QObject(parent) {}

public slots:
    void doWork(int value) {
        qDebug() << "Worker slot received:" << value << "in thread" << QThread::currentThread();
    }
};

#endif // WORKER_H

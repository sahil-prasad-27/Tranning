#include "mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    centralWidget = new QWidget(this);
    layout = new QVBoxLayout(centralWidget);
    btnEmitSignals = new QPushButton("Emit Signals", this);
    layout->addWidget(btnEmitSignals);
    setCentralWidget(centralWidget);

    // Move worker to thread
    worker.moveToThread(&workerThread);
    workerThread.start();

    // Button click emits all signals
    connect(btnEmitSignals, &QPushButton::clicked, this, [=]() {
        emit signalAuto(1);
        emit signalDirect(2);
        emit signalQueued(3);
        emit signalBlocking(4);
        emit signalUnique(5);
        emit signalSingleShot(6);

        // SingleShot triggers only once
        emit signalSingleShot(6);
    });

    // ===== Connections =====

    // 1. AutoConnection
    connect(this, &MainWindow::signalAuto,
            this, &MainWindow::receiveSlot,
            Qt::AutoConnection);

    // 2. DirectConnection
    connect(this, &MainWindow::signalDirect,
            this, &MainWindow::receiveSlot,
            Qt::DirectConnection);

    // 3. QueuedConnection (cross-thread)
    connect(this, &MainWindow::signalQueued,
            &worker, &Worker::doWork,
            Qt::QueuedConnection);

    // 4. BlockingQueuedConnection (cross-thread)
    connect(this, &MainWindow::signalBlocking,
            &worker, &Worker::doWork,
            Qt::BlockingQueuedConnection);

    // 5. UniqueConnection
    connect(this, &MainWindow::signalUnique,
            this, &MainWindow::receiveSlot,
            Qt::AutoConnection | Qt::UniqueConnection);

    // 6. SingleShotConnection
    connect(this, &MainWindow::signalSingleShot,
            this, &MainWindow::receiveSlot,
            Qt::SingleShotConnection);
}

MainWindow::~MainWindow()
{
    workerThread.quit();
    workerThread.wait();
}

void MainWindow::receiveSlot(int value)
{
    qDebug() << "Slot received value:" << value << "in thread" << QThread::currentThread();
}

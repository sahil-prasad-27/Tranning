#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QVBoxLayout>
#include "worker.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void signalAuto(int value);
    void signalDirect(int value);
    void signalQueued(int value);
    void signalBlocking(int value);
    void signalUnique(int value);
    void signalSingleShot(int value);

public slots:
    void receiveSlot(int value);

private:
    QWidget *centralWidget;
    QVBoxLayout *layout;
    QPushButton *btnEmitSignals;
    Worker worker;
    QThread workerThread;
};

#endif // MAINWINDOW_H

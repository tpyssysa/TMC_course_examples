/***************************************************************************
*                                                                          *
*                main.cpp for 00_concurrent_tasks                          *
*                Created on  : Thu Mar 23 2017 12:16                       *
*                Made by : Qt training <training@qt.io>                    *
*                                                                          *
***************************************************************************/

#include <QCoreApplication>
#include <QtConcurrent>

static int fibonacci(int x)
{
    if (x == 0)
        return 0;
    else if (x == 1)
        return 1;
    return (fibonacci(x - 1) + fibonacci(x - 2));
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QFuture<int> task1 = QtConcurrent::run(fibonacci, 6);
    QFuture<int> task2 = QtConcurrent::run(fibonacci, 7);
    QFuture<int> task3 = QtConcurrent::run(fibonacci, 8);
    QFuture<int> task4 = QtConcurrent::run(fibonacci, 9);
    QFuture<int> task5 = QtConcurrent::run(fibonacci, 10);

    QFutureWatcher<int> task1Watcher;
    task1Watcher.setFuture(task1);
    QFutureWatcher<int> task2Watcher;
    task2Watcher.setFuture(task2);
    QFutureWatcher<int> task3Watcher;
    task3Watcher.setFuture(task3);
    QFutureWatcher<int> task4Watcher;
    task4Watcher.setFuture(task4);
    QFutureWatcher<int> task5Watcher;
    task5Watcher.setFuture(task5);

    QObject::connect(&task1Watcher, &QFutureWatcher<int>::finished, [&task1] () {
        qDebug() << task1.result();
    });
    QObject::connect(&task2Watcher, &QFutureWatcher<int>::finished, [&task2] () {
        qDebug() << task2.result();
    });
    QObject::connect(&task3Watcher, &QFutureWatcher<int>::finished, [&task3] () {
        qDebug() << task3.result();
    });
    QObject::connect(&task4Watcher, &QFutureWatcher<int>::finished, [&task4] () {
        qDebug() << task4.result();
    });
    QObject::connect(&task5Watcher, &QFutureWatcher<int>::finished, [&a, &task5] () {
        qDebug() << task5.result();
        a.quit();
    });

    return a.exec();
}

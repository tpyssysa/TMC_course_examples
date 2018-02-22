/***************************************************************************
*                                                                          *
*                main.cpp for 03_mutual_exclusion                          *
*                Created on  : Mon Mar 27 2017 12:17                       *
*                Made by : Qt training <training@qt.io>                    *
*                                                                          *
***************************************************************************/

#include "thread.h"
#include "reentrantclass.h"
#include <QApplication>
#include <QPushButton>
#include <QSharedPointer>
#include <QtDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QSharedPointer<ReentrantClass> sharedObject(new ReentrantClass);

    Thread thread(sharedObject);
    thread.start();

    QPushButton button("Increment counter");
    button.connect(&button, &QPushButton::clicked, [&sharedObject] () {
        qDebug() << "Current counter value" << sharedObject.data()->counter();
        sharedObject.data()->incCounter();
    });
    a.connect(&a, &QApplication::aboutToQuit, [&thread] () {
        thread.requestInterruption();
    });
    button.resize(300,100);
    button.show();

    return a.exec();
}

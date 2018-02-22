/***************************************************************************
*                                                                          *
*                producer.cpp for 04_thread_synchronisation                *
*                Created on  : Tue Mar 28 2017 08:48                       *
*                Made by : Qt training <training@qt.io>                    *
*                                                                          *
***************************************************************************/

#include "producer.h"
#include "globalbuffer.h"
#include <QTime>
#include <QtDebug>

Producer::Producer(QObject *parent) :
    QThread(parent)
{
}

void Producer::run()
{
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    for (int i = 0; i < DataSize; ++i) {
        WriteSemaphore::globalWriteSemaphore()->acquire();
        Buffer::globalBuffer()->insert(i % BufferSize, "ACGT"[(int)qrand() % 4]);
        ReadSemaphore::globalReadSemaphore()->release();
    }
}

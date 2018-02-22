/***************************************************************************
*                                                                          *
*                consumer.cpp for 04_thread_synchronisation                *
*                Created on  : Tue Mar 28 2017 08:49                       *
*                Made by : Qt training <training@qt.io>                    *
*                                                                          *
***************************************************************************/

#include "consumer.h"
#include "globalbuffer.h"
#include <QtDebug>

Consumer::Consumer(QObject *parent) :
    QThread(parent)
{
}

void Consumer::run()
{
    for (int i = 0; i < DataSize; ++i) {
        ReadSemaphore::globalReadSemaphore()->acquire();
        qDebug() <<  Buffer::globalBuffer()->at(i % BufferSize);
        WriteSemaphore::globalWriteSemaphore()->release();
    }
}

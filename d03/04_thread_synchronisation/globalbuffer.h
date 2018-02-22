/***************************************************************************
*                                                                          *
*                globalbuffer.h for 04_thread_synchronisation              *
*                Created on  : Tue Mar 28 2017 12:03                       *
*                Made by : Qt training <training@qt.io>                    *
*                                                                          *
***************************************************************************/

#ifndef GLOBALBUFFER_H
#define GLOBALBUFFER_H

#include <QSemaphore>
#include <QByteArray>

const int DataSize = 64;
const int BufferSize = 8;

class Buffer : public QByteArray
{
public:
    static Buffer *globalBuffer();
};

class ReadSemaphore : public QSemaphore
{
public:
    static ReadSemaphore *globalReadSemaphore();
};

class WriteSemaphore : public QSemaphore
{
public:
    WriteSemaphore(int size);
    static WriteSemaphore *globalWriteSemaphore();
};

#endif // GLOBALBUFFER_H

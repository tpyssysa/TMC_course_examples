/***************************************************************************
*                                                                          *
*                globalbuffer.cpp for 04_thread_synchronisation            *
*                Created on  : Tue Mar 28 2017 12:26                       *
*                Made by : Qt training <training@qt.io>                    *
*                                                                          *
***************************************************************************/

#include "globalbuffer.h"
#include <QGlobalStatic>

Q_GLOBAL_STATIC(Buffer, buffer)
Q_GLOBAL_STATIC(ReadSemaphore, readSemaphore)
Q_GLOBAL_STATIC_WITH_ARGS(WriteSemaphore, writeSemaphore, (BufferSize))

Buffer *Buffer::globalBuffer()
{
    return buffer;
}

ReadSemaphore *ReadSemaphore::globalReadSemaphore()
{
    return readSemaphore;
}

WriteSemaphore::WriteSemaphore(int size)
    : QSemaphore(size)
{
}

WriteSemaphore *WriteSemaphore::globalWriteSemaphore()
{
    return writeSemaphore;
}



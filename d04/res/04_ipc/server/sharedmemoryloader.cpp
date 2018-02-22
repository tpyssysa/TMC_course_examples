/***************************************************************************
*                                                                          *
*                sharedmemoryloader.cpp for 04_ipc                         *
*                Created on  : Mon Apr 04 2017 12:12                       *
*                Made by : Qt training <training@qt.io>                    *
*                                                                          *
***************************************************************************/

#include "sharedmemoryloader.h"
#include <QLabel>

SharedMemoryLoader::SharedMemoryLoader(QLabel *imageLabel, QLabel *textLabel, QObject *parent) :
    QObject(parent),
    m_imageLabel(imageLabel),
    m_textLabel(textLabel),
{
}

void SharedMemoryLoader::loadFromSharedMemory()
{
}


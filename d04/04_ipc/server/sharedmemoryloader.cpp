/***************************************************************************
*                                                                          *
*                sharedmemoryloader.cpp for 04_ipc                         *
*                Created on  : Mon Apr 04 2017 12:12                       *
*                Made by : Qt training <training@qt.io>                    *
*                                                                          *
***************************************************************************/

#include "sharedmemoryloader.h"
#include <QLabel>
#include <QBuffer>

SharedMemoryLoader::SharedMemoryLoader(QLabel *imageLabel, QLabel *textLabel, QObject *parent) :
    QObject(parent),
    m_imageLabel(imageLabel),
    m_textLabel(textLabel),
    m_sharedMemory("SharedMemoryKey")
{
}

void SharedMemoryLoader::loadFromSharedMemory()
{
    if (!m_sharedMemory.isAttached()) {
        if (!m_sharedMemory.attach()) {
            m_textLabel->setText(tr("Unable to attach to shared memory segment."));
            return;
        }
    }

    QBuffer buffer;
    QDataStream in(&buffer);
    QImage image;

    m_sharedMemory.lock();
    buffer.setData((char *) m_sharedMemory.constData(), m_sharedMemory.size());
    buffer.open(QBuffer::ReadOnly);
    in >> image;
    m_sharedMemory.unlock();

    m_sharedMemory.detach();
    m_imageLabel->setPixmap(QPixmap::fromImage(image));
    m_textLabel->setText(tr("New image loaded from shared memory."));
}


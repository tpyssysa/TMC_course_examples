/***************************************************************************
*                                                                          *
*                sharedmemoryloader.h for 04_ipc                           *
*                Created on  : Mon Apr 04 2017 12:12                       *
*                Made by : Qt training <training@qt.io>                    *
*                                                                          *
***************************************************************************/

#ifndef SHAREDMEMORYLOADER_H
#define SHAREDMEMORYLOADER_H

#include <QObject>
#include <QSharedMemory>

QT_FORWARD_DECLARE_CLASS(QLabel)

class SharedMemoryLoader : public QObject
{
    Q_OBJECT
public:
    explicit SharedMemoryLoader(QLabel *imageLabel, QLabel *textLabel, QObject *parent = 0);

public Q_SLOTS:
    void loadFromSharedMemory();

private:
    QLabel *m_imageLabel;
    QLabel *m_textLabel;
    QSharedMemory m_sharedMemory;
};
#endif // SHAREDMEMORYLOADER_H

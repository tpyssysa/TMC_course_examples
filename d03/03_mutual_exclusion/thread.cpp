/***************************************************************************
*                                                                          *
*                thread.cpp for 03_mutual_exclusion                        *
*                Created on  : Tue Mar 28 2017 07:44                       *
*                Made by : Qt training <training@qt.io>                    *
*                                                                          *
***************************************************************************/

#include "thread.h"
#include "reentrantclass.h"
#include <QTimer>
#include <QtDebug>

Thread::Thread(QSharedPointer<ReentrantClass> sharedObject, QObject *parent) :
    QThread(parent),
    m_sharedObject(sharedObject)
{
}

void Thread::run()
{
    Q_FOREVER {
        m_sharedObject.data()->incCounter();
        m_sharedObject.data()->decCounter();
        if ((m_sharedObject.data()->counter() > 10) || isInterruptionRequested()) {
            break;
        }
    }

    qDebug() << "Worker thread is going to finish";
}

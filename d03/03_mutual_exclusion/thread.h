/***************************************************************************
*                                                                          *
*                thread.h for 03_mutual_exclusion                          *
*                Created on  : Tue Mar 28 2017 07:44                       *
*                Made by : Qt training <training@qt.io>                    *
*                                                                          *
***************************************************************************/

#ifndef THREAD_H
#define THREAD_H

#include <QThread>
#include <QSharedPointer>

class ReentrantClass;

class Thread : public QThread
{
public:
    Thread(QSharedPointer<ReentrantClass> sharedObject, QObject *parent = 0);
protected:
    void run() Q_DECL_OVERRIDE;

private:
    QSharedPointer<ReentrantClass> m_sharedObject;
};

#endif // THREAD_H


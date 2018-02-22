/***************************************************************************
*                                                                          *
*                producer.h for 04_thread_synchronisation                *
*                Created on  : Tue Mar 28 2017 08:48                       *
*                Made by : Qt training <training@qt.io>                    *
*                                                                          *
***************************************************************************/

#ifndef PRODUCER_H
#define PRODUCER_H

#include <QThread>

class Producer : public QThread
{
public:
    Producer(QObject *parent = 0);
protected:
    void run() Q_DECL_OVERRIDE;
};

#endif // PRODUCER_H

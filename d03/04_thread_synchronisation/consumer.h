/***************************************************************************
*                                                                          *
*                consumer.h for 04_thread_synchronisation                  *
*                Created on  : Tue Mar 28 2017 08:49                       *
*                Made by : Qt training <training@qt.io>                    *
*                                                                          *
***************************************************************************/

#ifndef CONSUMER_H
#define CONSUMER_H

#include <QThread>

class Consumer : public QThread
{
public:
    Consumer(QObject *parent = 0);
protected:
    void run() Q_DECL_OVERRIDE;
};

#endif // CONSUMER_H

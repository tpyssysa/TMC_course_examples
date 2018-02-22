/***************************************************************************
*                                                                          *
*                receiver.h for 03_object_communication_signals            *
*                Created on  : Thu Mar 09 2017 12:58                       *
*                Made by : Qt training <training@qt.io>                    *
*                                                                          *
***************************************************************************/

#ifndef RECEIVER_H
#define RECEIVER_H

#include <QObject>

class Receiver : public QObject
{
    Q_OBJECT
public:
    explicit Receiver(QObject *parent = 0);

signals:

public slots:
    void receiverSlot(const QString &, int) const;
};

#endif // RECEIVER_H

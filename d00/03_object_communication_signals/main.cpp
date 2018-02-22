/***************************************************************************
*                                                                          *
*                main.cpp for 03_object_communication_signals              *
*                Created on  : Thu Mar 09 2017 12:55                       *
*                Made by : Qt training <training@qt.io>                    *
*                                                                          *
***************************************************************************/

#include "sender.h"
#include "receiver.h"
#include <QtDebug>

int main(int, char **)
{
    Sender sender;
    Receiver receiver;

    receiver.connect(&sender, qOverload<const QString &, int>(&Sender::nameChanged), &receiver, &Receiver::receiverSlot);
    sender.setObjectName("Sender");

    sender.connect(&sender, &Sender::destroyed, [] () {
        qDebug() << "Sender destroyed";
    });

    return 0;
}

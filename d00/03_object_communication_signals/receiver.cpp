/***************************************************************************
*                                                                          *
*                receiver.cpp for 03_object_communication_signals          *
*                Created on  : Thu Mar 09 2017 12:58                       *
*                Made by : Qt training <training@qt.io>                    *
*                                                                          *
***************************************************************************/

#include "receiver.h"
#include <QtDebug>

Receiver::Receiver(QObject *parent) : QObject(parent)
{

}

void Receiver::receiverSlot(const QString &name, int number) const
{
    qDebug() << "Receiver says" << name << number;
    QString *namePtr(const_cast<QString *>(&name));
    *namePtr = QString("New Sender name set by the receiver");
}

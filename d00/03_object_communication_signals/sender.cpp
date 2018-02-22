/***************************************************************************
*                                                                          *
*                sender.cpp for 03_object_communication_signals            *
*                Created on  : Thu Mar 09 2017 13:02                       *
*                Made by : Qt training <training@qt.io>                    *
*                                                                          *
***************************************************************************/

#include "sender.h"
#include <QtDebug>

Sender::Sender(QObject *parent) : QObject(parent)
{
    connect(this, &Sender::objectNameChanged, this, QOverload<const QString &>::of(&Sender::changeName));
}

void Sender::changeName(const QString &name)
{
    emit nameChanged(name, 42);
    setObjectName(name);
    qDebug() << "Sender says" << objectName();
}



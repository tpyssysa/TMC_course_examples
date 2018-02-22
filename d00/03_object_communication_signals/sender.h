/***************************************************************************
*                                                                          *
*                sender.h for 03_object_communication_signals              *
*                Created on  : Thu Mar 09 2017 13:02                       *
*                Made by : Qt training <training@qt.io>                    *
*                                                                          *
***************************************************************************/

#ifndef SENDER_H
#define SENDER_H

#include <QObject>

class Sender : public QObject
{
    Q_OBJECT
public:
    explicit Sender(QObject *parent = 0);

signals:
    void nameChanged(const QString &);
    void nameChanged(const QString &, int);

private slots:
    void changeName(const QString &);
};

#endif // SENDER_H

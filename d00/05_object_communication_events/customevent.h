/***************************************************************************
*                                                                          *
*                customevent.h for 05_object_communication_events          *
*                Created on  : Fri Mar 10 2017 13:39                       *
*                Made by : Qt training <training@qt.io>                    *
*                                                                          *
***************************************************************************/

#ifndef CUSTOMEVENT_H
#define CUSTOMEVENT_H

#include <QEvent>
#include <QString>

const QEvent::Type customEventType = QEvent::Type(QEvent::User + 1);

class CustomEvent : public QEvent
{
public:
    CustomEvent();
    QString data() const;
    void setData(const QString &data);

private:
    QString m_eventData;
};

#endif // CUSTOMEVENT_H

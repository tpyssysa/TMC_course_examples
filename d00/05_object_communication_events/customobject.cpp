/***************************************************************************
*                                                                          *
*                customobject.cpp for 05_object_communication_events       *
*                Created on  : Fri Mar 10 2017 13:41                       *
*                Made by : Qt training <training@qt.io>                    *
*                                                                          *
***************************************************************************/

#include "customobject.h"
#include "customevent.h"
#include <QCoreApplication>
#include <QtDebug>

CustomObject::CustomObject(QObject *parent) : QObject(parent)
{
    m_timerId = startTimer(3000);
    // installEventFilter(this);
}

bool CustomObject::event(QEvent *event)
{
    if (event->type() == customEventType)
        qDebug() << "Custom event handled:" << "Event data" << static_cast<CustomEvent *>(event)->data();
    return QObject::event(event);
}

bool CustomObject::eventFilter(QObject *watched, QEvent *event)
{
    if (event->type() == customEventType) {
        qDebug() << "Custom event filtered.";
        return true;
    }
    return QObject::eventFilter(watched, event);
}

void CustomObject::timerEvent(QTimerEvent *event)
{
    if (event->timerId() == m_timerId) {
        killTimer(m_timerId);
        qApp->quit();
    }
    return QObject::timerEvent(event);
}

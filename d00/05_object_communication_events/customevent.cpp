/***************************************************************************
*                                                                          *
*                customevent.cpp for 05_object_communication_events          *
*                Created on  : Fri Mar 10 2017 13:39                       *
*                Made by : Qt training <training@qt.io>                    *
*                                                                          *
***************************************************************************/

#include "customevent.h"

CustomEvent::CustomEvent() :
    QEvent(customEventType),
    m_eventData("")
{
}

QString CustomEvent::data() const
{
    return m_eventData;
}

void CustomEvent::setData(const QString &data)
{
    m_eventData = data;
}

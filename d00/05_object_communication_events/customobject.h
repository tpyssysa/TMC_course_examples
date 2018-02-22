/***************************************************************************
*                                                                          *
*                customobject.h for 05_object_communication_events         *
*                Created on  : Fri Mar 10 2017 13:41                       *
*                Made by : Qt training <training@qt.io>                    *
*                                                                          *
***************************************************************************/

#ifndef CUSTOMOBJECT_H
#define CUSTOMOBJECT_H

#include <QObject>

class CustomObject : public QObject
{
    Q_OBJECT
public:
    explicit CustomObject(QObject *parent = 0);

protected:
    bool event(QEvent *event) Q_DECL_OVERRIDE;
    bool eventFilter(QObject *watched, QEvent *event) Q_DECL_OVERRIDE;
    void timerEvent(QTimerEvent *event);

private:
    int m_timerId;
};

#endif // CUSTOMOBJECT_H

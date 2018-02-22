/***************************************************************************
*                                                                          *
*                main.cpp for 05_object_communication_events               *
*                Created on  : Fri Mar 10 2017 13:19                       *
*                Made by : Qt training <training@qt.io>                    *
*                                                                          *
***************************************************************************/

#include "customevent.h"
#include "customobject.h"
#include <QCoreApplication>

int main(int argc, char **argv)
{
    QCoreApplication application(argc, argv);
    CustomObject receiver;

    CustomEvent *anotherEvent = new CustomEvent;
    anotherEvent->setData("Custom event - asynchronous");
    application.postEvent(&receiver, anotherEvent);

    CustomEvent event;
    event.setData("Custom event - synchronous");
    application.sendEvent(&receiver, &event);

    return application.exec();
}

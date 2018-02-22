/***************************************************************************
*                                                                          *
*                main.cpp for 04_painted_items                             *
*                Created on  : Thu Mar 30 2017 09:29                       *
*                Made by : Qt training <training@qt.io>                    *
*                                                                          *
***************************************************************************/

#include "button.h"
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <qqml.h>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    qmlRegisterType<Button>("Controls", 1,0, "Button");
    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}

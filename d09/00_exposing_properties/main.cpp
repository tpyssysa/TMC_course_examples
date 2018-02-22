/***************************************************************************
*                                                                          *
*                main.cpp for 00_exposing_properties                       *
*                Created on  : Thu Mar 30 2017 09:23                       *
*                Made by : Qt training <training@qt.io>                    *
*                                                                          *
***************************************************************************/

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    QQmlContext *context(engine.rootContext());
    context->setContextProperty("backgroundColor", "lightgreen");
    context->setContextProperty("userText", "Hello world");
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}

/***************************************************************************
*                                                                          *
*                main.cpp for 01_bindings_and_signals                      *
*                Created on  : Thu Mar 30 2017 09:25                       *
*                Made by : Qt training <training@qt.io>                    *
*                                                                          *
***************************************************************************/

#include "simpleclass.h"
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    QQmlContext* context(engine.rootContext());
    context->setContextProperty("simpleClass", new SimpleClass(&engine));

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}

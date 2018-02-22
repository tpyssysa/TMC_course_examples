/***************************************************************************
*                                                                          *
*                main.cpp for 02_rss_reader                                *
*                Created on  : Thu Mar 30 2017 09:27                       *
*                Made by : Qt training <training@qt.io>                    *
*                                                                          *
***************************************************************************/

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtWebEngine>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QtWebEngine::initialize();

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}

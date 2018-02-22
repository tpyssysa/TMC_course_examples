/***************************************************************************
*                                                                          *
*                main.cpp for 05_sg_items                                  *
*                Created on  : Thu Mar 30 2017 09:32                       *
*                Made by : Qt training <training@qt.io>                    *
*                                                                          *
***************************************************************************/

#include "imageitem.h"
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <qqml.h>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    qmlRegisterType<ImageItem>("Controls", 1, 0, "ImageItem");
    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}

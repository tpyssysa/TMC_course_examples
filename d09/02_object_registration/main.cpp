/***************************************************************************
*                                                                          *
*                main.cpp for 02_object_registration                       *
*                Created on  : Thu Mar 30 2017 09:27                       *
*                Made by : Qt training <training@qt.io>                    *
*                                                                          *
***************************************************************************/

#include "employee.h"
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <qqml.h>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    qmlRegisterType<Employee>("EmployeeTypes", 1,0, "Employee");
    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}

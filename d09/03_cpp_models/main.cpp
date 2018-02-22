/***************************************************************************
*                                                                          *
*                main.cpp for 03_cpp_models                                *
*                Created on  : Thu Mar 30 2017 09:28                       *
*                Made by : Qt training <training@qt.io>                    *
*                                                                          *
***************************************************************************/

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <qqml.h>
#include "employeemodel.h"

static QObject *employeeModel_provider(QQmlEngine *, QJSEngine *)
{
    EmployeeModel *model = new EmployeeModel();
    return model;
}


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    qmlRegisterSingletonType<EmployeeModel>("EmployeeTypes", 1, 0, "EmployeeModel", employeeModel_provider);
            QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}

/***************************************************************************
*                                                                          *
*                main.cpp for 06_data_streaming                            *
*                Created on  : Fri Mar 10 2017 13:35                       *
*                Made by : Qt training <training@qt.io>                    *
*                                                                          *
***************************************************************************/

#include "employee.h"
#include <QTemporaryFile>
#include <QDataStream>
#include <QtDebug>

int main(int, char **)
{
    Employee employee;
    employee.setName("Diligent Developer");
    employee.setSalary(42.24);

    QTemporaryFile file;
    if (!file.open()) {
        qDebug() << "Temp file opening failed.";
        return EXIT_FAILURE;
    }

    // Serialise to the file
    QDataStream stream(&file);
    qRegisterMetaTypeStreamOperators<Employee>("Employee");
    QVariant variantData(QVariant::fromValue(employee));
    stream << variantData;

    file.reset();

    // Serialise from the file
    Employee employeeFromFile;
    QVariant variantFromFile;
    stream >> variantFromFile;
    employeeFromFile = variantFromFile.value<Employee>();

    qDebug() << employeeFromFile.name();
    qDebug() << employeeFromFile.salary();

    file.close();

    return 0;
}

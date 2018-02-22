/***************************************************************************
*                                                                          *
*                employee.cpp for 06_data_streaming                          *
*                Created on  : Mon Mar 13 2017 09:19                       *
*                Made by : Qt training <training@qt.io>                    *
*                                                                          *
***************************************************************************/

#include "employee.h"

Employee::Employee() :
    Employee("NN", 0.0)
{
}

Employee::Employee(const QString &name, const float salary)
{
    m_name = name;
    m_salary = salary;
}

const QString &Employee::name() const
{
    return m_name;
}

void Employee::setName(const QString &name)
{
    m_name = name;
}

float Employee::salary() const
{
    return m_salary;
}

void Employee::setSalary(const float &salary)
{
    m_salary = salary;
}

QDataStream &operator<<(QDataStream &stream, const Employee &data)
{
    stream << data.name() << QString::number(data.salary());
    return stream;
}

QDataStream &operator>>(QDataStream &stream, Employee &data)
{
    QString name, salary;
    stream >> name >> salary;
    data.setName(name);
    data.setSalary(salary.toFloat());
    return stream;
}

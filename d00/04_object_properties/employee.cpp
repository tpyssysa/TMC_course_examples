/***************************************************************************
*                                                                          *
*                employee.cpp for 04_object_properties                     *
*                Created on  : Fri Mar 10 2017 09:48                       *
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

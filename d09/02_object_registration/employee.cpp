/***************************************************************************
*                                                                          *
*                employee.cpp for 02_object_registration                   *
*                Created on  : Mon Apr 17 2017 12:46                       *
*                Made by : Qt training <training@qt.io>                    *
*                                                                          *
***************************************************************************/

#include "employee.h"

Employee::Employee(QObject *parent) :
    QObject(parent),
    m_name("First name, Last name"),
    m_salary(0.0)
{
}

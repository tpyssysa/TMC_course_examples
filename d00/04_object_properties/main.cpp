/***************************************************************************
*                                                                          *
*                main.cpp for 04_object_properties                         *
*                Created on  : Fri Mar 10 2017 09:40                       *
*                Made by : Qt training <training@qt.io>                    *
*                                                                          *
***************************************************************************/

#include "employee.h"
#include "salesaccount.h"
#include <QtDebug>

int main(int, char **)
{
    Employee employee("Hard-working Developer", 7200.16);

    SalesAccount account;
    account.setProperty("regions", SalesAccount::Europe | SalesAccount::Americas);
    account.setProperty("employee", QVariant::fromValue(employee));

    account.connect(&account, &SalesAccount::regionsChanged, [&account] () { qDebug() << "Regions changed to" << account.property("regions"); });
    account.setRegions(SalesAccount::Europe);

    qDebug() << "Sales account" << account.property("employee").value<Employee>().name();
    qDebug() << "has a salary of" << account.property("employee").value<Employee>().salary();;
}

/***************************************************************************
*                                                                          *
*                employee.h for 07_item_containers                         *
*                Created on  : Mon Mar 13 2017 10:47                       *
*                Made by : Qt training <training@qt.io>                    *
*                                                                          *
***************************************************************************/

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <QString>
#include <QMetaType>

class Employee
{
public:
    Employee();
    Employee(const QString &name, const float salary);

    bool operator !=(const Employee &employee) const
    {
        if ((employee.m_name != m_name) || (employee.m_salary != m_salary))
            return true;
        return false;
    }

    const QString &name() const;
    void setName(const QString &name);

    float salary() const;
    void setSalary(const float &salary);

private:
    QString m_name;
    float m_salary;
};

Q_DECLARE_METATYPE(Employee);
QDataStream & operator<< (QDataStream &stream, const Employee &data);
QDataStream & operator>> (QDataStream &stream, Employee &data);

#endif // EMPLOYEE_H


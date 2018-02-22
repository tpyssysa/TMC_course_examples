/***************************************************************************
*                                                                          *
*                employee.h for 02_object_registration                     *
*                Created on  : Mon Apr 17 2017 12:46                       *
*                Made by : Qt training <training@qt.io>                    *
*                                                                          *
***************************************************************************/

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <QObject>

class Employee : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name MEMBER m_name NOTIFY onNameChanged)
    Q_PROPERTY(qreal salary MEMBER m_salary NOTIFY onSalaryChanged)
public:
    explicit Employee(QObject *parent = 0);

signals:
    void onNameChanged();
    void onSalaryChanged();

private:
    QString m_name;
    qreal m_salary;
};

#endif // EMPLOYEE_H

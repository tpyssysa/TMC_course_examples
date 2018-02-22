/***************************************************************************
*                                                                          *
*                salesaccount.h for 04_object_properties                   *
*                Created on  : Fri Mar 10 2017 09:50                       *
*                Made by : Qt training <training@qt.io>                    *
*                                                                          *
***************************************************************************/

#ifndef SALESACCOUNT_H
#define SALESACCOUNT_H

#include "employee.h"
#include <QObject>

class SalesAccount : public QObject
{
    Q_OBJECT
    Q_PROPERTY(Employee employee MEMBER m_employee NOTIFY employeeChanged)
    Q_PROPERTY(Regions regions READ regions WRITE setRegions NOTIFY regionsChanged)
public:
    explicit SalesAccount(QObject *parent = 0);

    enum Region { Africa = 0x01, Americas = 0x02, Asia = 0x04, Australia = 0x08, Europe = 0x10, Oceania = 0x20 };
    Q_DECLARE_FLAGS(Regions, Region)
    Q_FLAG(Regions)

    Regions regions() const;
    void setRegions(Regions regions);

signals:
    void employeeChanged();
    void regionsChanged();

private:
    Employee m_employee;
    Regions m_regions;
};

#endif // SALESACCOUNT_H

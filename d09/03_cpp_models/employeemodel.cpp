/***************************************************************************
*                                                                          *
*                employeemodel.cpp for 03_cpp_models                       *
*                Created on  : Mon Apr 17 2017 13:54                       *
*                Made by : Qt training <training@qt.io>                    *
*                                                                          *
***************************************************************************/

#include "employeemodel.h"
#include "employee.h"

EmployeeModel::EmployeeModel(QObject *parent)
    : QAbstractListModel(parent)
{
}

EmployeeModel::~EmployeeModel()
{
    for (const Employee *employee : m_employees)
        delete employee;
    m_employees.clear();
}

void EmployeeModel::addEmployee(const QString &name, qreal salary)
{
    Employee *employee = new Employee();
    employee->setProperty("name", name);
    employee->setProperty("salary", salary);
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    m_employees << employee;
    endInsertRows();
}

int EmployeeModel::rowCount(const QModelIndex &) const
{
    return m_employees.count();
}

Qt::ItemFlags EmployeeModel::flags(const QModelIndex &index) const
{
    return Qt::ItemIsEditable | QAbstractListModel::flags(index);
}

bool EmployeeModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (index.row() < 0 || index.row() > m_employees.count())
        return false;

    Employee *employee = m_employees[index.row()];
    if (role == NameRole || role == Qt::EditRole)
        employee->setProperty("name", value);
    else if (role == SalaryRole)
        employee->setProperty("salary", value);
    Q_EMIT dataChanged(index, index);
    return true;
}

QVariant EmployeeModel::data(const QModelIndex & index, int role) const {
    if (index.row() < 0 || index.row() >= m_employees.count())
        return QVariant();

    Employee *employee = m_employees[index.row()];
    if (role == NameRole)
        return employee->property("name");
    else if (role == SalaryRole)
        return employee->property("salary");
    return QVariant();
}

QHash<int, QByteArray> EmployeeModel::roleNames() const {
    QHash<int, QByteArray> roles;
    roles[NameRole] = "name";
    roles[SalaryRole] = "salary";
    return roles;
}




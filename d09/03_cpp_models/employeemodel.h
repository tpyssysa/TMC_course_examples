/***************************************************************************
*                                                                          *
*                employeemodel.h for 03_cpp_models                         *
*                Created on  : Mon Apr 17 2017 13:54                       *
*                Made by : Qt training <training@qt.io>                    *
*                                                                          *
***************************************************************************/

#ifndef EMPLOYEEMODEL_H
#define EMPLOYEEMODEL_H

#include <QAbstractListModel>

QT_FORWARD_DECLARE_CLASS(Employee)

class EmployeeModel : public QAbstractListModel
{
    Q_OBJECT
public:
    enum EmployeeRoles {
        NameRole = Qt::UserRole + 1,
        SalaryRole
    };

    EmployeeModel(QObject *parent = 0);
    ~EmployeeModel();
    Q_INVOKABLE void addEmployee(const QString &name, qreal salary);

    int rowCount(const QModelIndex & parent = QModelIndex()) const Q_DECL_OVERRIDE;
    Qt::ItemFlags flags(const QModelIndex &index) const Q_DECL_OVERRIDE;
    bool setData(const QModelIndex &index, const QVariant &value, int role) Q_DECL_OVERRIDE;
    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;

protected:
    QHash<int, QByteArray> roleNames() const;
private:
    QList<Employee *> m_employees;
};

#endif // EMPLOYEEMODEL_H

/***************************************************************************
*                                                                          *
*                customtablemodel.cpp for 03_custom_models                 *
*                Created on  : Wed Mar 22 2017 11:09                       *
*                Made by : Qt training <training@qt.io>                    *
*                                                                          *
***************************************************************************/

#include "customtablemodel.h"

CustomTableModel::CustomTableModel(QObject *parent) :
    QAbstractTableModel(parent)
{
}

void CustomTableModel::appendCurrencies(const CurrencyContainer &container)
{
    auto currentSize(m_currencies.count());
    auto containerSize(container.count());
    beginInsertRows(QModelIndex(), currentSize, containerSize);
    beginInsertColumns(QModelIndex(), currentSize, containerSize);
    for (CurrencyContainer::const_iterator iterator = container.cbegin(); iterator != container.cend(); ++iterator)
        m_currencies.append(*iterator);
    endInsertColumns();
    endInsertRows();
}

int CustomTableModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return m_currencies.count();
}

int CustomTableModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return m_currencies.count();
}

QVariant CustomTableModel::data(const QModelIndex &index, int role) const
{
    if (index.isValid() && role == Qt::DisplayRole)
        return m_currencies.at(index.column()).second / m_currencies.at(index.row()).second;
    return QVariant();
}

QVariant CustomTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    Q_UNUSED(orientation)
    if (role == Qt::DisplayRole)
        return m_currencies.at(section).first;
    return QVariant();
}

bool CustomTableModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (index.isValid() && role == Qt::EditRole) {
        m_currencies[index.column()].second = value.toDouble();
        Q_EMIT dataChanged(index, index);
        return true;
    }
    return false;
}

Qt::ItemFlags CustomTableModel::flags(const QModelIndex &index) const
{
    if (index.row() == 0 && index.column() > 0)
        return QAbstractTableModel::flags(index) | Qt::ItemIsEditable;
    return QAbstractTableModel::flags(index);
}

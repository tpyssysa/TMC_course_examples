/***************************************************************************
*                                                                          *
*                customtablemodel.h for 03_custom_models                   *
*                Created on  : Wed Mar 22 2017 11:09                       *
*                Made by : Qt training <training@qt.io>                    *
*                                                                          *
***************************************************************************/

#ifndef CUSTOMTABLEMODEL_H
#define CUSTOMTABLEMODEL_H

#include <QAbstractTableModel>

typedef QPair<QString, qreal> Item;
typedef QVector<Item> CurrencyContainer;

class CustomTableModel : public QAbstractTableModel
{
public:
    CustomTableModel(QObject *parent = 0);
    void appendCurrencies(const CurrencyContainer& container);

protected:
    int rowCount(const QModelIndex &parent) const Q_DECL_OVERRIDE;
    int columnCount(const QModelIndex &parent) const Q_DECL_OVERRIDE;
    QVariant data(const QModelIndex &index, int role) const Q_DECL_OVERRIDE;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const Q_DECL_OVERRIDE;
    bool setData(const QModelIndex &index, const QVariant &value, int role) Q_DECL_OVERRIDE;
    Qt::ItemFlags flags(const QModelIndex &index) const Q_DECL_OVERRIDE;

private:
    CurrencyContainer m_currencies;
};

#endif // CUSTOMTABLEMODEL_H

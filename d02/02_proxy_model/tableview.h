/***************************************************************************
*                                                                          *
*                tableview.h for 02_proxy_model                            *
*                Created on  : Wed Mar 22 2017 09:13                       *
*                Made by : Qt training <training@qt.io>                    *
*                                                                          *
***************************************************************************/

#ifndef TABLEVIEW_H
#define TABLEVIEW_H

#include <QWidget>

QT_FORWARD_DECLARE_CLASS(QSortFilterProxyModel)
QT_FORWARD_DECLARE_CLASS(QGridLayout)
QT_FORWARD_DECLARE_CLASS(QLabel)
QT_FORWARD_DECLARE_CLASS(QLineEdit)
QT_FORWARD_DECLARE_CLASS(QTableView)
QT_FORWARD_DECLARE_CLASS(QAbstractItemModel)

class TableView : public QWidget
{
public:
    TableView(QWidget *parent = 0);
    void setModel(QAbstractItemModel *model);

private Q_SLOTS:
    void setFilterColumn(int);

private:
    QSortFilterProxyModel *mFilter;
    QGridLayout *mLayout;
    QTableView *mTableView;
    QLabel *mLabel;
    QLineEdit *mLineEdit;
};

#endif // TABLEVIEW_H

/***************************************************************************
*                                                                          *
*                tableview.cpp for 02_proxy_model                          *
*                Created on  : Wed Mar 22 2017 09:13                       *
*                Made by : Qt training <training@qt.io>                    *
*                                                                          *
***************************************************************************/

#include "tableview.h"
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QHeaderView>
#include <QTableView>
#include <QSortFilterProxyModel>

TableView::TableView(QWidget *parent) :
    QWidget(parent),
    mFilter(new QSortFilterProxyModel(this))
{
    mLayout = new QGridLayout(this);

    mLabel = new QLabel(this);
    mLayout->addWidget(mLabel, 0, 0);

    mLineEdit = new QLineEdit(this);
    mLayout->addWidget(mLineEdit, 0, 1);
    mLabel->setText(tr("Filter:"));
    mLabel->setBuddy(mLineEdit);

    mTableView = new QTableView(this);
    mTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    mLayout->addWidget(mTableView, 1, 0, 1, 2);

    mTableView->setSortingEnabled(true);
    mFilter->setSortCaseSensitivity(Qt::CaseInsensitive);

    mTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    connect(mTableView->horizontalHeader(), &QHeaderView::sectionClicked,
              this, &TableView::setFilterColumn);
    mFilter->setFilterCaseSensitivity(Qt::CaseInsensitive);
    connect(mLineEdit, &QLineEdit::textChanged,
              mFilter, &QSortFilterProxyModel::setFilterWildcard);

    setFilterColumn(0);
}

void TableView::setModel(QAbstractItemModel *model)
{
    mFilter->setSourceModel(model);
    mTableView->setModel(mFilter);
    mTableView->resizeColumnsToContents();
}

void TableView::setFilterColumn(int column)
{
    mFilter->setFilterKeyColumn(column);
    mLineEdit->setFocus();
    mLineEdit->clear();
}

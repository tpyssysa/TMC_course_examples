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

TableView::TableView(QWidget *parent) :
    QWidget(parent)
{
    m_Layout = new QGridLayout(this);

    m_Label = new QLabel(this);
    m_Layout->addWidget(m_Label, 0, 0);

    m_LineEdit = new QLineEdit(this);
    m_Layout->addWidget(m_LineEdit, 0, 1);
    m_Label->setText(tr("Filter:"));
    m_Label->setBuddy(m_LineEdit);

    m_TableView = new QTableView(this);
    m_TableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    m_Layout->addWidget(m_TableView, 1, 0, 1, 2);

    m_TableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

void TableView::setModel(QAbstractItemModel *model)
{
    m_TableView->setModel(model);
    m_TableView->resizeColumnsToContents();
}


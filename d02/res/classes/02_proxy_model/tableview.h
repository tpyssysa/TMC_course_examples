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

private:
    QGridLayout *m_Layout;
    QTableView *m_TableView;
    QLabel *m_Label;
    QLineEdit *m_LineEdit;
};

#endif // TABLEVIEW_H

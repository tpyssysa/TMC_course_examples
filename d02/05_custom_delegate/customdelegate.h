/***************************************************************************
*                                                                          *
*                customdelegate.h for 05_custom_delegate                   *
*                Created on  : Thu Mar 23 2017 10:11                       *
*                Made by : Qt training <training@qt.io>                    *
*                                                                          *
***************************************************************************/

#ifndef CUSTOMDELEGATE_H
#define CUSTOMDELEGATE_H

#include <QItemDelegate>

enum { HIGHLIGHT_ROLE = Qt::UserRole + 1 };

class CustomDelegate : public QItemDelegate
{
public:
    CustomDelegate(QObject *parent = 0);

protected:
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const Q_DECL_OVERRIDE;
};

#endif // CUSTOMDELEGATE_H



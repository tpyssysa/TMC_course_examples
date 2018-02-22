/***************************************************************************
*                                                                          *
*                customdelegate.cpp for 05_custom_delegate                 *
*                Created on  : Thu Mar 23 2017 10:11                       *
*                Made by : Qt training <training@qt.io>                    *
*                                                                          *
***************************************************************************/

#include "customdelegate.h"
#include <QPainter>

CustomDelegate::CustomDelegate(QObject *parent) :
    QItemDelegate(parent)
{
}

void CustomDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QString text(index.data().toString());
    QString highlightText(index.data(HIGHLIGHT_ROLE).toString());

    if (!highlightText.isEmpty()) {
        int textIndex = text.indexOf(highlightText, 0, Qt::CaseInsensitive);

        QFontMetrics metrics(painter->fontMetrics());

        QRect highlightRect(option.rect);
        highlightRect.setX(metrics.width(text.left(textIndex)));
        highlightRect.setWidth(metrics.width(highlightText));
        highlightRect.setHeight(metrics.height());

        painter->fillRect(highlightRect, QBrush(Qt::yellow));
    }
    painter->drawText(option.rect, text, QTextOption(Qt::AlignLeft));
}

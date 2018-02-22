/***************************************************************************
*                                                                          *
*                button.cpp for 04_painted_items                           *
*                Created on  : Mon Apr 17 2017 15:29                       *
*                Made by : Qt training <training@qt.io>                    *
*                                                                          *
***************************************************************************/

#include "button.h"
#include <QBrush>
#include <QPainter>

Button::Button(QQuickPaintedItem *parent)
    : QQuickPaintedItem(parent)
{
    setAcceptedMouseButtons(Qt::LeftButton);
}

void Button::paint(QPainter *painter)
{
    QColor color(property("backgroundColor").value<QColor>());
    painter->setBrush(color);
    painter->setPen(color);
    painter->drawRect(boundingRect());

    painter->setPen("black");
    painter->drawText(boundingRect(), Qt::AlignCenter, property("buttontext").toString());
}

void Button::mousePressEvent(QMouseEvent *event)
{
    setProperty("backgroundColor", "lightgreen");
    Q_EMIT mousePressed();
    update();
    QQuickPaintedItem::mousePressEvent(event);
}


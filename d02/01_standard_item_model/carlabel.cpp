/***************************************************************************
*                                                                          *
*                carlabel.cpp for 01_standard_item_model                   *
*                Created on  : Tue Mar 21 2017 10:47                       *
*                Made by : Qt training <training@qt.io>                    *
*                                                                          *
***************************************************************************/

#include "carlabel.h"
#include <QMouseEvent>

CarLabel::CarLabel(QWidget *parent) :
    QLabel(parent)
{
    setWindowFlags(Qt::FramelessWindowHint);
    setGeometry(100, 100, CAR_IMAGE_WIDTH, CAR_IMAGE_HEIGHT);
}

void CarLabel::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
        hide();
    QLabel::mousePressEvent(event);
}

/***************************************************************************
*                                                                          *
*                carlabel.h for 01_standard_item_model                     *
*                Created on  : Tue Mar 21 2017 10:47                       *
*                Made by : Qt training <training@qt.io>                    *
*                                                                          *
***************************************************************************/

#ifndef CARLABEL_H
#define CARLABEL_H

#include <QLabel>

const quint16 CAR_IMAGE_WIDTH = 300;
const quint16 CAR_IMAGE_HEIGHT = 200;

class CarLabel : public QLabel
{
public:
    explicit CarLabel(QWidget *parent = 0);

protected:
    void mousePressEvent(QMouseEvent *) Q_DECL_OVERRIDE;
};

#endif // CARLABEL_H

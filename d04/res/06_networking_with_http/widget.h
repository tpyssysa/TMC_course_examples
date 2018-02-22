/***************************************************************************
*                                                                          *
*                widget.h for 05_networking_with_http                      *
*                Created on  : Mon Apr 03 2017 15:17                       *
*                Made by : Qt training <training@qt.io>                    *
*                                                                          *
***************************************************************************/

#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Form;
}

class Widget : public QWidget
{
    Q_OBJECT
public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private Q_SLOTS:
    void on_lineEdit_returnPressed();

private:
    Ui::Form *ui;
};

#endif // WIDGET_H

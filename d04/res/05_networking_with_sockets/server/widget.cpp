/***************************************************************************
*                                                                          *
*                widget.cpp for 05_networking_with_socket                  *
*                Created on  : Mon Apr 04 2017 13:12                       *
*                Made by : Qt training <training@qt.io>                    *
*                                                                          *
***************************************************************************/

#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    setWindowFlags(Qt::FramelessWindowHint);
}

Widget::~Widget()
{
    delete ui;
}

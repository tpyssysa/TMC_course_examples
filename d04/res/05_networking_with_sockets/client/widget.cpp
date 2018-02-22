/***************************************************************************
*                                                                          *
*                widget.cpp for 05_networking_with_socket                  *
*                Created on  : Mon Apr 04 2017 13:12                       *
*                Made by : Qt training <training@qt.io>                    *
*                                                                          *
***************************************************************************/

#include <QTcpSocket>
#include <QHostAddress>
#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
}

void Widget::on_lineEdit_returnPressed()
{
    on_pushButton_clicked();
}

void Widget::receiveData()
{
}

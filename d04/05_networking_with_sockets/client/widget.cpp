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
    m_socket = new QTcpSocket(this);
    m_socket->connectToHost(QHostAddress::LocalHost, 4242);
    connect(m_socket, &QTcpSocket::readyRead, this, &Widget::receiveData);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    QDataStream out(m_socket);
    out << ui->lineEdit->text();
}

void Widget::on_lineEdit_returnPressed()
{
    on_pushButton_clicked();
}

void Widget::receiveData()
{
    QDataStream in(m_socket);
    QString string;
    in >> string;
    ui->textEdit->append(string);
}

/***************************************************************************
*                                                                          *
*                widget.cpp for 05_networking_with_socket                  *
*                Created on  : Mon Apr 04 2017 13:12                       *
*                Made by : Qt training <training@qt.io>                    *
*                                                                          *
***************************************************************************/

#include <QTcpServer>
#include <QTcpSocket>
#include <QDebug>
#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget),
    m_sender(0),
    m_nofSockets(0)
{
    ui->setupUi(this);
    m_server = new QTcpServer(this);
    connect(m_server, &QTcpServer::newConnection, this, &Widget::newConnection);
    m_server->listen(QHostAddress::LocalHost, 4242);

    setWindowFlags(Qt::FramelessWindowHint);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::newConnection()
{
    while (m_server->hasPendingConnections()) {
        QTcpSocket *socket = qobject_cast<QTcpSocket *>(m_server->nextPendingConnection());
        connect(socket, &QTcpSocket::readyRead, this, &Widget::readData);
        connect(socket, &QTcpSocket::disconnected, this, &Widget::closeConnection);
        m_sockets.append(socket);
    }
}

void Widget::readData()
{
    m_sender = qobject_cast<QTcpSocket *>(sender());
    QDataStream in(m_sender);
    QString string;
    in >> string;
    ui->textEdit->append(string);
    for (QTcpSocket *socket : m_sockets) {
        QDataStream out(socket);
        out << string;
    }
}

void Widget::closeConnection()
{
    m_sender = qobject_cast<QTcpSocket *>(sender());
    ui->textEdit->append("Client closed.");
    m_sockets.removeOne(m_sender);
    m_sender->deleteLater();
    if (m_sockets.empty())
        qApp->quit();
}

/***************************************************************************
*                                                                          *
*                widget.h for 05_networking_with_socket                    *
*                Created on  : Mon Apr 04 2017 13:12                       *
*                Made by : Qt training <training@qt.io>                    *
*                                                                          *
***************************************************************************/

#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_FORWARD_DECLARE_CLASS(QTcpServer)
QT_FORWARD_DECLARE_CLASS(QTcpSocket)

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

public Q_SLOTS:
    void newConnection();
    void readData();
    void closeConnection();

private:
    Ui::Widget *ui;
    QTcpServer *m_server;
    QTcpSocket *m_sender;
    QVector<QTcpSocket *> m_sockets;
    int m_nofSockets;
};

#endif // WIDGET_H

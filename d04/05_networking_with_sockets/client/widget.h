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

private slots:
    void on_pushButton_clicked();
    void on_lineEdit_returnPressed();
    void receiveData();

private:
    Ui::Widget *ui;
    QTcpSocket *m_socket;
};

#endif // WIDGET_H

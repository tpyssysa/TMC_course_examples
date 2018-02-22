/***************************************************************************
*                                                                          *
*                widget.h for 06_networking_with_http                      *
*                Created on  : Mon Apr 03 2017 15:17                       *
*                Made by : Qt training <training@qt.io>                    *
*                                                                          *
***************************************************************************/

#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPointer>

QT_FORWARD_DECLARE_CLASS(QNetworkAccessManager)
QT_FORWARD_DECLARE_CLASS(QNetworkReply)

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
    void handleNetworkReply();

private:
    Ui::Form *ui;
    QNetworkAccessManager *m_manager;
    QPointer<QNetworkReply> m_reply;
};

#endif // WIDGET_H

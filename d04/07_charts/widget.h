/***************************************************************************
*                                                                          *
*                widget.h for 07_charts                                    *
*                Created on  : Mon Apr 03 2017 22:58                       *
*                Made by : Qt training <training@qt.io>                    *
*                                                                          *
***************************************************************************/

#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPointer>
#include <QChartView>

using namespace QtCharts;

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
    QChartView *m_chartView;
};

#endif // WIDGET_H

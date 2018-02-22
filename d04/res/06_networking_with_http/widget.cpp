/***************************************************************************
*                                                                          *
*                widget.cpp for 05_networking_with_http                    *
*                Created on  : Mon Apr 03 2017 15:17                       *
*                Made by : Qt training <training@qt.io>                    *
*                                                                          *
***************************************************************************/

#include "widget.h"
#include "ui_form.h"
#include <QUrlQuery>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_lineEdit_returnPressed()
{
    QUrl url("http://api.openweathermap.org/data/2.5/weather");
    QUrlQuery query;

    query.addQueryItem("q", ui->lineEdit->text());
    query.addQueryItem("mode", "json");
    query.addQueryItem("APPID", QStringLiteral("36496bad1955bf3365448965a42b9eac"));
    url.setQuery(query);
}

void Widget::handleNetworkReply()
{
}

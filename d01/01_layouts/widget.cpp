/***************************************************************************
*                                                                          *
*                widget.cpp for 01_layouts                                 *
*                Created on  : Fri Mar 17 2017 10:10                       *
*                Made by : Qt training <training@qt.io>                    *
*                                                                          *
***************************************************************************/

#include "widget.h"
#include "ui_widget.h"
#include <QWebEngineView>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget),
    m_webView(new QWebEngineView)
{
    ui->setupUi(this);
    ui->verticalLayout->addWidget(m_webView);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_lineEdit_returnPressed()
{
    on_pushButton_clicked();
}

void Widget::on_pushButton_clicked()
{
    m_webView->load(ui->lineEdit->text());
}

void Widget::on_pushButton_2_clicked()
{
    m_webView->back();
}

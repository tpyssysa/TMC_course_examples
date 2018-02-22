/***************************************************************************
*                                                                          *
*                widget.cpp for 02_dialogs                                 *
*                Created on  : Fri Mar 17 2017 10:10                       *
*                Made by : Qt training <training@qt.io>                    *
*                                                                          *
***************************************************************************/

#include "widget.h"
#include "ui_widget.h"
#include <QWebEngineView>
#include <QProgressBar>
#include <QInputDialog>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget),
    m_webView(new QWebEngineView),
    m_progressBar(new QProgressBar)
{
    ui->setupUi(this);
    m_progressBar->setVisible(false);
    ui->verticalLayout->addWidget(m_progressBar);
    ui->verticalLayout->addWidget(m_webView);
    connect(m_webView, &QWebEngineView::loadProgress, m_progressBar, &QProgressBar::setValue);
    connect(m_progressBar, &QProgressBar::valueChanged, [this] (int value) {
       if (value >= 100)
           m_progressBar->setVisible(false);
    });
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_lineEdit_returnPressed()
{
    m_progressBar->setVisible(true);
    m_webView->load(ui->lineEdit->text());
}

void Widget::on_pushButton_clicked()
{
    QInputDialog inputDialog;
    inputDialog.setLabelText("Give URL");
    inputDialog.setTextValue("http://");
    if (inputDialog.exec() == QDialog::Accepted) {
        m_progressBar->setVisible(true);
        m_webView->load(inputDialog.textValue());
    }
}

void Widget::on_pushButton_2_clicked()
{
    m_webView->back();
}

/***************************************************************************
*                                                                          *
*                widget.cpp for 04_ipc                                     *
*                Created on  : Mon Apr 04 2017 12:09                       *
*                Made by : Qt training <training@qt.io>                    *
*                                                                          *
***************************************************************************/

#include "widget.h"
#include "ui_widget.h"
#include <QFileDialog>
#include <QBuffer>
#include <QImageReader>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget),
{
    ui->setupUi(this);
    ui->label->setText(tr("Select an image file"));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_loadImageButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(0, QString(), QString(), tr("Images (*.png *.xpm *.jpg *.jpeg)"));
    if (!m_sharedImage.load(fileName)) {
        ui->label->setText(tr("Selected file is not an image, please select another."));
        return;
    }
    ui->label->setPixmap(QPixmap::fromImage(m_sharedImage));
}

void Widget::on_writeToMemoryButton_clicked()
{
}

void Widget::on_writeToFileButton_clicked()
{
}

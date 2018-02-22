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
#include <QMessageBox>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget),
    m_sharedMemory("SharedMemoryKey")
{
    ui->setupUi(this);
    ui->label->setText(tr("Select an image file"));
}

Widget::~Widget()
{
    m_sharedImage.detach();
    delete ui;
}

void Widget::on_loadImageButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(0, QString(), QString(), tr("Images (*.png *.xpm *.jpg *.jpeg)"));
    if (!m_sharedImage.load(fileName)) {
        QMessageBox::warning(this, tr("Shared memory error"), tr("Selected file is not an image, please select another."));
        return;
    }
    ui->label->setPixmap(QPixmap::fromImage(m_sharedImage));
    resize(m_sharedImage.width(), m_sharedImage.height());
}

void Widget::on_writeToMemoryButton_clicked()
{
    QBuffer buffer;
    buffer.open(QBuffer::ReadWrite);
    QDataStream out(&buffer);
    out << m_sharedImage;
    int size = buffer.size();

    if (!m_sharedMemory.isAttached()) {
        if (!m_sharedMemory.create(size)) {
            QMessageBox::warning(this, tr("Shared memory error"), tr("Unable to create a shared memory segment."));
            return;
        }
    }
    else {
        if (m_sharedMemory.size() < buffer.size()) {
            QMessageBox::warning(this, tr("Shared memory error"), tr("Existing shared memory segment too small"));
            return;
        }
    }

    m_sharedMemory.lock();
    char *to = (char *) m_sharedMemory.data();
    const char *from = buffer.data().data();
    memcpy(to, from, qMin(m_sharedMemory.size(), size));
    m_sharedMemory.unlock();
}

void Widget::on_writeToFileButton_clicked()
{
    QFile outFile(QString(QDir::tempPath() + "/imageFile"));
    outFile.open(QFile::WriteOnly);
    QDataStream out(&outFile);
    out << m_sharedImage;
}

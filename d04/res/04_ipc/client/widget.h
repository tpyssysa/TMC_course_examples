/***************************************************************************
*                                                                          *
*                widget.h for 04_ipc                                       *
*                Created on  : Mon Apr 04 2017 12:09                       *
*                Made by : Qt training <training@qt.io>                    *
*                                                                          *
***************************************************************************/

#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QImage>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = Q_NULLPTR);
    ~Widget();

private Q_SLOTS:
    void on_loadImageButton_clicked();
    void on_writeToMemoryButton_clicked();
    void on_writeToFileButton_clicked();

private:
    Ui::Widget *ui;
    QImage m_sharedImage;
};

#endif // WIDGET_H

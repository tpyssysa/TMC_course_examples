/***************************************************************************
*                                                                          *
*                widget.h for 02_dialogs                                   *
*                Created on  : Fri Mar 17 2017 10:10                       *
*                Made by : Qt training <training@qt.io>                    *
*                                                                          *
***************************************************************************/

#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_FORWARD_DECLARE_CLASS(QWebEngineView)
QT_FORWARD_DECLARE_CLASS(QProgressBar)

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
    void on_lineEdit_returnPressed();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Widget *ui;
    QWebEngineView *m_webView;
    QProgressBar *m_progressBar;
};

#endif // WIDGET_H

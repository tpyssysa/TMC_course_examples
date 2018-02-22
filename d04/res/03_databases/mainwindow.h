/***************************************************************************
*                                                                          *
*                mainwindow.h for 03_databases                             *
*                Created on  : Mon Apr 03 2017 11:34                       *
*                Made by : Qt training <training@qt.io>                    *
*                                                                          *
***************************************************************************/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_FORWARD_DECLARE_CLASS(QStandardItemModel)

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_pressed();

private:
    Ui::MainWindow *ui;
    QStandardItemModel *m_model;
};

#endif // MAINWINDOW_H

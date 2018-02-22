/***************************************************************************
*                                                                          *
*                mainwindow.h for 05_thread_management                     *
*                Created on  : Mon Mar 27 2017 12:33                       *
*                Made by : Qt training <training@qt.io>                    *
*                                                                          *
***************************************************************************/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private Q_SLOTS:
    void on_pushButton_released();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

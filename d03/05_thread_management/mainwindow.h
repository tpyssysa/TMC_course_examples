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
#include <QThread>
#include <QPointer>
#include "picalculator.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    bool stopThread();

private Q_SLOTS:
    void on_pushButton_released();

private:
    Ui::MainWindow *ui;
    QPointer<QThread> m_worker;
    QPointer<PiCalculator> m_calculator;
};

#endif // MAINWINDOW_H

/***************************************************************************
*                                                                          *
*                mainwindow.cpp for 00_video_player                          *
*                Created on  : Thu Apr 03 2017 08:22                       *
*                Made by : Qt training <training@qt.io>                    *
*                                                                          *
***************************************************************************/

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_openButton_clicked()
{
}

void MainWindow::on_playButton_clicked()
{
}

void MainWindow::on_pauseButton_clicked()
{
}

void MainWindow::on_stopButton_clicked()
{
}

/***************************************************************************
*                                                                          *
*                mainwindow.cpp for 05_thread_management                   *
*                Created on  : Mon Mar 27 2017 12:33                       *
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
    stopThread();
}

bool MainWindow::stopThread()
{
    if (m_worker) {
        if (m_worker->isRunning()) {
            m_worker->requestInterruption();
            return true;
        }
    }
    return false;
}

void MainWindow::on_pushButton_released()
{
    if (stopThread())
        return;
    m_worker = new QThread();
    m_calculator = new PiCalculator(ui->progressBar, ui->label, m_worker);

    connect(m_worker.data(), &QThread::started, m_calculator.data(), &PiCalculator::run);
    connect(m_worker.data(), &QThread::finished, [this] () { ui->pushButton->setText(tr("Start Task")); });
    connect(m_worker.data(), &QThread::finished, m_calculator.data(), &PiCalculator::deleteLater);
    connect(m_worker.data(), &QThread::finished, m_worker.data(), &QThread::deleteLater);

    m_worker->start();
    ui->pushButton->setText(tr("Stop Task"));
}


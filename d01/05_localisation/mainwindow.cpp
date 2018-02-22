/***************************************************************************
*                                                                          *
*                mainwindow.cpp for 04_localisation                        *
*                Created on  : Fri Mar 17 2017 13:07                       *
*                Made by : Qt training <training@qt.io>                    *
*                                                                          *
***************************************************************************/

#include "mainwindow.h"
#include <QLabel>
#include <QMessageBox>
#include <QAction>
#include <QMenu>
#include <QMenuBar>
#include <QToolBar>
#include <QStatusBar>
#include <QDockWidget>
#include <QListWidget>
#include <QApplication>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setupActions();
    setupMenuBar();
    setupToolBar();
    setupStatusBar();
    setupDockWindow();

    QLabel *label = new QLabel(this);
    QPixmap pixmap(":/flag");
    label->setPixmap(pixmap);
    setCentralWidget(label);
}

void MainWindow::setupActions()
{
    m_fileExit = new QAction(QIcon(":/icons/application-exit.png"), tr("Exit"), this);
    m_fileExit->setShortcuts(QKeySequence::Quit);
    connect(m_fileExit, &QAction::triggered, qApp, &QApplication::quit);

    m_helpAboutQt = new QAction(tr("About Qt"), this);
    connect(m_helpAboutQt, &QAction::triggered, qApp, &QApplication::aboutQt);

    m_fileNew = new QAction(QIcon(":/icons/document-new.png"), tr("New"), this);
    connect(m_fileNew, &QAction::triggered, [this] () {
        QMessageBox::information(this, tr("Hello"), tr("File new pressed"));
    });

    m_fileOpen = new QAction(QIcon(":/icons/document-open.png"), tr("Open"), this);
    connect(m_fileOpen, &QAction::triggered, [this] () {
        QMessageBox::information(this, tr("Hello"), tr("File open pressed"));
    });

    m_fileSave = new QAction(QIcon(":/icons/document-save.png"), tr("Save"), this);
    connect(m_fileSave, &QAction::triggered, [this] () {
        QMessageBox::information(this, tr("Hello"), tr("File save pressed"));
    });
}

void MainWindow::setupMenuBar()
{
    m_fileMenu = menuBar()->addMenu(tr("File"));
    m_fileMenu->addAction(m_fileExit);

    m_helpMenu = menuBar()->addMenu(tr("Help"));
    m_helpMenu->addAction(m_helpAboutQt);
}

void MainWindow::setupToolBar()
{
    m_toolBar = addToolBar("Standard");
    m_toolBar->addAction(m_fileNew);
    m_toolBar->addAction(m_fileOpen);
    m_toolBar->addAction(m_fileSave);
}

void MainWindow::setupStatusBar()
{
    QStatusBar *bar = statusBar();
    bar->showMessage(tr("Application ready"), 10000);
}

void MainWindow::setupDockWindow()
{
    QDockWidget *dock = new QDockWidget(tr("DockWidget"), this);

    QListWidget *widget = new QListWidget(dock);
    widget->addItem(tr("Dock Content"));
    dock->setWidget(widget);

    addDockWidget(Qt::LeftDockWidgetArea, dock);
}

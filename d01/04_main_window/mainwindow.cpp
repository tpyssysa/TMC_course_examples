/***************************************************************************
*                                                                          *
*                mainwindow.cpp for 03_main_window                         *
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

    QLabel *label = new QLabel("Central Widget", this);
    setCentralWidget(label);
}

void MainWindow::setupActions()
{
    m_fileExit = new QAction(QIcon(":/icons/application-exit.png"), "Exit", this);
    m_fileExit->setShortcuts(QKeySequence::Quit);
    connect(m_fileExit, &QAction::triggered, qApp, &QApplication::quit);

    m_helpAboutQt = new QAction("About Qt", this);
    connect(m_helpAboutQt, &QAction::triggered, qApp, &QApplication::aboutQt);

    m_fileNew = new QAction(QIcon(":/icons/document-new.png"), "New", this);
    connect(m_fileNew, &QAction::triggered, [this] () {
        QMessageBox::information(this, "Hello", "File new pressed");
    });

    m_fileOpen = new QAction(QIcon(":/icons/document-open.png"), "Open", this);
    connect(m_fileOpen, &QAction::triggered, [this] () {
        QMessageBox::information(this, "Hello", "File open pressed");
    });

    m_fileSave = new QAction(QIcon(":/icons/document-save.png"), "Save", this);
    connect(m_fileSave, &QAction::triggered, [this] () {
        QMessageBox::information(this, "Hello", "File save pressed");
    });
}

void MainWindow::setupMenuBar()
{
    m_fileMenu = menuBar()->addMenu("File");
    m_fileMenu->addAction(m_fileExit);

    m_helpMenu = menuBar()->addMenu("Help");
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
    bar->showMessage("Application ready", 10000);
}

void MainWindow::setupDockWindow()
{
    QDockWidget *dock = new QDockWidget("DockWidget", this);

    QListWidget *widget = new QListWidget(dock);
    widget->addItem("Dock Content");
    dock->setWidget(widget);

    addDockWidget(Qt::LeftDockWidgetArea, dock);
}

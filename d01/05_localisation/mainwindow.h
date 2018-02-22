/***************************************************************************
*                                                                          *
*                mainwindow.h for 04_localisation                          *
*                Created on  : Fri Mar 17 2017 13:07                       *
*                Made by : Qt training <training@qt.io>                    *
*                                                                          *
***************************************************************************/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

public: // setup functions
    void setupActions();
    void setupMenuBar();
    void setupToolBar();
    void setupStatusBar();
    void setupDockWindow();

private: // data member
    QMenu *m_fileMenu;
    QMenu *m_editMenu;
    QMenu *m_helpMenu;
    QToolBar *m_toolBar;
    QAction *m_fileNew;
    QAction *m_fileOpen;
    QAction *m_fileSave;
    QAction *m_fileExit;
    QAction *m_helpAboutQt;
};

#endif // MAINWINDOW_H

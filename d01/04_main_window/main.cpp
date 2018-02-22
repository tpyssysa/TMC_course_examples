/***************************************************************************
*                                                                          *
*                main.cpp for 03_main_window                               *
*                Created on  : Fri Mar 17 2017 13:07                       *
*                Made by : Qt training <training@qt.io>                    *
*                                                                          *
***************************************************************************/

#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}

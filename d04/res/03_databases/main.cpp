/***************************************************************************
*                                                                          *
*                main.cpp for 03_databases                                 *
*                Created on  : Thu Mar 30 2017 08:17                       *
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

/***************************************************************************
*                                                                          *
*                main.cpp for 05_thread_management                         *
*                Created on  : Mon Mar 27 2017 12:33                       *
*                Made by : Qt training <training@qt.io>                    *
*                                                                          *
***************************************************************************/

#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setGeometry(200, 200, 600, 500);
    w.show();

    return a.exec();
}

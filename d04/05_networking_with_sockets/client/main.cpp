/***************************************************************************
*                                                                          *
*                main.cpp for 05_networking_with_socket                    *
*                Created on  : Mon Apr 04 2017 13:12                       *
*                Made by : Qt training <training@qt.io>                    *
*                                                                          *
***************************************************************************/

#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();

    return a.exec();
}

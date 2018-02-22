/***************************************************************************
*                                                                          *
*                main.cpp for 04_ipc                                       *
*                Created on  : Mon Apr 04 2017 12:40                       *
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

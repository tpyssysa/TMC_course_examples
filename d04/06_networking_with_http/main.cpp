/***************************************************************************
*                                                                          *
*                main.cpp for 06_networking_with_http                      *
*                Created on  : Thu Mar 30 2017 08:19                       *
*                Made by : Qt training <training@qt.io>                    *
*                                                                          *
***************************************************************************/

#include "widget.h"
#include <QApplication>
#include <QWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget widget;
    widget.show();

    return a.exec();
}

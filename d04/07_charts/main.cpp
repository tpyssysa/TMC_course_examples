/***************************************************************************
*                                                                          *
*                widget.cpp for 07_charts                                  *
*                Created on  : Mon Apr 03 2017 22:41                       *
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
    widget.resize(400, 600);
    widget.show();

    return a.exec();
}

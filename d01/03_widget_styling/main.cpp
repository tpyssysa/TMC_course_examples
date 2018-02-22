/***************************************************************************
*                                                                          *
*                main.cpp for 03_styling                                   *
*                Created on  : Fri Mar 17 2017 10:09                       *
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

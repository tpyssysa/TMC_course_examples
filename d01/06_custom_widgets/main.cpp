/***************************************************************************
*                                                                          *
*                main.cpp for 06_custom_widgets                            *
*                Created on  : Fri Mar 17 2017 17:55                       *
*                Made by : Qt training <training@qt.io>                    *
*                                                                          *
***************************************************************************/

#include "customwidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CustomWidget widget;
    widget.show();

    return a.exec();
}

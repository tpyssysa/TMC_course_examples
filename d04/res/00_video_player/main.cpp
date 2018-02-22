/***************************************************************************
*                                                                          *
*                main.cpp for 00_video_player                              *
*                Created on  : Thu Mar 30 2017 08:11                       *
*                Made by : Qt training <training@qt.io>                    *
*                                                                          *
***************************************************************************/

#include <QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}

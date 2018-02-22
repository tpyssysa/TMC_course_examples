/***************************************************************************
*                                                                          *
*                main.cpp for 04_localisation                              *
*                Created on  : Fri Mar 17 2017 13:07                       *
*                Made by : Qt training <training@qt.io>                    *
*                                                                          *
***************************************************************************/

#include "mainwindow.h"
#include <QApplication>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    translator.load(":/localisation_fi.qm");
    a.installTranslator(&translator);

    QLocale locale(QLocale::Finnish);
    QLocale::setDefault(locale);

    MainWindow w;
    w.show();

    return a.exec();
}

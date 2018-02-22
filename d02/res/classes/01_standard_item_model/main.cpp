/***************************************************************************
*                                                                          *
*                main.cpp for 01_standard_item_model                       *
*                Created on  : Tue Mar 21 2017 10:39                       *
*                Made by : Qt training <training@qt.io>                    *
*                                                                          *
***************************************************************************/

#include "carlabel.h"
#include <QApplication>
#include <QStandardItemModel>
#include <QTableView>
#include <QHeaderView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    CarLabel carLabel;
    carLabel.setAttribute(Qt::WA_QuitOnClose, false);

    QList <QStringList> carData;
    carData.append(QStringList( { { "Cadillac" }, { "Oldtimer" } } ));
    carData.append(QStringList( { { "Cadillac" }, { "Oldtimer2" } } ));
    carData.append(QStringList( { { "Chevrolet" }, { "Corvette" } } ));
    carData.append(QStringList( { { "Chevrolet" }, { "Oldtimer" } } ));
    carData.append(QStringList( { { "Ford" }, { "Mustang" } } ));
    carData.append(QStringList( { { "Ford" }, { "Shelby" } } ));
    carData.append(QStringList( { { "Ford" }, { "thunderbird" } } ));
    carData.append(QStringList( { { "Mercedes" }, { "300" } } ));
    carData.append(QStringList( { { "Mercedes" }, { "Oldtimer" } } ))

    QTableView tableView;
    tableView.horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    tableView.show();
    return a.exec();
}

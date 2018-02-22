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
    carData.append(QStringList( { { "Mercedes" }, { "Oldtimer" } } ));

    QStandardItemModel model;
    model.insertRows(0, carData.count());
    model.insertColumns(0, carData.at(0).count());

    int row(0);
    for (const QStringList &carDataRow : carData) {
        model.setData(model.index(row, 0), carDataRow.at(0));
        model.setData(model.index(row, 1), carDataRow.at(1));
        ++row;
    }
    model.setHeaderData(0, Qt::Horizontal, "Car");
    model.setHeaderData(1, Qt::Horizontal, "Model");

    QTableView tableView;
    tableView.horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    QTableView::connect(&tableView, &QTableView::clicked, [&tableView, &model, &carLabel] (QModelIndex index) {
        QString carName(":/car_images/" +
                        model.data(model.index(index.row(), 0)).toString() +
                        "-" +
                        model.data(model.index(index.row(), 1)).toString() +
                        ".jpg");
        carName = carName.toLower();

        QPixmap carPixmap(QPixmap(carName).scaled(CAR_IMAGE_WIDTH, CAR_IMAGE_HEIGHT));
        carLabel.setPixmap(carPixmap);
        carLabel.show();
    });

    tableView.setModel(&model);
    tableView.show();
    return a.exec();
}

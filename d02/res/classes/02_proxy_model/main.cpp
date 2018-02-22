/***************************************************************************
*                                                                          *
*                main.cpp for 02_proxy_model                               *
*                Created on  : Wed Mar 22 2017 09:07                       *
*                Made by : Qt training <training@qt.io>                    *
*                                                                          *
***************************************************************************/

#include "tableview.h"
#include <QApplication>
#include <QStandardItemModel>

static const struct ModelData {
    QString name;
    QString nickname;
    int age;
} Dudes[] = { // Totally imaginary data
    { "James Bond", "Pointy Haired Boss", 33 },
    { "Mr. Bean",  "Blackie", 23 },
    { "Annie", "Miss A.", 26 },
    { "Fonzie",  "F", 79 }
};

static const int NOFDUDES = sizeof(Dudes)/sizeof(ModelData);

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TableView table;
    QStandardItemModel model;
    model.insertRows(0, NOFDUDES, QModelIndex());
    model.insertColumns(0, 3, QModelIndex());
    for (auto row = 0; row < NOFDUDES; ++row)
    {
        model.setData(model.index(row, 0, QModelIndex()), Dudes[row].name);
        model.setData(model.index(row, 1, QModelIndex()), Dudes[row].nickname);
        model.setData(model.index(row, 2, QModelIndex()), Dudes[row].age);
    }
    model.setHeaderData(0, Qt::Horizontal, "Name");
    model.setHeaderData(1, Qt::Horizontal, "Nickname");
    model.setHeaderData(2, Qt::Horizontal, "Age");

    table.setModel(&model);
    table.resize(500, 400);
    table.show();


    return a.exec();
}




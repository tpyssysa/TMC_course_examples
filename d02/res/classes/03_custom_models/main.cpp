/***************************************************************************
*                                                                          *
*                main.cpp for 03_custom_models                             *
*                Created on  : Wed Mar 22 2017 11:07                       *
*                Made by : Qt training <training@qt.io>                    *
*                                                                          *
***************************************************************************/

#include <QApplication>
#include <QTableView>
#include <QHeaderView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    CurrencyContainer currencies({{"EUR", 1.0},
                                  {"DZD", 0.0085},
                                  {"AED", 0.2521},
                                  {"AUD", 0.7090},
                                  {"EGP", 0.0510},
                                  {"KRW", 0.0008},
                                  {"HKD", 0.1192},
                                  {"JPY", 0.0083},
                                  {"CAD", 0.6912},
                                  {"NOK", 0.1089}});

    QTableView view;
    view.resizeColumnsToContents();
    view.resize(860, 400);
    view.horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    view.show();

    return a.exec();
}

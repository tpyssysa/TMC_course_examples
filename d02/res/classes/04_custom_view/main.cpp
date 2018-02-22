/***************************************************************************
*                                                                          *
*                main.cpp for 04_custom_view                               *
*                Created on  : Wed Mar 22 2017 15:42                       *
*                Made by : Qt training <training@qt.io>                    *
*                                                                          *
***************************************************************************/

#include <QApplication>
#include <QStandardItemModel>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QList<int> populations;
    populations << 5573894 << 9482855 << 5252166 << 322100000 << 81843743 << 38538447 << 323002 << 16730348 << 63256141 << 4582769 << 9932000;

    QStringList countries;
    countries << "Denmark" << "Sweden" << "Norway" << "USA" << "Germany"
              << "Poland" << "Iceland" << "Holland" << "Great Britain" << "Ireland" << "Hungary";

    QStandardItemModel model(populations.size(), 2);
    for (auto row = 0; row < populations.size(); ++row) {
        model.setData(model.index(row, 0), countries[row]);
        model.setData(model.index(row, 1), populations[row]);
    }
    model.setHeaderData(0, Qt::Horizontal, "Country");
    model.setHeaderData(1, Qt::Horizontal, "Population");

    return a.exec();
}


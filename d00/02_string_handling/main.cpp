/***************************************************************************
*                                                                          *
*                main.cpp for 02_string_handling                           *
*                Created on  : Fri Mar 10 2017 13:33                       *
*                Made by : Qt training <training@qt.io>                    *
*                                                                          *
***************************************************************************/

#include <QtDebug>

int main(int, char **)
{
    QString string("Qt rules ");
    string.append(QString::number(42));
    qDebug() << string;

    if (string.contains("Qt"))
        string.insert(string.indexOf("Qt") + QByteArray("Qt").length(), " always");
    qDebug() << string;

    QString copyString(" " + string);
    for (auto i = 0; i < 9; ++i)
        string.append(copyString);
    qDebug() << string;

    qDebug() << string.count("Qt");
    return 0;
}

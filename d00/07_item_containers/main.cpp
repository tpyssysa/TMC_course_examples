/***************************************************************************
*                                                                          *
*                main.cpp for 07_item_containers                           *
*                Created on  : Fri Mar 10 2017 13:37                       *
*                Made by : Qt training <training@qt.io>                    *
*                                                                          *
***************************************************************************/

#include <QPoint>
#include <QtDebug>
#include "employee.h"

bool operator <(const QPoint &p1, const QPoint &p2)
{
    return (p1.x() < p2.x() ||
            (p1.x() == p2.x() && p1.y() < p2.y()));
}

bool isSubString(const Employee &employee) { return employee.name().contains("NN"); }

typedef QMap<QPoint, Employee> Container;

void logAllItems(const Container &container)
{
    for (const Employee employee : container)
        qDebug() << employee.name() << employee.salary();
}

int main(int, char **)
{
    Container container;

    // Fill in the container
    for (int x = 0; x < 100; ++x) {
        for (int y = 0; y < 100; ++y) {
            container.insert(QPoint(x, y), Employee("Firstname Lastname", 100 * x + y));
        }
    }

    // Log the result
    logAllItems(container);

    // Remove every third element from the container
    QMutableMapIterator<QPoint, Employee> mutableIterator(container);
    int count(1);
    while (mutableIterator.hasNext()) {
        mutableIterator.next();
        if ((count++ % 3) == 0) {
            mutableIterator.remove();
        }
    }

    // Log the result
    logAllItems(container);

    // Set the name of every fifth employee to NN n
    count = 1;
    mutableIterator.toFront();
    while (mutableIterator.hasNext()) {
        mutableIterator.next();
        if ((count++ % 5) == 0) {
            Employee employee("NN " + QString::number(count), mutableIterator.value().salary());
            mutableIterator.setValue(employee);
        }
    }

    // Log the result
    logAllItems(container);

    // Calculate how many times "hello" sub-string is included in the container
    qDebug() << std::count_if(container.begin(), container.end(), isSubString);
}

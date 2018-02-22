/***************************************************************************
*                                                                          *
*                main.cpp for 01_memory_management                         *
*                Created on  : Thu Mar 09 2017 10:54                       *
*                Made by : Qt training <training@qt.io>                    *
*                                                                          *
***************************************************************************/

#include "customclass.h"
#include <QSharedPointer>

int main(int, char **)
{
    CustomClass parentObject;
    parentObject.setObjectName("Parent");

    CustomClass *child1 = new CustomClass(&parentObject);
    child1->setObjectName("Child 1");

    QScopedPointer<CustomClass> child2(new CustomClass());
    child2.data()->setObjectName("Child 2");

    QSharedPointer<CustomClass> child3(new CustomClass());
    child3->setObjectName("Child 3");

    return 0;
}

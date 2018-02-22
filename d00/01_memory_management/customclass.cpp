/***************************************************************************
*                                                                          *
*                customclass.cpp for 01_memory_management                  *
*                Created on  : Thu Mar 09 2017 11:00                       *
*                Made by : Qt training <training@qt.io>                    *
*                                                                          *
***************************************************************************/

#include "customclass.h"
#include <QtDebug>

CustomClass::CustomClass(QObject *parent) : QObject(parent)
{
}

CustomClass::~CustomClass()
{
    qDebug() << "Object" << objectName() << "destructed";
}

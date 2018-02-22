/***************************************************************************
*                                                                          *
*                simpleclass.cpp for 01_bindings_and_signals               *
*                Created on  : Mon Apr 17 2017 12:08                       *
*                Made by : Qt training <training@qt.io>                    *
*                                                                          *
***************************************************************************/

#include "simpleclass.h"

SimpleClass::SimpleClass(QObject *parent) :
    QObject(parent),
    m_backgroundColor(QColor(Qt::lightGray)),
    m_userText("Hello world")
{
}

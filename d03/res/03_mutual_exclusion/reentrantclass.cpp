/***************************************************************************
*                                                                          *
*                reentrantclss.cpp for 03_mutual_exclusion                 *
*                Created on  : Tue Mar 28 2017 07:43                       *
*                Made by : Qt training <training@qt.io>                    *
*                                                                          *
***************************************************************************/

#include "reentrantclass.h"
#include <QtDebug>

ReentrantClass::ReentrantClass() :
    m_counter(0)
{
}

ReentrantClass::~ReentrantClass()
{
    qDebug() << "ReentrantClass destructor called";
}

void ReentrantClass::incCounter()
{
    ++m_counter;
}

void ReentrantClass::decCounter()
{
    --m_counter;
}

int ReentrantClass::counter() const
{
    return m_counter;
}






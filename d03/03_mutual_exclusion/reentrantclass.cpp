/***************************************************************************
*                                                                          *
*                reentrantclss.cpp for 03_mutual_exclusion                 *
*                Created on  : Tue Mar 28 2017 07:43                       *
*                Made by : Qt training <training@qt.io>                    *
*                                                                          *
***************************************************************************/

#include "reentrantclass.h"
#include <QMutexLocker>
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
    QMutexLocker locker(&m_mutex);
    ++m_counter;
}

void ReentrantClass::decCounter()
{
    QMutexLocker locker(&m_mutex);
    --m_counter;
}

int ReentrantClass::counter()
{
    QMutexLocker locker(&m_mutex);
    return m_counter;
}






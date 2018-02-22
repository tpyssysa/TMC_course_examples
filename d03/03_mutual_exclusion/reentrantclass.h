/***************************************************************************
*                                                                          *
*                reentrantclss.h for 03_mutual_exclusion                   *
*                Created on  : Tue Mar 28 2017 07:43                       *
*                Made by : Qt training <training@qt.io>                    *
*                                                                          *
***************************************************************************/

#ifndef REENTRANTCLASS_H
#define REENTRANTCLASS_H

#include <QMutex>

class ReentrantClass
{
public:
    ReentrantClass();
    ~ReentrantClass();
    void incCounter();
    void decCounter();
    int counter();
private:
    volatile int m_counter;
    QMutex m_mutex;
};

#endif // REENTRANTCLASS_H

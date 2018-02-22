/***************************************************************************
*                                                                          *
*                picalculator.cpp for 05_thread_management                 *
*                Created on  : Mon Mar 27 2017 12:36                       *
*                Made by : Qt training <training@qt.io>                    *
*                                                                          *
***************************************************************************/

#include "picalculator.h"
#include <float.h>
#include <QtMath>
#include <QTimer>
#include <QThread>
#include <QProgressBar>
#include <QAbstractEventDispatcher>
#include <QLabel>

PiCalculator::PiCalculator(QObject *observer, QObject *label, QThread *worker, QObject *parent) :
    QObject(parent),
    m_observer(observer),
    m_label(label),
    m_timer(new QTimer(this)),
    m_pi(1.0)
{
}

PiCalculator::~PiCalculator()
{
}

void PiCalculator::run()
{
    m_timer->start(TIMER_DURATION);
    qreal k(3.0);
    bool minus(true);

    Q_FOREVER {
        m_pi += minus ? -1/k : 1/k;
        k += 2;
        minus = !minus;
        // Note! The pi value is 4 * m_pi; 
    }
}


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
    connect(m_timer, &QTimer::timeout, [this] () { thread()->requestInterruption(); });
    moveToThread(worker);
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
        if (thread()->isInterruptionRequested() || k >= (DBL_MAX - 2)) {
            thread()->quit();
            return;
        }

        m_pi += minus ? -1/k : 1/k;
        k += 2;
        minus = !minus;
        if (qFloor(k) % 999 == 0) {
            QMetaObject::invokeMethod(m_observer, "setValue", Qt::QueuedConnection, Q_ARG(int, ((qreal)TIMER_DURATION - m_timer->remainingTime()) / (qreal)TIMER_DURATION * 100));
            QMetaObject::invokeMethod(m_label, "setText", Qt::QueuedConnection, Q_ARG(QString, QString("Pi = %1").arg(m_pi * 4.0, 0, 'g', 20)));
            thread()->eventDispatcher()->processEvents(QEventLoop::AllEvents);
        }
    }
}


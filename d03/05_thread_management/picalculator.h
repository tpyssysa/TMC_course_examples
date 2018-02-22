/***************************************************************************
*                                                                          *
*                picalculator.h for 05_thread_management                   *
*                Created on  : Mon Mar 27 2017 12:36                       *
*                Made by : Qt training <training@qt.io>                    *
*                                                                          *
***************************************************************************/

#ifndef PICALCULATOR_H
#define PICALCULATOR_H

#include <QObject>

QT_FORWARD_DECLARE_CLASS(QLabel)
QT_FORWARD_DECLARE_CLASS(QTimer)

const quint32 TIMER_DURATION = 5000;

class PiCalculator : public QObject
{
    Q_OBJECT
public:
    explicit PiCalculator(QObject *observer = 0, QObject *label = 0, QThread *worker = 0, QObject *parent = 0);
    ~PiCalculator();

public Q_SLOTS:
    void run();

private:
    QObject *m_observer;
    QObject *m_label;
    QTimer *m_timer;
    qreal m_pi;
};

#endif // PICALCULATOR_H

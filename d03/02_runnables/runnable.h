/***************************************************************************
*                                                                          *
*                runnable.h for 02_runnables                               *
*                Created on  : Mon Mar 27 2017 10:02                       *
*                Made by : Qt training <training@qt.io>                    *
*                                                                          *
***************************************************************************/

#ifndef RUNNABLE_H
#define RUNNABLE_H

#include <QRunnable>
#include <QString>
#include <QModelIndex>

QT_FORWARD_DECLARE_CLASS(QStandardItemModel)

class Runnable : public QRunnable
{
public:
    Runnable(const QString &fileToBeInverted, QStandardItemModel *model, const QModelIndex &currentIndex);

protected:
    void run() Q_DECL_OVERRIDE;

private:
    QString m_fileToBeInverted;
    QStandardItemModel *m_model;
    QModelIndex m_index;
};

#endif // RUNNABLE_H

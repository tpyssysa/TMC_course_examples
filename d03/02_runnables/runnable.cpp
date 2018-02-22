/***************************************************************************
*                                                                          *
*                runnable.cpp for 02_runnables                             *
*                Created on  : Mon Mar 27 2017 10:02                       *
*                Made by : Qt training <training@qt.io>                    *
*                                                                          *
***************************************************************************/

#include "runnable.h"
#include <QStandardItemModel>

Runnable::Runnable(const QString &fileToBeInverted, QStandardItemModel *model, const QModelIndex &currentIndex) :
    m_fileToBeInverted(fileToBeInverted),
    m_model(model),
    m_index(currentIndex)
{
}

void Runnable::run()
{
    QImage image(m_fileToBeInverted);
    image.invertPixels();

    QMetaObject::invokeMethod(m_model, "setData", Qt::QueuedConnection, Q_ARG(QModelIndex, m_index), Q_ARG(QVariant, image), Q_ARG(int, Qt::DecorationRole));
}

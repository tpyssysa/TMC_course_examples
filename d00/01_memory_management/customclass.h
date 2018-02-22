/***************************************************************************
*                                                                          *
*                customclass.h for 01_memory_management                    *
*                Created on  : Thu Mar 09 2017 11:00                       *
*                Made by : Qt training <training@qt.io>                    *
*                                                                          *
***************************************************************************/

#ifndef CUSTOMCLASS_H
#define CUSTOMCLASS_H

#include <QObject>

class CustomClass : public QObject
{
    Q_OBJECT
public:
    explicit CustomClass(QObject *parent = 0);
    ~CustomClass();

signals:

public slots:
};

#endif // CUSTOMCLASS_H

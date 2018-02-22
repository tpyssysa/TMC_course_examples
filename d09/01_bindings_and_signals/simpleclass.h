/***************************************************************************
*                                                                          *
*                simpleclass.h for 01_bindings_and_signals                 *
*                Created on  : Mon Apr 17 2017 12:08                       *
*                Made by : Qt training <training@qt.io>                    *
*                                                                          *
***************************************************************************/

#ifndef SIMPLECLASS_H
#define SIMPLECLASS_H

#include <QObject>
#include <QColor>

class SimpleClass : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QColor backgroundColor MEMBER m_backgroundColor NOTIFY backgroundColorChanged)
    Q_PROPERTY(QString userText MEMBER m_userText NOTIFY userTextChanged)

public:
    explicit SimpleClass(QObject *parent = 0);

Q_SIGNALS:
    void backgroundColorChanged();
    void userTextChanged();

private:
    QColor m_backgroundColor;
    QString m_userText;
};

#endif // SIMPLECLASS_H

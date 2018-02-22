/***************************************************************************
*                                                                          *
*                button.h for 04_painted_items                             *
*                Created on  : Mon Apr 17 2017 15:29                       *
*                Made by : Qt training <training@qt.io>                    *
*                                                                          *
***************************************************************************/

#ifndef BUTTON_H
#define BUTTON_H

#include <QQuickPaintedItem>

class Button : public QQuickPaintedItem
{
    Q_OBJECT
    Q_PROPERTY(QString buttontext MEMBER m_buttontext NOTIFY onButtonTextChanged)
    Q_PROPERTY(QColor backgroundColor MEMBER m_backgroundColor NOTIFY onBackgroundColorChanged)
public:
    Button(QQuickPaintedItem *parent = Q_NULLPTR);

protected:
    void paint(QPainter *painter) Q_DECL_OVERRIDE;
    void mousePressEvent(QMouseEvent *event) Q_DECL_OVERRIDE;

Q_SIGNALS:
    void onButtonTextChanged();
    void onBackgroundColorChanged();
    void mousePressed();

private:
    QString m_buttontext;
    QColor m_backgroundColor;
};

#endif // BUTTON_H

/***************************************************************************
*                                                                          *
*                customwidget.h for 06_custom_widgets                      *
*                Created on  : Fri Mar 17 2017 17:55                       *
*                Made by : Qt training <training@qt.io>                    *
*                                                                          *
***************************************************************************/

#ifndef CUSTOMWIDGET_H
#define CUSTOMWIDGET_H

#include <QWidget>
#include <QImage>

QT_FORWARD_DECLARE_CLASS(QPropertyAnimation)

const int ROTATIONS = 360;
const int DURATION = 1000;

class CustomWidget : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(int angle MEMBER m_angle)

public:
    explicit CustomWidget(QWidget *parent = Q_NULLPTR, Qt::WindowFlags flags = Qt::WindowFlags());
    ~CustomWidget();

protected:
    void paintEvent(QPaintEvent *) Q_DECL_OVERRIDE;
    void mousePressEvent(QMouseEvent *) Q_DECL_OVERRIDE;

private:
    QPropertyAnimation *m_animation;
    QImage m_transparentGradient;
    int m_angle;
};

#endif // CUSTOMWIDGET_H

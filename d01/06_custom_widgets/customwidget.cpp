/***************************************************************************
*                                                                          *
*                customwidget.h for 06_custom_widgets                      *
*                Created on  : Fri Mar 17 2017 17:55                       *
*                Made by : Qt training <training@qt.io>                    *
*                                                                          *
***************************************************************************/

#include "customwidget.h"
#include <QPainter>
#include <QPropertyAnimation>
#include <QtDebug>

CustomWidget::CustomWidget(QWidget *parent, Qt::WindowFlags flags)
    : QWidget(parent, flags),
      m_animation(Q_NULLPTR),
      m_angle(0)
{
}

CustomWidget::~CustomWidget()
{
}

void CustomWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    int width(rect().width());
    int height (rect().height());

    // Draw a radial gradient
    QRadialGradient g(width / 2, height / 2, 5);
    g.setColorAt(0.0, Qt::yellow);
    g.setColorAt(1.0, Qt::black);
    g.setSpread(QGradient::ReflectSpread);
    painter.setBrush(g);
    painter.drawEllipse(0, 0, width, height);

    // Draw an image and its reflection
    QImage image(":/icons/qt_logo.png");
    int imageWidth(image.width());
    int imageHeight(image.height());

    painter.save();
    painter.translate(width / 2, height / 2);
    painter.rotate(m_angle);
    painter.translate(-width / 2, -height / 2);
    painter.drawImage((width - imageWidth)/ 2, (height - imageHeight) / 2, image);
    painter.restore();

    if (m_transparentGradient.isNull()) {
        m_transparentGradient = QImage(imageWidth, imageHeight, QImage::Format_ARGB32_Premultiplied);
        QPainter imagePainter(&m_transparentGradient);
        QLinearGradient lG2(imageWidth/2, 0, imageWidth/2, imageHeight);
        lG2.setColorAt(0.0, QColor(1, 1, 1, 255));
        lG2.setColorAt(1.0, QColor(1, 1, 1, 0));
        imagePainter.setBrush(lG2);
        imagePainter.setPen(Qt::NoPen);
        imagePainter.drawRect(0, 0, imageWidth, imageHeight);

        imagePainter.setCompositionMode(QPainter::CompositionMode_DestinationIn);
        imagePainter.drawImage(0, 0, image);

        imagePainter.setCompositionMode(QPainter::CompositionMode_DestinationOver);
        imagePainter.drawImage(0, 0, image);
    }

    painter.drawImage((width - imageWidth)/ 2, (height + imageHeight) / 2, m_transparentGradient.mirrored());
}

void CustomWidget::mousePressEvent(QMouseEvent *)
{
    if (m_animation) {
        if (m_animation->state() == QAbstractAnimation::Running)
            return;
    }
    else {
        m_animation = new QPropertyAnimation(this, "angle", this);
        m_animation->setDuration(DURATION);
        m_animation->setStartValue(0);
        m_animation->setEndValue(ROTATIONS);
        connect(m_animation, &QPropertyAnimation::valueChanged,
                [this] () { update(); });
    }

    m_animation->start();
}


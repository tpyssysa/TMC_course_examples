/***************************************************************************
*                                                                          *
*                videowidget.cpp for 01_subtitles                          *
*                Created on  : Mon Apr 03 2017 09:07                       *
*                Made by : Qt training <training@qt.io>                    *
*                                                                          *
***************************************************************************/

#include "videowidget.h"
#include "videosurface.h"
#include <QVideoSurfaceFormat>
#include <QPainter>
#include <QPaintEvent>

VideoWidget::VideoWidget(QWidget *parent)
    : QWidget(parent)
    , surface(0)
{
    setAutoFillBackground(false);
    setAttribute(Qt::WA_NoSystemBackground, true);

    QPalette palette = this->palette();
    palette.setColor(QPalette::Background, Qt::black);
    setPalette(palette);

    setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);

    surface = new VideoSurface(this);
}

VideoWidget::~VideoWidget()
{
    delete surface;
}

QSize VideoWidget::sizeHint() const
{
    return surface->surfaceFormat().sizeHint();
}

void VideoWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    if (surface->isActive()) {
        const QRect videoRect = surface->videoRect();

        if (!videoRect.contains(event->rect())) {
            QRegion region = event->region();
            region = region.subtracted(videoRect);

            QBrush brush = palette().background();

            foreach (const QRect &rect, region.rects())
                painter.fillRect(rect, brush);
        }

        surface->paint(&painter);
    } else {
        painter.fillRect(event->rect(), palette().background());
    }
}

void VideoWidget::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);

    surface->updateVideoRect();
}

/***************************************************************************
*                                                                          *
*                videosurface.cpp for 01_subtitles                         *
*                Created on  : Thu Apr 03 2017 08:55                       *
*                Made by : Qt training <training@qt.io>                    *
*                                                                          *
***************************************************************************/

#include "videosurface.h"
#include "videowidget.h"
#include <QVideoSurfaceFormat>
#include <QPainter>
#include <QFontMetrics>

VideoSurface::VideoSurface(QWidget *widget, QObject *parent)
    : QAbstractVideoSurface(parent),
      m_widget(widget),
      m_imageFormat(QImage::Format_Invalid)
{
}

QList<QVideoFrame::PixelFormat> VideoSurface::supportedPixelFormats(
        QAbstractVideoBuffer::HandleType handleType) const
{
}

bool VideoSurface::isFormatSupported(const QVideoSurfaceFormat &format) const
{
}

bool VideoSurface::start(const QVideoSurfaceFormat &format)
{
    return false;
}

void VideoSurface::stop()
{
}

bool VideoSurface::present(const QVideoFrame &frame)
{
    return false;
}

void VideoSurface::updateVideoRect()
{
    QSize size = surfaceFormat().sizeHint();
    size.scale(m_widget->size().boundedTo(size), Qt::KeepAspectRatio);

    m_targetRect = QRect(QPoint(0, 0), size);
    m_targetRect.moveCenter(m_widget->rect().center());
}

void VideoSurface::paint(QPainter *painter)
{
}


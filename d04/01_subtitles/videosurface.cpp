/***************************************************************************
*                                                                          *
*                videosurface.cpp for 01_subtitles                         *
*                Created on  : Mon Apr 03 2017 08:55                       *
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
    if (handleType == QAbstractVideoBuffer::NoHandle) {
        return QList<QVideoFrame::PixelFormat>()
                << QVideoFrame::Format_RGB32
                << QVideoFrame::Format_ARGB32
                << QVideoFrame::Format_ARGB32_Premultiplied
                << QVideoFrame::Format_RGB565
                << QVideoFrame::Format_RGB555;
    } else {
        return QList<QVideoFrame::PixelFormat>();
    }
}

bool VideoSurface::isFormatSupported(const QVideoSurfaceFormat &format) const
{
    const QImage::Format imageFormat = QVideoFrame::imageFormatFromPixelFormat(format.pixelFormat());
    const QSize size = format.frameSize();

    return imageFormat != QImage::Format_Invalid
            && !size.isEmpty()
            && format.handleType() == QAbstractVideoBuffer::NoHandle;
}

bool VideoSurface::start(const QVideoSurfaceFormat &format)
{
    const QImage::Format imageFormat = QVideoFrame::imageFormatFromPixelFormat(format.pixelFormat());
    const QSize size = format.frameSize();

    if (imageFormat != QImage::Format_Invalid && !size.isEmpty()) {
        m_imageFormat = imageFormat;
        m_imageSize = size;
        m_sourceRect = format.viewport();

        QAbstractVideoSurface::start(format);

        m_widget->updateGeometry();
        updateVideoRect();

        return true;
    } else {
        return false;
    }
}

void VideoSurface::stop()
{
    QAbstractVideoSurface::stop();
}

bool VideoSurface::present(const QVideoFrame &frame)
{
    if (surfaceFormat().pixelFormat() != frame.pixelFormat()
            || surfaceFormat().frameSize() != frame.size()) {
        setError(IncorrectFormatError);
        stop();

        return false;
    } else {
        m_currentFrame = frame;

        m_widget->repaint(m_targetRect);

        return true;
    }
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
    if (m_currentFrame.map(QAbstractVideoBuffer::ReadOnly)) {
        const QTransform oldTransform = painter->transform();

        if (surfaceFormat().scanLineDirection() == QVideoSurfaceFormat::BottomToTop) {
            painter->scale(1, -1);
            painter->translate(0, -m_widget->height());
        }

        QImage image(
                    m_currentFrame.bits(),
                    m_currentFrame.width(),
                    m_currentFrame.height(),
                    m_currentFrame.bytesPerLine(),
                    m_imageFormat);

        painter->drawImage(m_targetRect, image, m_sourceRect);

        QPen pen(QColor("black"));
        QBrush brush(QColor(255, 255, 255, 127));
        QFont font("TimesNewRoman", 42);
        QFontMetrics metrics(font);
        QString subtitle("Subtitle");
        painter->setPen(pen);
        painter->setFont(font);
        painter->setBrush(brush);
        QPointF subtitlePos(m_widget->width() * 0.1, m_widget->height() * 0.8);
        painter->drawRect(subtitlePos.x(), subtitlePos.y(), metrics.width(subtitle), 42);
        painter->drawText(QRect(subtitlePos.x(), subtitlePos.y(), m_widget->width(), m_widget->height()), subtitle);

        painter->setTransform(oldTransform);

        m_currentFrame.unmap();
    }
}


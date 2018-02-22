/***************************************************************************
*                                                                          *
*                videosurface.h for 01_subtitles                           *
*                Created on  : Mon Apr 03 2017 08:56                       *
*                Made by : Qt training <training@qt.io>                    *
*                                                                          *
***************************************************************************/

#ifndef VIDEOSURFACE_H
#define VIDEOSURFACE_H

#include <QAbstractVideoSurface>
#include <QImage>
#include <QRect>
#include <QVideoFrame>

class VideoSurface : public QAbstractVideoSurface
{
    Q_OBJECT

public:
    VideoSurface(QWidget *widget, QObject *parent = 0);

    QList<QVideoFrame::PixelFormat> supportedPixelFormats(
            QAbstractVideoBuffer::HandleType handleType = QAbstractVideoBuffer::NoHandle) const Q_DECL_OVERRIDE;
    bool isFormatSupported(const QVideoSurfaceFormat &format) const Q_DECL_OVERRIDE;

    bool start(const QVideoSurfaceFormat &format) Q_DECL_OVERRIDE;
    void stop() Q_DECL_OVERRIDE;

    bool present(const QVideoFrame &frame) Q_DECL_OVERRIDE;

    QRect videoRect() const { return m_targetRect; }
    void updateVideoRect();

    void paint(QPainter *painter);

private:
    QWidget *m_widget;
    QImage::Format m_imageFormat;
    QRect m_targetRect;
    QSize m_imageSize;
    QRect m_sourceRect;
    QVideoFrame m_currentFrame;
};


#endif // VIDEOSURFACE_H

/***************************************************************************
*                                                                          *
*                videowidget.h for 01_subtitles                            *
*                Created on  : Thu Apr 03 2017 09:07                       *
*                Made by : Qt training <training@qt.io>                    *
*                                                                          *
***************************************************************************/

#ifndef VIDEOWIDGET_H
#define VIDEOWIDGET_H

#include "videosurface.h"
#include <QWidget>

QT_FORWARD_DECLARE_CLASS(QAbstractVideoSurface)

class VideoWidget : public QWidget
{
public:
    VideoWidget(QWidget *parent = 0);
    ~VideoWidget();

    QAbstractVideoSurface *videoSurface() const { return surface; }
    QSize sizeHint() const Q_DECL_OVERRIDE;

protected:
    void paintEvent(QPaintEvent *event);
    void resizeEvent(QResizeEvent *event);

private:
    VideoSurface *surface;
};

#endif // VIDEOWIDGET_H

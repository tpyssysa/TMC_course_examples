/***************************************************************************
*                                                                          *
*                imageitem.h for 05_sg_items                               *
*                Created on  : Mon Apr 17 2017 16:37                       *
*                Made by : Qt training <training@qt.io>                    *
*                                                                          *
***************************************************************************/

#ifndef IMAGEITEM_H
#define IMAGEITEM_H

#include <QQuickItem>

QT_FORWARD_DECLARE_CLASS(QSGTexture)

class ImageItem : public QQuickItem
{
    Q_OBJECT
    Q_PROPERTY(QString imageSource MEMBER m_imageSource NOTIFY onImageSourceChanged)
public:
    ImageItem(QQuickItem *parent = 0);
    ~ImageItem();

Q_SIGNALS:
    void onImageSourceChanged();

protected:
    QSGNode *updatePaintNode(QSGNode *, UpdatePaintNodeData *) Q_DECL_OVERRIDE;

private:
    QSGTexture *m_texture;
    QString m_imageSource;
};

#endif // IMAGEITEM_H

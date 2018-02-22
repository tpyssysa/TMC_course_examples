/***************************************************************************
*                                                                          *
*                imageitem.cpp for 05_sg_items                             *
*                Created on  : Mon Apr 17 2017 16:37                       *
*                Made by : Qt training <training@qt.io>                    *
*                                                                          *
***************************************************************************/

#include "imageitem.h"
#include <QSGSimpleTextureNode>
#include <QSGTexture>
#include <QQuickWindow>

ImageItem::ImageItem(QQuickItem *parent)
    : QQuickItem(parent),
      m_texture(Q_NULLPTR)
{
    setFlag(ItemHasContents, true);
}

ImageItem::~ImageItem()
{
    m_texture->deleteLater();
}

QSGNode *ImageItem::updatePaintNode(QSGNode *node, QQuickItem::UpdatePaintNodeData *)
{
    QSGSimpleTextureNode *textureNode = static_cast<QSGSimpleTextureNode *>(node);
    if (!textureNode) {
        textureNode = new QSGSimpleTextureNode();
        QImage image(m_imageSource);
        if (m_texture)
            m_texture->deleteLater();
        m_texture = window()->createTextureFromImage(image);
        textureNode->setTexture(m_texture);
    }
    textureNode->setRect(0, 0, width(), height());
    textureNode->setFiltering(QSGTexture::Linear);

    return textureNode;
}

/***************************************************************************
*                                                                          *
*                Page.qml for 05_styling                                   *
*                Created on  : Thu Jul 06 2017 10:57                       *
*                Made by : Qt training <training@qt.io>                    *
*                                                                          *
***************************************************************************/

import QtQuick 2.9
import QtQuick.Templates 2.2 as T
import QtQuick.Controls.Universal 2.2
import Theme 1.0

T.Page {
    id: control

    property alias backgroundVisible: backgroundImg.visible

    implicitWidth: Math.max(background ? background.implicitWidth : 0,
                            Math.max(contentWidth,
                                     header && header.visible ? header.implicitWidth : 0,
                                     footer && footer.visible ? footer.implicitWidth : 0) + leftPadding + rightPadding)
    implicitHeight: Math.max(background ? background.implicitHeight : 0,
                             contentHeight + topPadding + bottomPadding
                             + (header && header.visible ? header.implicitHeight + spacing : 0)
                             + (footer && footer.visible ? footer.implicitHeight + spacing : 0))

    contentWidth: contentItem.implicitWidth || (contentChildren.length === 1 ? contentChildren[0].implicitWidth : 0)
    contentHeight: contentItem.implicitHeight || (contentChildren.length === 1 ? contentChildren[0].implicitHeight : 0)

    background: Rectangle {
        color: control.Universal.background
        Image {
            id: backgroundImg
            anchors.centerIn: parent
            source: Theme.backgroundImage
        }
    }
}

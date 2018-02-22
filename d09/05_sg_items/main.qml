/***************************************************************************
*                                                                          *
*                main.qml for 05_sg_items                                  *
*                Created on  : Thu Mar 30 2017 09:33                       *
*                Made by : Qt training <training@qt.io>                    *
*                                                                          *
***************************************************************************/

import QtQuick 2.6
import QtQuick.Window 2.2
import Controls 1.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("SG Items")

    ImageItem {
        anchors.fill: parent
        imageSource: ":/images/lady.png"
    }
}


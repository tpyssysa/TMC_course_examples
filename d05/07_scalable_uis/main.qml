/***************************************************************************
*                                                                          *
*                main.qml for 07_scalable_uis                              *
*                Created on  : Thu Mar 30 2017 09:33                       *
*                Made by : Qt training <training@qt.io>                    *
*                                                                          *
***************************************************************************/

import QtQuick 2.6
import QtQuick.Window 2.2

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Scalable UIs")

    Text {
        id: textField
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        text: qsTr("Qt 42")
        width: parent.width
        height: parent.height
        fontSizeMode: Text.Fit
        minimumPixelSize: 5
        font.pixelSize: 100
        wrapMode: Text.WordWrap
    }
}

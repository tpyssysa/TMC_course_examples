/***************************************************************************
*                                                                          *
*                Notification.qml for 00_custom_item                       *
*                Created on  : Tue Apr 04 2017 10:18                       *
*                Made by : Qt training <training@qt.io>                    *
*                                                                          *
***************************************************************************/

import QtQuick 2.6

Rectangle {
    property alias buttonText: textField.text

    border.width: 5

    gradient: Gradient {
        GradientStop {
            position: 0.00;
            color: "#000000";
        }
        GradientStop {
            position: 1.00;
            color: "#b9b3b3";
        }
    }

    Text {
        id: textField
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        text: qsTr("Hello world")
        width: parent.width
        height: parent.height
        fontSizeMode: Text.Fit
        minimumPixelSize: 10
        font.pixelSize: 108
        wrapMode: Text.WordWrap
        color: "white"
    }
}

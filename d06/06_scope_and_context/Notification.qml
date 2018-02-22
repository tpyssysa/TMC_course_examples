/***************************************************************************
*                                                                          *
*                Notification.qml for 06_scope_and_context                 *
*                Created on  : Tue Apr 04 2017 13:36                       *
*                Made by : Qt training <training@qt.io>                    *
*                                                                          *
***************************************************************************/

import QtQuick 2.6

Rectangle {
    property alias buttonText: textField.text

    signal buttonClicked(real x, real y, var mouseEvent)

    function show(notificationText) {
        textField.text = notificationText;
        opacity = 0.7;
        timer.start();
    }

    border.width: 5
    opacity: 0.2
    visible: opacity > 0.2

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

    Behavior on opacity {
        NumberAnimation {
            duration: 2000
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
        PropertyAnimation {
            id: rotationAnimation
            target: textField
            properties: "rotation"
            from: 0
            to: 360
        }
    }

    Timer {
        id: timer
        interval: 2000
        onTriggered: {
            parent.opacity = 0.2;
        }
    }

    MouseArea {
        anchors.fill: parent
        onClicked: {
            rotationAnimation.running = !rotationAnimation.running;
            buttonClicked(mouse.x, mouse.y, mouse);
        }
    }
}


/***************************************************************************
*                                                                          *
*                main.qml for 03_signal_handling                           *
*                Created on  : Thu Mar 30 2017 09:28                       *
*                Made by : Qt training <training@qt.io>                    *
*                                                                          *
***************************************************************************/

import QtQuick 2.6
import QtQuick.Window 2.2

Window {
    id: window
    visible: true
    width: 640
    height: 480
    title: qsTr("Signal handling")

    Rectangle {
        anchors.fill: parent
        gradient: Gradient {
            GradientStop {
                position: 0.00;
                color: "#403737";
            }
            GradientStop {
                position: 1.00;
                color: "#ffffff";
            }
        }
    }

    Image {
        id: image
        source: "qrc:/images/qt_logo.png"
        asynchronous: true
        onStatusChanged: text.text = (image.status === Image.Ready) ? qsTr("Ready") : qsTr("Loading")
    }

    Text {
        id: text
        anchors.centerIn: parent
        text: qsTr("Hello world!")
    }

    TextInput {
        id: textInput
        x: parent.width * 0.1; y: parent.height * 0.1
        width: parent.width * 0.75
        font { family: "Helvetica";
            pixelSize: (parent.height > parent.width)
                       ? parent.width * 0.4
                       : parent.height * 0.4 }
        text: qsTr("Qt Quick")
        focus: true
        onTextChanged: color = "green"
        wrapMode: Text.WordWrap
    }

    Component.onCompleted: {
        textInput.text = qsTr("Input text");
        textInput.width = Qt.binding(function() { return window.width * 0.75; });
    }
}


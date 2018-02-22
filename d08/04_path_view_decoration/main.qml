/***************************************************************************
*                                                                          *
*                main.qml for 04_path_view_decoration                      *
*                Created on  : Thu Mar 30 2017 09:30                       *
*                Made by : Qt training <training@qt.io>                    *
*                                                                          *
***************************************************************************/

import QtQuick 2.6
import QtQuick.Window 2.2

Window {
    title: qsTr("Path View")
    id: root
    width: 640; height: 480
    visible: true
    color: "white"

    Component {
        id: nameDelegate
        Item {
            width: childrenRect.width
            height: childrenRect.height

            opacity: PathView.opacity
            scale: PathView.scale

            Text {
                id: delegateText
                text: name; font.pixelSize: 24
            }
        }
    }

    PathView {
        anchors.fill: parent
        model: NameModel { }
        delegate: nameDelegate
        focus: true
        visible: true
        path: Path {
            startX: 40; startY: 0
            PathAttribute { name: "opacity"; value: 0.5 }
            PathAttribute { name: "scale"; value: 0.5 }
            PathLine { x: width / 2 - 80; y: height - 80 }
            PathAttribute { name: "opacity"; value: 1.0 }
            PathAttribute { name: "scale"; value: 1.0 }
            PathLine { x: width / 2 + 80; y: height - 80 }
            PathAttribute { name: "opacity"; value: 1.0 }
            PathAttribute { name: "scale"; value: 1.0 }
            PathLine { x: width; y: 0 }
            PathAttribute { name: "opacity"; value: 0.5 }
            PathAttribute { name: "scale"; value: 0.5 }
        }
    }
}

/***************************************************************************
*                                                                          *
*                main.qml for 06_efficient_delegates                       *
*                Created on  : Thu Mar 30 2017 09:33                       *
*                Made by : Qt training <training@qt.io>                    *
*                                                                          *
***************************************************************************/

import QtQuick 2.6
import QtQuick.Window 2.2

Window {
    id: root
    title: qsTr("Efficient delegates")
    width: 640; height: 480
    visible: true
    color: "white"

    Component {
        id: nameDelegate
        Item {
            property var view: PathView
            width: delegateText.width
            height: delegateText.height
            Text {
                id: delegateText
                opacity: view.opacity
                scale: view.scale
                text: name; font.pixelSize: 24
            }
            MouseArea {
                anchors.fill: parent
                onClicked: {
                    if (loader.sourceComponent == undefined) {
                        loader.sourceComponent = intensiveItem;
                    }
                    else {
                        loader.sourceComponent = undefined;
                    }
                }
            }
            Loader {
                id: loader
                asynchronous: true
            }

            Component {
                id: intensiveItem
                Grid {
                    id: grid
                    columns: 100
                    spacing: 20
                    Repeater {
                        model: 100000
                        Rectangle {
                            width: 10
                            height: 10
                            color: "black"
                        }
                    }
                }
            }
        }
    }

    PathView {
        anchors.fill: parent
        model: NameModel { }
        delegate: nameDelegate
        focus: true
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

/***************************************************************************
*                                                                          *
*                main.qml for 03_list_view_decoration                      *
*                Created on  : Thu Mar 30 2017 09:28                       *
*                Made by : Qt training <training@qt.io>                    *
*                                                                          *
***************************************************************************/

import QtQuick 2.6
import QtQuick.Window 2.2

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("List view decoration")

    Component {
        id: nameDelegate
        Text {
            text: name
            font.pixelSize: 32
        }
    }

    ListView {
        id: listView

        width: parent.width
        anchors.top: parent.top
        anchors.bottom: label.top
        anchors.bottomMargin: 4

        model: Animals { }
        delegate: nameDelegate
        focus: true
        clip: true

        section.property: "team"
        section.criteria: ViewSection.FullString
        section.delegate: Rectangle {
            color: "#b0dfb0"
            width: parent.width
            height: childrenRect.height + 4
            Text { anchors.horizontalCenter: parent.horizontalCenter
                font.pixelSize: 16
                font.bold: true
                text: section }
        }

        header: Rectangle {
            width: parent.width; height: 10;
            color: "pink"
        }
        footer: Rectangle {
            width: parent.width; height: 10;
            color: "lightblue"
        }
        highlight: Rectangle {
            color: "lightgray"
        }
    }

    Text {
        id: label
        anchors.bottom: parent.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        text: "<b>" + listView.currentItem.text +
              "</b> is current"
        font.pixelSize: 16
    }
}


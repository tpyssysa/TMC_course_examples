/***************************************************************************
*                                                                          *
*                main.qml for 05_grid_view                                 *
*                Created on  : Thu Mar 30 2017 09:33                       *
*                Made by : Qt training <training@qt.io>                    *
*                                                                          *
***************************************************************************/

import QtQuick 2.6
import QtQuick.Window 2.2
import QtQuick.Controls 2.3 as QQC2
import QtQuick.Controls 1.4

Window {
    id: root
    visible: true
    width: 640
    height: 480
    title: qsTr("GridView vs. TableView")

    Component.onCompleted: {
        for (var i = 0; i < 100; ++i) {
            simpleModel.append({"name": "Item " + i, "btnChecked": "false"});
        }
    }

    Row {
        anchors.fill: parent
        GridView {
            id: gridView
            width: parent.width / 2
            height: parent.height
            model: simpleModel
            delegate: gridViewDelegate
        }
        TableView {
            id: tableView
            width: parent.width / 2
            height: parent.height

            TableViewColumn {
                id: col1
                title: "Item"
                width: tableView.contentItem.width * 0.6
                role: "name"
            }
            TableViewColumn {
                title: "Button"
                width: tableView.contentItem.width * 0.2
                role: "btnChecked"
                delegate: tableViewDelegate
                resizable: true
            }

            model: simpleModel
        }
    }

    Component {
        id: gridViewDelegate
        QQC2.RadioDelegate {
            display: QQC2.AbstractButton.TextBesideIcon
            text: name
            autoExclusive: false
            checked: (btnChecked === "false") ? false : true
            onClicked: {
                checked ? simpleModel.setProperty(index, "btnChecked", "true") : simpleModel.setProperty(index, "btnChecked", "false");
            }
        }
    }

    Component {
        id: tableViewDelegate
        QQC2.RadioDelegate {
            id: tableViewRadioBtnDelegate
            autoExclusive: false
            checked: (styleData.value === "false") ? false : true
            onClicked: {
                checked ? simpleModel.setProperty(styleData.row, "btnChecked", "true") : simpleModel.setProperty(styleData.row, "btnChecked", "false");
            }
            indicator: Rectangle {
                implicitWidth: tableViewRadioBtnDelegate.height
                implicitHeight: implicitWidth
                radius: implicitHeight / 2
                color: "transparent"
                border.color: "#b0b0b0"

                Rectangle {
                    anchors { fill: parent; margins: 3 }
                    radius: width / 2
                    color: tableViewRadioBtnDelegate.checked ? "black" : "transparent"
                }
            }
        }
    }

    ListModel {
        id: simpleModel
    }
}

/***************************************************************************
*                                                                          *
*                main.qml for 01_qml_models                                *
*                Created on  : Thu Mar 30 2017 09:23                       *
*                Made by : Qt training <training@qt.io>                    *
*                                                                          *
***************************************************************************/

import QtQuick 2.6
import QtQuick.Window 2.2

Window {
    title: qsTr("Model View")
    id: root
    width: 400; height: 400
    visible: true
    color: "gray"

    Component {
        id: delegate
        PhonebookDelegate {
            width: parent.width
        }
    }

    Component {
        id: highlight
        Rectangle {
            color: "lightsteelblue"
            radius: 5
        }
    }

    ListView {
        anchors.fill: parent
        model: contactModel
        delegate: delegate
        highlight: highlight
        focus: true
    }

    PhonebookModel {
        id: contactModel
    }

    WorkerScript {
        id: contactGenerator
        source: "qrc:/contactGenerator.js"
    }

    Component.onCompleted: {
        contactGenerator.sendMessage({'model': contactModel})
    }
}

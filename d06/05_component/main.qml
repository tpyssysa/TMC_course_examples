/***************************************************************************
*                                                                          *
*                main.qml for 06_component                                 *
*                Created on  : Thu Mar 30 2017 09:33                       *
*                Made by : Qt training <training@qt.io>                    *
*                                                                          *
***************************************************************************/

import QtQuick 2.6
import QtQml 2.2
import QtQuick.Window 2.2

Window {
    title: qsTr("Component")
    id: root
    width: 1024; height: 600
    visible: true
    color: "black"

    Grid {
        id: grid
        anchors.fill: parent
        spacing: 2
        columns: 10

        Instantiator {
            model: 100
            delegate: Component {
                Rectangle {
                    parent: grid
                    width: parent.width / parent.columns - parent.spacing
                    height: width
                    color: "white"
                }
            }
        }
    }
}



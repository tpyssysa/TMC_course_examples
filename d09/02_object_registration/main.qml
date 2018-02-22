/***************************************************************************
*                                                                          *
*                main.qml for 02_object_registration                       *
*                Created on  : Thu Mar 30 2017 09:27                       *
*                Made by : Qt training <training@qt.io>                    *
*                                                                          *
***************************************************************************/

import QtQuick 2.6
import QtQuick.Window 2.2
import EmployeeTypes 1.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Object registration")

    Row {
        anchors.fill: parent
        TextEdit {
            font.pixelSize: 20
            text: employee.name + " "
        }
        TextEdit {
            font.pixelSize: 20
            text: employee.salary
        }
    }

    Employee {
        id: employee
    }
}

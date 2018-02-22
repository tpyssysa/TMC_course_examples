/***************************************************************************
*                                                                          *
*                main.qml for 03_cpp_models                                *
*                Created on  : Thu Mar 30 2017 09:28                       *
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
    title: qsTr("C++ Models")

    ListView {
        anchors.fill: parent
        focus: true
        model: EmployeeModel
        delegate: Row {
            width: parent.width
            spacing: 10
            TextInput {
                text: name
                font.pixelSize: 20
                width: parent.width * 0.8
                wrapMode: Text.WordWrap
                onTextChanged: {
                    if (name != text)
                        name = text;
                }
            }
            TextInput {
                text: salary
                font.pixelSize: 20
                width: parent.width * 0.15
                onTextChanged: {
                    if (salary != text)
                        salary = text;
                }
            }
        }
    }

    Component.onCompleted: {
        for (var i = 0; i < 10; ++i) {
            EmployeeModel.addEmployee("Employee " + i, i * 1000 + i / 100);
        }
    }
}

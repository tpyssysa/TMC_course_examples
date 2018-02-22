/***************************************************************************
*                                                                          *
*                PhonebookDelegate.qml for 01_qml_models                   *
*                Created on  : Tue Apr 04 2017 14:59                       *
*                Made by : Qt training <training@qt.io>                    *
*                                                                          *
***************************************************************************/

import QtQuick 2.6

Item {
    height: childrenRect.height
    Text {
        text: name
    }
    Text {
        anchors.right: parent.right;
        text: number
    }
}

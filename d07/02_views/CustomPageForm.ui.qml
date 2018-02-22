/***************************************************************************
*                                                                          *
*                CustomPageForm.ui.qml for 02_views                        *
*                Created on  : Tue Jul 04 2017 13:19                       *
*                Made by : Qt training <training@qt.io>                    *
*                                                                          *
***************************************************************************/

import QtQuick 2.4
import QtQuick.Controls 2.2

Item {
    width: 400
    height: 400

    property alias title: page.title

    Page {
        id: page
        anchors.fill: parent

        Label {
            id: label
            x: 153
            y: 171
            text: page.title
            fontSizeMode: Text.FixedSize
            font.pointSize: 48
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
        }
    }
}

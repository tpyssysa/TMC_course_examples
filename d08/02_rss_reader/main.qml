/***************************************************************************
*                                                                          *
*                main.qml for 02_rss_reader                                *
*                Created on  : Thu Mar 30 2017 09:27                       *
*                Made by : Qt training <training@qt.io>                    *
*                                                                          *
***************************************************************************/

import QtQuick 2.6
import QtQuick.Window 2.2
import QtQuick.XmlListModel 2.0
import QtWebEngine 1.4

Window {
    id: root
    visible: true
    width: 640
    height: 480
    title: qsTr("RSS Reader")

    XmlListModel {
        id: rssModel
        source: "http://feeds.bbci.co.uk/news/rss.xml"
        query: "//item"

        XmlRole { name: "title"; query: "title/string()" }
        XmlRole { name: "link"; query: "link/string()" }
    }

    Component {
        id: xmlDelegate
        TitleDelegate {
            width: root.width
            height: root.height * 0.1
            onLinkActivated: webengineView.url = link
        }
    }

    ListView {
        anchors { top: parent.top; left: parent.left; right: parent.right }
        height: parent.height / 2
        clip: true
        model: rssModel
        delegate: xmlDelegate
    }

    WebEngineView {
        id: webengineView
        anchors { bottom: parent.bottom; left: parent.left; right: parent.right }
        height: parent.height / 2
    }
}

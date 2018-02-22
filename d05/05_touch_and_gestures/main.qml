/***************************************************************************
*                                                                          *
*                main.qml for 05_touch_and_gestures                        *
*                Created on  : Thu Mar 30 2017 09:33                       *
*                Made by : Qt training <training@qt.io>                    *
*                                                                          *
***************************************************************************/

import QtQuick 2.6
import QtQuick.Window 2.2

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Touch and gestures")

    Image {
        source: "qrc:/images/qt_logo.png"

        PinchArea {
            anchors.fill: parent
            pinch.target: parent

            pinch.minimumScale: 0.5
            pinch.maximumScale: 2.0

            pinch.minimumRotation: -3600
            pinch.maximumRotation: 3600
        }
    }

    MultiPointTouchArea {
        anchors.fill: parent
        touchPoints: [
            TouchPoint { id: point1 },
            TouchPoint { id: point2 }
        ]
        onTouchUpdated: {
            var str = "Count: " + touchPoints.length + "\n"
            for( var i=0; i < touchPoints.length; i++) {
                str = str + touchPoints[i].pointId + ": (" + touchPoints[i].x + " , " + touchPoints[i].y + ")\n"
            }
            console.log(str);
        }
    }

    Image {
        x: point1.x - width / 2
        y: point1.y - height / 2
        visible: point1.pressed
        source: "qrc:/images/qt_logo.png"
    }

    Image {
        x: point2.x - width / 2
        y: point2.y - height / 2
        visible: point2.pressed
        source: "qrc:/images/qt_logo.png"
    }
}


import QtQuick 2.0

Item {
    id: container
    property alias cellColor: rectangle.color
    signal clicked(cellColor: color)

    width: 110; height: 160

    Rectangle {
        id: rectangle
        anchors.fill: parent
    }

    MouseArea {
        anchors.fill: parent
        onClicked: container.clicked(container.cellColor)
    }
}

import QtQuick 2.0

Rectangle{
    property var count
    property var imageUrl

    width:50
    height:50
    anchors.topMargin: 20


    Image{
        id: checkMark
        anchors.left: parent.left
        width:20
        height:20
        source: imageUrl
    }

    Text{
        anchors.left: checkMark.right
        text: count
    }

}

import QtQuick 2.0
import QtQuick.Controls 2.15
Item {

    Text {
        id: difficultyText
        text: "Difficulty"
        font.pointSize: 24
    }

    Column {
        id: difficultyColumn
        anchors.top: difficultyText.bottom
        RadioButton {
            checked: questionInstance.difficulty === "easy"
            text: qsTr("Easy")
            onClicked: {
                questionInstance.difficulty = "easy"
            }
        }

        RadioButton {
            checked: questionInstance.difficulty === "medium"
            text: qsTr("Medium")
            onClicked: questionInstance.difficulty ="medium"
        }
    }
    Text {
        anchors.left: difficultyText.right
        anchors.leftMargin: 50
        id:pictureText
        text: "Picture"
        font.pointSize: 24
    }
    Grid {
        id: grid
        columns: 3
        rows: Math.ceil(imageInfo.getUrlsSize() / 3)
        anchors.top: pictureText.bottom
        anchors.left: pictureText.left
        Repeater {
            model: imageInfo.getUrlsSize();
            Rectangle{
                id: borderRectangle
                width: 150
                height: 150
                border.width: 5;
                border.color: imageInfo.url.localeCompare(image.source) === 0 ? "black": "white";

                Rectangle{
                    id: rectangle
                    anchors.horizontalCenter: borderRectangle.horizontalCenter
                    anchors.verticalCenter: borderRectangle.verticalCenter
                    width: borderRectangle.width - 2*borderRectangle.border.width
                    height: borderRectangle.height - 2*borderRectangle.border.width

                    Image{
                        id: image
                        anchors.fill: parent
                        fillMode: Image.PreserveAspectFit
                        height: 100
                        width: 100
                        source: imageInfo.getUrlByIndex(index)
                        MouseArea {
                            anchors.fill: parent
                            onClicked: {
                                imageInfo.url = image.source }
                            onDoubleClicked: {
                                imageInfo.url = image.source
                                game.visible = !game.visible
                            }
                        }

                    }
                }
            }
        }
    }
}

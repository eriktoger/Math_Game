import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.15
import Question 1.0

Window{
    id: window;
    width: 640
    height: 480
    title: qsTr("Math Game")
    visible: true


    Question{
        id: questionInstance
        onCorrectIncremented: imageInfo.showMore()
        onDifficultyChanged: questionInstance.newQuestion()
        // https://forum.qt.io/topic/99556/communication-between-qml-objects/2
    }

//    ImageInfo{
//        //id: imageInfo
//    }

    Button{
        id: optionsButton
        text: game.visible ? "Options \n ctrl + o" : "Game \n ctrl + o";
        onClicked:  game.visible = !game.visible;
        height: 50
        anchors {
            bottom: game.bottom
            left: game.left
            leftMargin: 10
        }

        Shortcut {
            sequence: "Ctrl+O"
            onActivated: {
                if(!imageInfo.imageDone) game.visible = !game.visible
            }
        }

    }
    Button {
        anchors.bottom: game.bottom
        anchors.left: optionsButton.right
        anchors.leftMargin: 10
        text: "Quit"
        onClicked: Qt.quit()
        height: optionsButton.height
    }


    Game {
        anchors.fill: parent
        id:game;
    }

    Options{
        visible: !game.visible
    }

}

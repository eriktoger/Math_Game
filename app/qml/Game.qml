import QtQuick 2.0
//import io.qt.examples.question 1.0
Item {

    QuestionText{
        id: questionText
    }

    AnswerBox{
        id: answerBox
        //questionText: questionText
    }

    Counter {
        id: correctCounter
        count: questionInstance.correct
        imageUrl:"images/icons/greenCheckMark.png"
        anchors.top: questionText.bottom
    }

    Counter {
        count: questionInstance.errors
        imageUrl:"images/icons/Icon_Simple_Error.png"
        anchors.top: questionText.bottom
        anchors.left: correctCounter.right
    }

    Rectangle{
        id: frame
        anchors.right: game.right
        color: "black"
        width: 330
        height: 480

        Image {
            id: image
            anchors.horizontalCenter: frame.horizontalCenter
            anchors.verticalCenter: frame.verticalCenter
            fillMode: Image.PreserveAspectFit
            width: frame.width
            height: frame.height

            source: imageInfo.url
            states: [
                    State {
                        name: "done"
                        when: imageInfo.imageDone
                        PropertyChanges { target: frame; width: window.width; height:window.height }
                    }
                ]
            transitions: Transition {
                        from: ""; to: "done"; reversible: true
                        ParallelAnimation {
                            NumberAnimation { properties: "width,height"; duration: 500; easing.type: Easing.InOutQuad }

                        }
                    }
            MouseArea {
                anchors.fill: parent
                onClicked: {
                    imageInfo.imageDone = false }
            }


        }

        Filter{

            x: (image.width - image.paintedWidth) / 2
            y: (image.height - image.paintedHeight)/2
            width: image.paintedWidth
            height: image.paintedHeight

        }
    }

}

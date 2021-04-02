import QtQuick 2.12
import QtQuick.Window 2.12

Rectangle{

    id: rec
    anchors.left:  questionText.right
    border.width: 2
    width:100
    height:40
     y: 30
    TextInput {
        id: answer
        focus: game.visible
        leftPadding: 5
        maximumLength: 5

        font.pointSize: 24; font.bold: true
        font.weight: Font.DemiBold
        onAccepted: {
            questionInstance.gradeQuestion(answer.text)
            answer.text =""
        }
    }
}

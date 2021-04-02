import QtQuick 2.0
Grid {
    id: hideImage
    //anchors.right: game.right
    rows: 3
    columns: 3


    Repeater {
        id: repeater
        model: 9
        Rectangle{
            width: Math.ceil(hideImage.width / 3)
            height: Math.ceil( hideImage.height /3)
            color:  "black"

            function getCurrent(){
                imageInfo.setCurrentByIndex(index);
                return imageInfo.current;
            }
            states: State {
                name: "brighter"; when: getCurrent()
                PropertyChanges { target: repeater.itemAt(index); color: "transparent" }
            }

            transitions: Transition {
                to: "brighter"
                ColorAnimation { duration: 1000 }
            }
        }

    }

}

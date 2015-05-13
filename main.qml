import QtQuick 2.3
import QtQuick.Controls 1.2
import Frameless 1.0
import QtQuick.Layouts 1.1

FramelessWindow {
    id: root;
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    color: systemPalette.base;


    SystemPalette {
        id: systemPalette;
    }

    Label {
        text: qsTr("Hello World")
        anchors.centerIn: parent
    }

    MenuBar {
            Menu {
                title: "File"
                MenuItem { text: "Open..." }
                MenuItem { text: "Close" }
            }

            Menu {
                title: "Edit"
                MenuItem { text: "Cut" }
                MenuItem { text: "Copy" }
                MenuItem { text: "Paste" }
            }
        }

    ToolBar {
        RowLayout {
            height: 55;
            Rectangle {
                anchors.fill: parent;
                color: "red"
            }
        }
    }


}

from PyQt5 import QtCore, QtGui, QtWidgets
from PyQt5.QtWidgets import QApplication
import sys
import layout
import serial.tools.list_ports

def SerialPorts():
    PortList = serial.tools.list_ports.comports()

    return [i.device for i in PortList]

class PIDApp(QtWidgets.QMainWindow, layout.Ui_MainWindow):
    def __init__(self, parent=None):
        super(PIDApp, self).__init__(parent)
        self.setupUi(self)
        self.StartButton.clicked.connect(self.StartButtonClick)
        self.StopButton.clicked.connect(self.StopButtonClick)
        self.RefreshPortButton.clicked.connect(self.RefreshPortList)
        self.PortDropDownList.activated[str].connect(self.PortDropDownListOption)
   
    def StartButtonClick(self):
        print("start button clicked")
    
    def StopButtonClick(self):
        print("stop button clicked")

    def RefreshPortList(self):
        self.PortDropDownList.clear()
        self.PortDropDownList.addItems(SerialPorts())

    def PortDropDownListOption(self, text):
        print("option selected: {}".format(text))

# https://www.youtube.com/watch?v=Y-8N1dPFsVE to dynamically resize
def main():
    app = QApplication(sys.argv)
    form = PIDApp()
    form.show()
    app.exec_()

if __name__ == '__main__':
    main()
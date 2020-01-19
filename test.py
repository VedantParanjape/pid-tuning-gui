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
        self.SetPointSendButton.clicked.connect(self.SetPointSendButtonClick)
        self.KpSendButton.clicked.connect(self.KpSendButtonClick)
        self.KiSendButton.clicked.connect(self.KiSendButtonClick)
        self.KdSendButton.clicked.connect(self.KdSendButtonClick)
        self.SetPointSpinBox.valueChanged.connect(self.SetPointChanged)
        self.KpSpinBox.valueChanged.connect(self.KpChanged)
        self.KiSpinBox.valueChanged.connect(self.KiChanged)
        self.KdSpinBox.valueChanged.connect(self.KdChanged)
        self.SetPoint = 0
        self.Kp = 0
        self.Ki = 0
        self.Kd = 0

    def StartButtonClick(self):
        print("start button clicked")
    
    def StopButtonClick(self):
        print("stop button clicked")

    def RefreshPortList(self):
        self.PortDropDownList.clear()
        self.PortDropDownList.addItems(SerialPorts())

    def PortDropDownListOption(self, text):
        print("option selected: {}".format(text))

    def SetPointSendButtonClick(self):
        print("set point: {}".format(self.SetPoint))

    def KpSendButtonClick(self):
        self.KpLabel.setText("Kp: " + str(self.Kp))
        print("kp: {}".format(self.Kp))

    def KiSendButtonClick(self):
        self.KiLabel.setText("Ki: " + str(self.Ki))
        print("ki: {}".format(self.Ki))
    
    def KdSendButtonClick(self):
        self.KdLabel.setText("Kd: " + str(self.Kd))
        print("kd: {}".format(self.Kd))

    def SetPointChanged(self):
        self.SetPoint = self.SetPointSpinBox.value()

    def KpChanged(self):
        self.Kp = self.KpSpinBox.value()
   
    def KiChanged(self):
        self.Ki = self.KiSpinBox.value()

    def KdChanged(self):
        self.Kd = self.KdSpinBox.value()
# https://www.youtube.com/watch?v=Y-8N1dPFsVE to dynamically resize

def main():
    app = QApplication(sys.argv)
    form = PIDApp()
    form.show()
    app.exec_()

if __name__ == '__main__':
    main()
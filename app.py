from PyQt5 import QtCore, QtGui, QtWidgets
from PyQt5.QtWidgets import QApplication
import sys
from UI import layout
import serial.tools.list_ports
import pyqtgraph
import time
import math
import pyqtgraph as pg
import json

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
        self.SerialPortOptionButton.setChecked(True)
        self.UDPPortOptionButton.setChecked(False)
        self.PortDropDownList.setVisible(True)
        self.RefreshPortButton.setVisible(True)
        self.ServerAddressTextBox.setVisible(False)
        self.ConnectUDPPortButton.setVisible(False)
        self.SerialPortOptionButton.toggled.connect(self.SerialPortOptionButtonToggled)
        self.UDPPortOptionButton.toggled.connect(self.UDPPortOptionButtonToggled)
        self.ConnectUDPPortButton.clicked.connect(self.ConnectUDPPortButtonClicked)
        self.ServerAddressTextBox.textChanged.connect(self.ServerAddressChanged)
        self.SetPoint = 0
        self.Kp = 0
        self.Ki = 0
        self.Kd = 0
        self.timer = pg.QtCore.QTimer(self)
        self.prev_i = 0
        self.dict_config = {}
        self.SerialPortMode = True
        self.UDPPortMode = False
        self.SerialPort = 'dev/ttyUSB0'
        self.UDPAddress = '127.0.0.1:990'

    def write_config(self):
        self.dict_config.update({'SetPoint' : self.SetPoint})
        self.dict_config.update({'Kp' : self.Kp})
        self.dict_config.update({'Ki' : self.Ki})
        self.dict_config.update({'Kd' : self.Kd})
        
        print(self.dict_config)
        fwrite = open('config.json', "w")
        json.dump(self.dict_config, fwrite)

    def update_plot(self):
        X = [float(i/0.01) for i in range(self.prev_i, self.prev_i+100)]
        self.prev_i = self.prev_i + 100
        Y = [math.sin(X[i]) for i in range(100)]
        Y1 = [math.cos(X[i]) for i in range(100)]
        CenterPoint = self.prev_i - 50
        self.PlotWidgetUpLeft.setXRange(float(CenterPoint-5)/0.01, float(CenterPoint+5)/0.01)
        self.PlotWidgetUpRight.setXRange(float(CenterPoint-5)/0.01, float(CenterPoint+5)/0.01)
        self.PlotWidgetBottomLeft.setXRange(float(CenterPoint-5)/0.01, float(CenterPoint+5)/0.01)
        self.PlotWidgetBottomCenter.setXRange(float(CenterPoint-5)/0.01, float(CenterPoint+5)/0.01)
        self.PlotWidgetBottomRight.setXRange(float(CenterPoint-5)/0.01, float(CenterPoint+5)/0.01)
        
        time.sleep(0.01)
        
        self.PlotWidgetUpLeft.plot(X,Y, clear=True)
        self.PlotWidgetUpRight.plot(X,Y1, clear=True)
        self.PlotWidgetBottomLeft.plot(X,Y, clear=True)
        self.PlotWidgetBottomCenter.plot(X,Y1, clear=True)
        self.PlotWidgetBottomRight.plot(X,Y, clear=True)


    def StartButtonClick(self):
        print("start button clicked")
        self.timer.timeout.connect(self.update_plot)
        self.timer.start(0)

    def StopButtonClick(self):
        self.timer.stop()
        print("stop button clicked")

    def RefreshPortList(self):
        self.PortDropDownList.clear()
        self.PortDropDownList.addItems(SerialPorts())

    def PortDropDownListOption(self, text):
        self.SerialPort = text
        print("option selected: {}".format(text))
    
    def SetPointSendButtonClick(self):
        self.write_config()
        print("set point: {}".format(self.SetPoint))

    def KpSendButtonClick(self):
        self.KpLabel.setText(self.KpLabel.text()[0:8] + str(self.Kp))
        self.write_config()
        print("kp: {}".format(self.Kp))

    def KiSendButtonClick(self):
        self.KiLabel.setText(self.KiLabel.text()[0:8] + str(self.Ki))
        self.write_config()
        print("ki: {}".format(self.Ki))
    
    def KdSendButtonClick(self):
        self.KdLabel.setText(self.KdLabel.text()[0:8] + str(self.Kd))
        self.write_config()
        print("kd: {}".format(self.Kd))

    def SetPointChanged(self):
        self.SetPoint = self.SetPointSpinBox.value()

    def KpChanged(self):
        self.Kp = self.KpSpinBox.value()
   
    def KiChanged(self):
        self.Ki = self.KiSpinBox.value()

    def KdChanged(self):
        self.Kd = self.KdSpinBox.value()

    def SerialPortOptionButtonToggled(self):
        self.SerialPortMode = True
        self.UDPPortMode = False
        self.UDPPortOptionButton.setChecked(False)

        self.PortDropDownList.setVisible(True)
        self.RefreshPortButton.setVisible(True)
        self.ServerAddressTextBox.setVisible(False)
        self.ConnectUDPPortButton.setVisible(False)
    
    def UDPPortOptionButtonToggled(self):
        self.SerialPortMode = False
        self.UDPPortMode = True
        self.SerialPortOptionButton.setChecked(False)

        self.PortDropDownList.setVisible(False)
        self.RefreshPortButton.setVisible(False)
        self.ServerAddressTextBox.setVisible(True)
        self.ConnectUDPPortButton.setVisible(True)

    def ServerAddressChanged(self, text):
        self.UDPAddress = text

    def ConnectUDPPortButtonClicked(self):
        print("connect clicked ip addr: {}".format(self.UDPAddress))
# https://www.youtube.com/watch?v=Y-8N1dPFsVE to dynamically resize

def main():
    app = QApplication(sys.argv)
    form = PIDApp()
    form.show()
    app.exec_()

if __name__ == '__main__':
    main()
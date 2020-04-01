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
from server.tcp import tcp_server
from server.udp import udp_server

def SerialPorts():
    PortList = serial.tools.list_ports.comports()

    return [i.device for i in PortList]


class PIDApp(QtWidgets.QMainWindow, layout.Ui_MainWindow):
    def __init__(self, parent=None, tcp_handle=None, udp_handle=None):
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
        self.dict_config = {}
        self.PID_dict = {}
        self.SerialPortMode = True
        self.UDPPortMode = False
        self.SerialPort = 'dev/ttyUSB0'
        self.UDPAddress = '127.0.0.1:990'
        self.tcp_handle = tcp_handle
        self.udp_handle = udp_handle
        self.udp_handle.run(True)
        # print("i am here")
        # self.PID_dict = self.udp_handle.recv_data(150)
        # print(self.PID_dict)

        self.prev_i = 0
        self.X = [float(i/0.02) for i in range(0, 2000)]
        self.Y = [math.sin(self.X[i]) for i in range(2000)]
        self.Y1 = [math.cos(self.X[i]) for i in range(2000)]

        self.UpLeft = self.PlotWidgetUpLeft.plot(self.X, self.Y)
        self.UpRight = self.PlotWidgetUpRight.plot(self.X, self.Y1)
        self.BottomLeft = self.PlotWidgetBottomLeft.plot(self.X, self.Y)
        self.BottomCenter = self.PlotWidgetBottomCenter.plot(self.X, self.Y1)
        self.BottomRight = self.PlotWidgetBottomRight.plot(self.X, self.Y)

    def write_config(self):
        self.dict_config.update({'Kp' : self.Kp})
        self.dict_config.update({'Ki' : self.Ki})
        self.dict_config.update({'Kd' : self.Kd})
        self.dict_config.update({'SetPoint' : self.SetPoint})
        
        print(self.dict_config)
        fwrite = open('config.json', "w")
        json.dump(self.dict_config, fwrite)

        # self.tcp_handle.send_data(json.dumps(self.dict_config))
        self.tcp_handle.message_pipe.put(json.dumps(self.dict_config))

    def update_plot(self):
        print("update_plot")
        self.PID_dict = self.udp_handle.recv_data(150)
        print(self.PID_dict)

        self.prev_i = self.prev_i + 1
        CenterPoint = self.prev_i - 0.5
        self.PlotWidgetUpLeft.setXRange(float(CenterPoint-5)/0.01, float(CenterPoint+5)/0.01)
        self.PlotWidgetUpRight.setXRange(float(CenterPoint-5)/0.01, float(CenterPoint+5)/0.01)
        self.PlotWidgetBottomLeft.setXRange(float(CenterPoint-5)/0.01, float(CenterPoint+5)/0.01)
        self.PlotWidgetBottomCenter.setXRange(float(CenterPoint-5)/0.01, float(CenterPoint+5)/0.01)
        self.PlotWidgetBottomRight.setXRange(float(CenterPoint-5)/0.01, float(CenterPoint+5)/0.01)
        
        self.X = self.X[1:]
        self.X.append(self.X[-1] + 0.01)
        self.Y = self.Y[1:]
        self.Y.append(math.sin(self.X[-1]))
        self.Y1 = self.Y1[1:]
        self.Y1.append(math.cos(self.X[-1]))

        time.sleep(0.05)

        self.UpLeft.setData(self.X, self.Y)
        self.UpRight.setData(self.X, self.Y1)
        self.BottomLeft.setData(self.X, self.Y)
        self.BottomCenter.setData(self.X, self.Y1)
        self.BottomRight.setData(self.X, self.Y)


    def StartButtonClick(self):
        print("start button clicked")
        self.timer.setInterval(50)
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
    
    tcp_handle = tcp_server(2121)
    tcp_handle.run(True)
    # tcp_handle.send_data

    udp_handle = udp_server(1212)
    # udp_handle.run(True)
    # udp_handle.send_data

    form = PIDApp(tcp_handle=tcp_handle, udp_handle=udp_handle)
    form.show()
    app.exec_()

if __name__ == '__main__':
    main()
from PyQt5 import QtCore, QtGui, QtWidgets
from PyQt5.QtWidgets import QApplication
import sys
from ui import layout
import pyqtgraph
import time
import math
import pyqtgraph as pg
import json
from server.tcp import tcp_server
from server.udp import udp_server
from server.tcp import tcp_client

class PIDApp(QtWidgets.QMainWindow, layout.Ui_MainWindow):
    def __init__(self, parent=None, tcp_handle=None, udp_handle=None):
        super(PIDApp, self).__init__(parent)
        self.setupUi(self)
        self.StartButton.clicked.connect(self.StartButtonClick)
        self.StopButton.clicked.connect(self.StopButtonClick)
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
        self.timer = pg.QtCore.QTimer(self)
        self.dict_sent = {}
        self.tcp_handle = tcp_handle
        self.udp_handle = udp_handle
        self.start_button_status = False
        self.stop_button_status = True

        # Initialize
        self.xAxis = list(range(100))
        self.pTerm = [0] * 100
        self.iTerm = [0] * 100
        self.dTerm = [0] * 100
        self.currentTerm = [0] * 100
        self.errorTerm = [0] * 100

        # See if this can be put in layout.py
        penUpLeft = pg.mkPen(color=(255, 255, 255), width=2)
        penUpRight = pg.mkPen(color=(255, 255, 255), width=2)
        penBottomLeft = pg.mkPen(color=(255, 0, 0), width=2)
        penBottomCentre = pg.mkPen(color=(0, 255, 0), width=2)
        penBottomRight = pg.mkPen(color=(0, 0, 255), width=2)

        # Initial Plot
        self.UpLeft = self.PlotWidgetUpLeft.plot(self.xAxis, self.currentTerm, pen=penUpLeft)
        self.UpRight = self.PlotWidgetUpRight.plot(self.xAxis, self.errorTerm, pen=penUpRight)
        self.BottomLeft = self.PlotWidgetBottomLeft.plot(self.xAxis, self.pTerm, pen=penBottomLeft)
        self.BottomCenter = self.PlotWidgetBottomCenter.plot(self.xAxis, self.iTerm, pen=penBottomCentre)
        self.BottomRight = self.PlotWidgetBottomRight.plot(self.xAxis, self.dTerm, pen=penBottomRight)

    def closeEvent(self, event):
        print("close event")
        reply = QtGui.QMessageBox.question(self, 'Message',
            "Are you sure to quit?", QtGui.QMessageBox.Yes, QtGui.QMessageBox.No)

        if reply == QtGui.QMessageBox.Yes:
            event.accept() 
        else:
            event.ignore()
    
    def write_config(self):
        self.dict_sent.update({'Kp' : self.Kp})
        self.dict_sent.update({'Ki' : self.Ki})
        self.dict_sent.update({'Kd' : self.Kd})
        self.dict_sent.update({'SetPoint' : self.SetPoint})
        
        print(self.dict_sent)
        fwrite = open('sent.json', "w")
        json.dump(self.dict_sent, fwrite)
        self.tcp_handle.message_pipe.put(json.dumps(self.dict_sent))

    def update_plot(self):
        data = self.udp_handle.message_pipe.get()

        self.KpLabel.setText(self.KpLabel.text()[0:8] + str(data['P']))
        self.KiLabel.setText(self.KiLabel.text()[0:8] + str(data['I']))
        self.KdLabel.setText(self.KdLabel.text()[0:8] + str(data['D']))
        
        # Removing the first entry
        self.xAxis = self.xAxis[1:]
        self.pTerm = self.pTerm[1:]
        self.iTerm = self.iTerm[1:]
        self.dTerm = self.dTerm[1:]
        self.currentTerm = self.currentTerm[1:]
        self.errorTerm = self.errorTerm[1:]

        # Updating the Values
        self.xAxis.append(self.xAxis[-1] + 1)
        self.pTerm.append(data['P'])
        self.iTerm.append(data['I'])
        self.dTerm.append(data['D'])
        self.currentTerm.append(data['current'])
        self.errorTerm.append(data['error'])


        # Updating the Plot
        self.UpLeft.setData(self.xAxis, self.currentTerm)
        self.UpRight.setData(self.xAxis, self.errorTerm)
        self.BottomLeft.setData(self.xAxis, self.pTerm)
        self.BottomCenter.setData(self.xAxis, self.iTerm)
        self.BottomRight.setData(self.xAxis, self.dTerm)

    def StartButtonClick(self):
        if self.start_button_status == False and self.stop_button_status == True:
            print("start button clicked")
            self.start_button_status = True
            self.stop_button_status = False
            self.timer.setInterval(50)
            self.timer.timeout.connect(self.update_plot)
            self.timer.start(0)
        else:
            print("already running")

    def StopButtonClick(self):
        if self.start_button_status == True and self.stop_button_status == False:
            print("stop button clicked")
            self.start_button_status = False
            self.stop_button_status = True
            self.timer.stop()
        else:
            print("already stopped")

    def SetPointSendButtonClick(self):
        self.write_config()
        print("set point: {}".format(self.SetPoint))

    def KpSendButtonClick(self):
        self.write_config()
        print("kp: {}".format(self.Kp))

    def KiSendButtonClick(self):       
        self.write_config()
        print("ki: {}".format(self.Ki))
    
    def KdSendButtonClick(self):
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

# https://www.youtube.com/watch?v=Y-8N1dPFsVE to dynamically resize

def main():
    app = QApplication(sys.argv)

    tcp_handle = tcp_server(2121)
    tcp_handle.run()

    udp_handle = udp_server(1212)
    udp_handle.run()

    form = PIDApp(udp_handle=udp_handle, tcp_handle=tcp_handle)
    form.show()
    app.exec_()

if __name__ == '__main__':
    main()

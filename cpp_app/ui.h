/********************************************************************************
** Form generated from reading UI file 'layout.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LAYOUT_H
#define UI_LAYOUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include <QObject>
#include "qcustomplot.h"
#include "pid_message_config.h"
#include <iostream>
#include <boost/lexical_cast.hpp>

#define _SETPOINT_STEP_ (0.01)
#define _KD_STEP_ (0.01)
#define _KI_STEP_ (0.01)
#define _KP_STEP_ (0.01)
#define _INITIAL_KP_ (1.00)
#define _INITIAL_KI_ (0.00)
#define _INITIAL_KD_ (0.00)
#define _INITIAL_SETPOINT_ (0.00)

//QT_BEGIN_NAMESPACE

class Ui_MainWindow:public QObject
{
Q_OBJECT
public:
    QWidget *centralwidget;
    QPushButton *StartButton;
    QPushButton *StopButton;
    QGroupBox *SetPointBox;
    QGridLayout *gridLayout;
    QDoubleSpinBox *SetPointSpinBox;
    QPushButton *SetPointSendButton;
    QGroupBox *KpBox;
    QGridLayout *gridLayout_2;
    QPushButton *KpSendButton;
    QDoubleSpinBox *KpSpinBox;
    QGroupBox *KiBox;
    QGridLayout *gridLayout_3;
    QDoubleSpinBox *KiSpinBox;
    QPushButton *KiSendButton;
    QGroupBox *KdBox;
    QGridLayout *gridLayout_4;
    QDoubleSpinBox *KdSpinBox;
    QPushButton *KdSendButton;
    QGroupBox *PIDParametersBox;
    QLabel *KdLabel;
    QLabel *KiLabel;
    QLabel *KpLabel;
    QLabel *GraphicViewUpLeftLabel;
    QLabel *GraphicViewBottomLeftLabel;
    QLabel *GraphicViewBottomCenterLabel;
    QLabel *GraphicViewUpRightLabel;
    QLabel *GraphicViewBottomRightLabel;
    QCustomPlot *PlotWidgetUpLeft;
    QCustomPlot *PlotWidgetUpRight;
    QCustomPlot *PlotWidgetBottomLeft;
    QCustomPlot *PlotWidgetBottomCenter;
    QCustomPlot *PlotWidgetBottomRight;

    void setupUi();

    void retranslateUi(QMainWindow *MainWindow);
    Ui_MainWindow(QMainWindow *w);
    virtual ~Ui_MainWindow(){};
    QMainWindow *MainWindow;
signals:
    void send_vals(pid_term_send_values _vals);
    void start_sig(bool _start);
    void stop_sig(bool _start);
public slots:
    void on_send_kd();
    void on_send_ki();
    void on_send_kp();
    void on_send_setpoint();
    void on_start();
    void on_stop();
private:
    pid_term_send_values vals;
    std::string d_term = "D Term: ";
    std::string p_term = "P Term: ";
    std::string i_term = "I Term: ";
    bool start = false;

};
//QT_END_NAMESPACE

#endif // UI_LAYOUT_H

#include "ui.h"

Ui_MainWindow::Ui_MainWindow(QMainWindow *w)
{
    //
    MainWindow = w;
    setupUi();
}

void Ui_MainWindow::setupUi()
{
    if (MainWindow->objectName().isEmpty())
        MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
    MainWindow->resize(1155, 652);
    MainWindow->setUnifiedTitleAndToolBarOnMac(false);
    centralwidget = new QWidget(MainWindow);
    centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
    StartButton = new QPushButton(centralwidget);
    StartButton->setObjectName(QString::fromUtf8("StartButton"));
    StartButton->setGeometry(QRect(10, 10, 100, 31));
    StopButton = new QPushButton(centralwidget);
    StopButton->setObjectName(QString::fromUtf8("StopButton"));
    StopButton->setGeometry(QRect(120, 10, 100, 31));
    SetPointBox = new QGroupBox(centralwidget);
    SetPointBox->setObjectName(QString::fromUtf8("SetPointBox"));
    SetPointBox->setGeometry(QRect(10, 80, 189, 74));
    gridLayout = new QGridLayout(SetPointBox);
    gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
    SetPointSpinBox = new QDoubleSpinBox(SetPointBox);
    SetPointSpinBox->setObjectName(QString::fromUtf8("SetPointSpinBox"));

    gridLayout->addWidget(SetPointSpinBox, 0, 0, 1, 1);

    SetPointSendButton = new QPushButton(SetPointBox);
    SetPointSendButton->setObjectName(QString::fromUtf8("SetPointSendButton"));

    gridLayout->addWidget(SetPointSendButton, 0, 1, 1, 1);

    KpBox = new QGroupBox(centralwidget);
    KpBox->setObjectName(QString::fromUtf8("KpBox"));
    KpBox->setGeometry(QRect(10, 180, 189, 74));
    gridLayout_2 = new QGridLayout(KpBox);
    gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
    KpSendButton = new QPushButton(KpBox);
    KpSendButton->setObjectName(QString::fromUtf8("KpSendButton"));

    gridLayout_2->addWidget(KpSendButton, 0, 1, 1, 1);

    KpSpinBox = new QDoubleSpinBox(KpBox);
    KpSpinBox->setObjectName(QString::fromUtf8("KpSpinBox"));

    gridLayout_2->addWidget(KpSpinBox, 0, 0, 1, 1);

    KiBox = new QGroupBox(centralwidget);
    KiBox->setObjectName(QString::fromUtf8("KiBox"));
    KiBox->setGeometry(QRect(10, 280, 189, 74));
    gridLayout_3 = new QGridLayout(KiBox);
    gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
    KiSpinBox = new QDoubleSpinBox(KiBox);
    KiSpinBox->setObjectName(QString::fromUtf8("KiSpinBox"));

    gridLayout_3->addWidget(KiSpinBox, 0, 0, 1, 1);

    KiSendButton = new QPushButton(KiBox);
    KiSendButton->setObjectName(QString::fromUtf8("KiSendButton"));

    gridLayout_3->addWidget(KiSendButton, 0, 1, 1, 1);

    KdBox = new QGroupBox(centralwidget);
    KdBox->setObjectName(QString::fromUtf8("KdBox"));
    KdBox->setGeometry(QRect(10, 380, 189, 74));
    gridLayout_4 = new QGridLayout(KdBox);
    gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
    KdSpinBox = new QDoubleSpinBox(KdBox);
    KdSpinBox->setObjectName(QString::fromUtf8("KdSpinBox"));

    gridLayout_4->addWidget(KdSpinBox, 0, 0, 1, 1);

    KdSendButton = new QPushButton(KdBox);
    KdSendButton->setObjectName(QString::fromUtf8("KdSendButton"));

    gridLayout_4->addWidget(KdSendButton, 0, 1, 1, 1);

    PIDParametersBox = new QGroupBox(centralwidget);
    PIDParametersBox->setObjectName(QString::fromUtf8("PIDParametersBox"));
    PIDParametersBox->setGeometry(QRect(10, 500, 191, 121));
    KdLabel = new QLabel(PIDParametersBox);
    KdLabel->setObjectName(QString::fromUtf8("KdLabel"));
    KdLabel->setGeometry(QRect(10, 90, 171, 21));
    KiLabel = new QLabel(PIDParametersBox);
    KiLabel->setObjectName(QString::fromUtf8("KiLabel"));
    KiLabel->setGeometry(QRect(10, 60, 171, 21));
    KpLabel = new QLabel(PIDParametersBox);
    KpLabel->setObjectName(QString::fromUtf8("KpLabel"));
    KpLabel->setGeometry(QRect(10, 30, 171, 21));
    GraphicViewUpLeftLabel = new QLabel(centralwidget);
    GraphicViewUpLeftLabel->setObjectName(QString::fromUtf8("GraphicViewUpLeftLabel"));
    GraphicViewUpLeftLabel->setGeometry(QRect(420, 10, 101, 19));
    QPalette palette;
    QBrush brush(QColor(0, 0, 0, 255));
    brush.setStyle(Qt::SolidPattern);
    palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
    QBrush brush1(QColor(255, 255, 255, 255));
    brush1.setStyle(Qt::SolidPattern);
    palette.setBrush(QPalette::Active, QPalette::Button, brush1);
    palette.setBrush(QPalette::Active, QPalette::Light, brush1);
    palette.setBrush(QPalette::Active, QPalette::Midlight, brush1);
    QBrush brush2(QColor(127, 127, 127, 255));
    brush2.setStyle(Qt::SolidPattern);
    palette.setBrush(QPalette::Active, QPalette::Dark, brush2);
    QBrush brush3(QColor(170, 170, 170, 255));
    brush3.setStyle(Qt::SolidPattern);
    palette.setBrush(QPalette::Active, QPalette::Mid, brush3);
    palette.setBrush(QPalette::Active, QPalette::Text, brush);
    palette.setBrush(QPalette::Active, QPalette::BrightText, brush1);
    palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
    palette.setBrush(QPalette::Active, QPalette::Base, brush1);
    palette.setBrush(QPalette::Active, QPalette::Window, brush1);
    palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
    palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush1);
    QBrush brush4(QColor(255, 255, 220, 255));
    brush4.setStyle(Qt::SolidPattern);
    palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush4);
    palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
    palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
    palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
    palette.setBrush(QPalette::Inactive, QPalette::Light, brush1);
    palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush1);
    palette.setBrush(QPalette::Inactive, QPalette::Dark, brush2);
    palette.setBrush(QPalette::Inactive, QPalette::Mid, brush3);
    palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
    palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush1);
    palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
    palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
    palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
    palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
    palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush1);
    palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush4);
    palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
    palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
    palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
    palette.setBrush(QPalette::Disabled, QPalette::Light, brush1);
    palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush1);
    palette.setBrush(QPalette::Disabled, QPalette::Dark, brush2);
    palette.setBrush(QPalette::Disabled, QPalette::Mid, brush3);
    palette.setBrush(QPalette::Disabled, QPalette::Text, brush2);
    palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush1);
    palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
    palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
    palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
    palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
    palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
    palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush4);
    palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
    GraphicViewUpLeftLabel->setPalette(palette);
    GraphicViewBottomLeftLabel = new QLabel(centralwidget);
    GraphicViewBottomLeftLabel->setObjectName(QString::fromUtf8("GraphicViewBottomLeftLabel"));
    GraphicViewBottomLeftLabel->setGeometry(QRect(320, 340, 101, 19));
    GraphicViewBottomCenterLabel = new QLabel(centralwidget);
    GraphicViewBottomCenterLabel->setObjectName(QString::fromUtf8("GraphicViewBottomCenterLabel"));
    GraphicViewBottomCenterLabel->setGeometry(QRect(650, 340, 91, 19));
    GraphicViewUpRightLabel = new QLabel(centralwidget);
    GraphicViewUpRightLabel->setObjectName(QString::fromUtf8("GraphicViewUpRightLabel"));
    GraphicViewUpRightLabel->setGeometry(QRect(890, 10, 81, 19));
    GraphicViewBottomRightLabel = new QLabel(centralwidget);
    GraphicViewBottomRightLabel->setObjectName(QString::fromUtf8("GraphicViewBottomRightLabel"));
    GraphicViewBottomRightLabel->setGeometry(QRect(940, 340, 101, 19));
    PlotWidgetUpLeft = new QCustomPlot(centralwidget);
    PlotWidgetUpLeft->setObjectName(QString::fromUtf8("PlotWidgetUpLeft"));
    PlotWidgetUpLeft->setGeometry(QRect(229, 10, 451, 321));
    PlotWidgetUpLeft->setBackground(QBrush(QColor("#1a2228")));
//    PlotWidgetUpLeft->paintEngine()QBrush(QColor("#000000")));
    PlotWidgetUpRight = new QCustomPlot(centralwidget);
    PlotWidgetUpRight->setObjectName(QString::fromUtf8("PlotWidgetUpRight"));
    PlotWidgetUpRight->setGeometry(QRect(690, 10, 451, 321));
    PlotWidgetUpRight->setBackground(QBrush(QColor("#1a2228")));
    PlotWidgetBottomLeft = new QCustomPlot(centralwidget);
    PlotWidgetBottomLeft->setObjectName(QString::fromUtf8("PlotWidgetBottomLeft"));
    PlotWidgetBottomLeft->setGeometry(QRect(230, 340, 291, 281));
    PlotWidgetBottomLeft->setBackground(QBrush(QColor("#1a2228")));
    PlotWidgetBottomCenter = new QCustomPlot(centralwidget);
    PlotWidgetBottomCenter->setObjectName(QString::fromUtf8("PlotWidgetBottomCenter"));
    PlotWidgetBottomCenter->setGeometry(QRect(530, 340, 301, 281));
    PlotWidgetBottomCenter->setBackground(QBrush(QColor("#1a2228")));
    PlotWidgetBottomRight = new QCustomPlot(centralwidget);
    PlotWidgetBottomRight->setObjectName(QString::fromUtf8("PlotWidgetBottomRight"));
    PlotWidgetBottomRight->setGeometry(QRect(840, 340, 301, 281));
    PlotWidgetBottomRight->setBackground(QBrush(QColor("#1a2228")));
    MainWindow->setCentralWidget(centralwidget);
    PlotWidgetBottomRight->raise();
    PlotWidgetBottomCenter->raise();
    PlotWidgetBottomLeft->raise();
    PlotWidgetUpRight->raise();
    PlotWidgetUpLeft->raise();
    StartButton->raise();
    StopButton->raise();
    SetPointBox->raise();
    KpBox->raise();
    KiBox->raise();
    KdBox->raise();
    PIDParametersBox->raise();
    GraphicViewUpLeftLabel->raise();
    GraphicViewBottomLeftLabel->raise();
    GraphicViewBottomCenterLabel->raise();
    GraphicViewUpRightLabel->raise();
    GraphicViewBottomRightLabel->raise();

    retranslateUi(MainWindow);

    QMetaObject::connectSlotsByName(MainWindow);

    vals.Kd = _INITIAL_KD_;
    vals.Kp = _INITIAL_KP_;
    vals.Ki = _INITIAL_KI_;
    vals.setpoint = _INITIAL_SETPOINT_;

    KpSpinBox->setSingleStep(_KP_STEP_);
    KdSpinBox->setSingleStep(_KD_STEP_);
    KiSpinBox->setSingleStep(_KI_STEP_);
    SetPointSpinBox->setSingleStep(_SETPOINT_STEP_);


    KdLabel->setText(QApplication::translate("MainWindow",(d_term+boost::lexical_cast<std::string>(vals.Kd)).data(), nullptr));
    KiLabel->setText(QApplication::translate("MainWindow",(i_term+boost::lexical_cast<std::string>(vals.Ki)).data(), nullptr));
    KpLabel->setText(QApplication::translate("MainWindow",(p_term+boost::lexical_cast<std::string>(vals.Kp)).data(), nullptr));

    connect(KpSendButton,&QPushButton::released,this, &Ui_MainWindow::on_send_kp);
    connect(KiSendButton,&QPushButton::released,this, &Ui_MainWindow::on_send_ki);
    connect(KdSendButton,&QPushButton::released,this, &Ui_MainWindow::on_send_kd);
    connect(SetPointSendButton,&QPushButton::released,this, &Ui_MainWindow::on_send_setpoint);
    connect(StartButton,&QPushButton::released,this, &Ui_MainWindow::on_start);
    connect(StopButton,&QPushButton::released,this, &Ui_MainWindow::on_stop);
} // setupUi

void Ui_MainWindow::retranslateUi(QMainWindow *MainWindow)
{
    MainWindow->setWindowTitle(QApplication::translate("MainWindow", "PID Tuner", nullptr));
    StartButton->setText(QApplication::translate("MainWindow", "Start", nullptr));
    StopButton->setText(QApplication::translate("MainWindow", "Stop", nullptr));
    SetPointBox->setTitle(QApplication::translate("MainWindow", "Setpoint Control", nullptr));
    SetPointSendButton->setText(QApplication::translate("MainWindow", "Send", nullptr));
    KpBox->setTitle(QApplication::translate("MainWindow", "Kp Control", nullptr));
    KpSendButton->setText(QApplication::translate("MainWindow", "Send", nullptr));
    KiBox->setTitle(QApplication::translate("MainWindow", "Ki Control", nullptr));
    KiSendButton->setText(QApplication::translate("MainWindow", "Send", nullptr));
    KdBox->setTitle(QApplication::translate("MainWindow", "Kd Control", nullptr));
    KdSendButton->setText(QApplication::translate("MainWindow", "Send", nullptr));
    PIDParametersBox->setTitle(QApplication::translate("MainWindow", "PID Parameters", nullptr));
    KdLabel->setText(QApplication::translate("MainWindow", "D Term: 10", nullptr));
    KiLabel->setText(QApplication::translate("MainWindow", "I Term: 10", nullptr));
    KpLabel->setText(QApplication::translate("MainWindow", "P Term: 10", nullptr));
    GraphicViewUpLeftLabel->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#ffffff;\">Current Plot</span></p></body></html>", nullptr));
    GraphicViewBottomLeftLabel->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#ffffff;\">P Term Plot</span></p></body></html>", nullptr));
    GraphicViewBottomCenterLabel->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#ffffff;\">I Term Plot</span></p></body></html>", nullptr));
    GraphicViewUpRightLabel->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#ffffff;\">Error Plot</span></p></body></html>", nullptr));
    GraphicViewBottomRightLabel->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#ffffff;\">D Term Plot</span></p></body></html>", nullptr));
} // retranslateUi

void Ui_MainWindow::on_send_kd()
{

    vals.Kd = KdSpinBox->value();
    emit send_vals(vals);
    KdLabel->setText(QApplication::translate("MainWindow",(d_term+boost::lexical_cast<std::string>(vals.Kd)).data(), nullptr));
}

void Ui_MainWindow::on_send_ki()
{
    vals.Ki = KiSpinBox->value();
    emit send_vals(vals);
    KiLabel->setText(QApplication::translate("MainWindow",(i_term+boost::lexical_cast<std::string>(vals.Ki)).data(), nullptr));
}

void Ui_MainWindow::on_send_kp()
{

    vals.Kp = KpSpinBox->value();
    emit send_vals(vals);
    KpLabel->setText(QApplication::translate("MainWindow",(p_term+boost::lexical_cast<std::string>(vals.Kp)).data(), nullptr));
}

void Ui_MainWindow::on_send_setpoint()
{
    vals.setpoint = SetPointSpinBox->value();
    emit send_vals(vals);
}


void Ui_MainWindow::on_start()
{
    start = true;
    emit start_sig(start);
}


void Ui_MainWindow::on_stop()
{
    emit stop_sig(true);
}

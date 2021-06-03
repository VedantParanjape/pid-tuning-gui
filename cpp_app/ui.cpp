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
    MainWindow->setAutoFillBackground(false);
    MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
    MainWindow->setUnifiedTitleAndToolBarOnMac(false);
    centralwidget = new QWidget(MainWindow);
    centralwidget->setObjectName(QString::fromUtf8("centralwidget"));

    logo = new QLabel(centralwidget);
    logo->setObjectName(QString::fromUtf8("label"));
    logo->setMaximumSize(QSize(300, 300));
    StartButton = new QPushButton(centralwidget);
    StartButton->setObjectName(QString::fromUtf8("StartButton"));
    StartButton->setGeometry(QRect(10, 10, 100, 31));
    StartButton->setMaximumSize(QSize(150, 150));
    StopButton = new QPushButton(centralwidget);
    StopButton->setObjectName(QString::fromUtf8("StopButton"));
    StopButton->setGeometry(QRect(120, 10, 100, 31));
    StopButton->setMaximumSize(QSize(150, 150));
    SetPointBox = new QGroupBox(centralwidget);
    SetPointBox->setObjectName(QString::fromUtf8("SetPointBox"));
    SetPointBox->setGeometry(QRect(10, 80, 189, 74));
    SetPointBox->setMaximumSize(QSize(300, 300));
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
    KpBox->setMaximumSize(QSize(300, 300));
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
    KiBox->setGeometry(QRect(10, 180, 189, 74));
    KiBox->setMaximumSize(QSize(300, 300));
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
    KdBox->setMaximumSize(QSize(300, 300));
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
    PIDParametersBox->setMaximumSize(QSize(300, 300));
    KdLabel = new QLabel(PIDParametersBox);
    KdLabel->setObjectName(QString::fromUtf8("KdLabel"));
    KdLabel->setGeometry(QRect(10, 90, 171, 21));
    KiLabel = new QLabel(PIDParametersBox);
    KiLabel->setObjectName(QString::fromUtf8("KiLabel"));
    KiLabel->setGeometry(QRect(10, 60, 171, 21));
    KpLabel = new QLabel(PIDParametersBox);
    KpLabel->setObjectName(QString::fromUtf8("KpLabel"));
    KpLabel->setGeometry(QRect(10, 30, 171, 21));

    gridLayout_5 = new QGridLayout(PIDParametersBox);
    gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_6"));

    gridLayout_5->addWidget(KpLabel, 0, 0, 1, 1);

    gridLayout_5->addWidget(KiLabel, 1, 0, 1, 1);

    gridLayout_5->addWidget(KdLabel, 2, 0, 1, 1);

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

    PlotWidgetUpLeft = new QCustomPlot(centralwidget);
    PlotWidgetUpLeft->setObjectName(QString::fromUtf8("PlotWidgetUpLeft"));
    PlotWidgetUpLeft->setGeometry(QRect(229, 10, 451, 321));
    PlotWidgetUpLeft->setBackground(QBrush(QColor("#1a2228")));
    GraphicViewUpLeftLabel = new QLabel(PlotWidgetUpLeft);
    GraphicViewUpLeftLabel->setObjectName(QString::fromUtf8("GraphicViewBottomLeftLabel"));
    GraphicViewUpLeftLabel->setGeometry(QRect(130, 0, 101, 19));
    GraphicViewUpLeftLabel->setStyleSheet(
        QString::fromUtf8("color: rgb(252, 233, 79);background-color: #1a2228;"));

    //    PlotWidgetUpLeft->paintEngine()QBrush(QColor("#000000")));

    PlotWidgetUpRight = new QCustomPlot(centralwidget);
    PlotWidgetUpRight->setObjectName(QString::fromUtf8("PlotWidgetUpRight"));
    PlotWidgetUpRight->setGeometry(QRect(690, 10, 451, 321));
    PlotWidgetUpRight->setBackground(QBrush(QColor("#1a2228")));
    GraphicViewUpRightLabel = new QLabel(PlotWidgetUpRight);
    GraphicViewUpRightLabel->setObjectName(QString::fromUtf8("GraphicViewUpRightLabel"));
    GraphicViewUpRightLabel->setGeometry(QRect(150, 0, 81, 19));
    GraphicViewUpRightLabel->setStyleSheet(
        QString::fromUtf8("color: rgb(252, 233, 79);background-color: #1a2228;"));

    PlotWidgetBottomLeft = new QCustomPlot(centralwidget);
    PlotWidgetBottomLeft->setObjectName(QString::fromUtf8("PlotWidgetBottomLeft"));
    PlotWidgetBottomLeft->setGeometry(QRect(230, 340, 291, 281));
    PlotWidgetBottomLeft->setBackground(QBrush(QColor("#1a2228")));
    GraphicViewBottomLeftLabel = new QLabel(PlotWidgetBottomLeft);
    GraphicViewBottomLeftLabel->setObjectName(QString::fromUtf8("GraphicViewBottomLeftLabel"));
    GraphicViewBottomLeftLabel->setGeometry(QRect(30, 0, 95, 21));
    GraphicViewBottomLeftLabel->setStyleSheet(
        QString::fromUtf8("color: rgb(252, 233, 79);background-color: #1a2228;"));

    PlotWidgetBottomCenter = new QCustomPlot(centralwidget);
    PlotWidgetBottomCenter->setObjectName(QString::fromUtf8("PlotWidgetBottomCenter"));
    PlotWidgetBottomCenter->setGeometry(QRect(530, 340, 301, 281));
    PlotWidgetBottomCenter->setBackground(QBrush(QColor("#1a2228")));
    GraphicViewBottomCenterLabel = new QLabel(PlotWidgetBottomCenter);
    GraphicViewBottomCenterLabel->setObjectName(QString::fromUtf8("GraphicViewBottomCenterLabel"));
    GraphicViewBottomCenterLabel->setGeometry(QRect(150, 0, 91, 19));
    GraphicViewBottomCenterLabel->setStyleSheet(
        QString::fromUtf8("color: rgb(252, 233, 79);background-color: #1a2228;"));

    PlotWidgetBottomRight = new QCustomPlot(centralwidget);
    PlotWidgetBottomRight->setObjectName(QString::fromUtf8("PlotWidgetBottomRight"));
    PlotWidgetBottomRight->setGeometry(QRect(840, 340, 301, 281));
    PlotWidgetBottomRight->setBackground(QBrush(QColor("#1a2228")));
    GraphicViewBottomRightLabel = new QLabel(PlotWidgetBottomRight);
    GraphicViewBottomRightLabel->setObjectName(QString::fromUtf8("GraphicViewBottomRightLabel"));
    GraphicViewBottomRightLabel->setGeometry(QRect(60, 0, 101, 19));
    GraphicViewBottomRightLabel->setStyleSheet(
        QString::fromUtf8("color: rgb(252, 233, 79);background-color: #1a2228;"));

    main_layout = new QGridLayout(centralwidget);
    main_layout->setObjectName(QString::fromUtf8("main_layout"));
    main_layout->addWidget(logo, 0, 0, 1, 2, Qt::AlignHCenter);
    main_layout->addWidget(StartButton, 1, 0, 1, 1);
    main_layout->addWidget(StopButton, 1, 1, 1, 1);
    main_layout->addWidget(PlotWidgetUpLeft, 0, 2, 4, 2);
    main_layout->addWidget(PlotWidgetUpRight, 0, 4, 4, 2);
    main_layout->addWidget(SetPointBox, 2, 0, 1, 2);
    main_layout->addWidget(KpBox, 3, 0, 1, 2);
    main_layout->addWidget(KiBox, 4, 0, 1, 2);
    main_layout->addWidget(PlotWidgetBottomLeft, 4, 2, 3, 1);
    main_layout->addWidget(PlotWidgetBottomCenter, 4, 3, 3, 2);
    main_layout->addWidget(PlotWidgetBottomRight, 4, 5, 3, 1);
    main_layout->addWidget(KdBox, 5, 0, 1, 2);
    main_layout->addWidget(PIDParametersBox, 6, 0, 1, 2);

    MainWindow->setCentralWidget(centralwidget);
    PlotWidgetBottomRight->raise();
    PlotWidgetBottomCenter->raise();
    PlotWidgetBottomLeft->raise();
    PlotWidgetUpRight->raise();
    PlotWidgetUpLeft->raise();
    logo->raise();
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

    KdLabel->setText(
        QApplication::translate("MainWindow",
                                (d_term + boost::lexical_cast<std::string>(vals.Kd)).data(),
                                nullptr));
    KiLabel->setText(
        QApplication::translate("MainWindow",
                                (i_term + boost::lexical_cast<std::string>(vals.Ki)).data(),
                                nullptr));
    KpLabel->setText(
        QApplication::translate("MainWindow",
                                (p_term + boost::lexical_cast<std::string>(vals.Kp)).data(),
                                nullptr));

    connect(KpSendButton, &QPushButton::released, this, &Ui_MainWindow::on_send_kp);
    connect(KiSendButton, &QPushButton::released, this, &Ui_MainWindow::on_send_ki);
    connect(KdSendButton, &QPushButton::released, this, &Ui_MainWindow::on_send_kd);
    connect(SetPointSendButton, &QPushButton::released, this, &Ui_MainWindow::on_send_setpoint);
    connect(StartButton, &QPushButton::released, this, &Ui_MainWindow::on_start);
    connect(StopButton, &QPushButton::released, this, &Ui_MainWindow::on_stop);
} // setupUi

void Ui_MainWindow::retranslateUi(QMainWindow *MainWindow)
{
    MainWindow->setWindowTitle(QApplication::translate("MainWindow", "PID Tuner", nullptr));
    logo->setText(QApplication::translate(
        "MainWindow",
        "<html><head/><body><p><img src=\":/SRA LOGO/sra.png\"/></p></body></html>",
        nullptr));
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
    GraphicViewUpLeftLabel->setText(QApplication::translate(
        "MainWindow",
        "<html><head/><body><p><span style=\" ;\">Current Plot</span></p></body></html>",
        nullptr));
    GraphicViewBottomLeftLabel->setText(QApplication::translate(
        "MainWindow",
        "<html><head/><body><p><span style=\" ;\">P Term Plot</span></p></body></html>",
        nullptr));
    GraphicViewBottomCenterLabel->setText(QApplication::translate(
        "MainWindow",
        "<html><head/><body><p><span style=\" ;\">I Term Plot</span></p></body></html>",
        nullptr));
    GraphicViewUpRightLabel->setText(QApplication::translate(
        "MainWindow",
        "<html><head/><body><p><span style=\" ;\">Error Plot</span></p></body></html>",
        nullptr));
    GraphicViewBottomRightLabel->setText(QApplication::translate(
        "MainWindow",
        "<html><head/><body><p><span style=\";\">D Term Plot</span></p></body></html>",
        nullptr));
} // retranslateUi

void Ui_MainWindow::on_send_kd()
{
    vals.Kd = KdSpinBox->value();
    emit send_vals(vals);
    KdLabel->setText(
        QApplication::translate("MainWindow",
                                (d_term + boost::lexical_cast<std::string>(vals.Kd)).data(),
                                nullptr));
}

void Ui_MainWindow::on_send_ki()
{
    vals.Ki = KiSpinBox->value();
    emit send_vals(vals);
    KiLabel->setText(
        QApplication::translate("MainWindow",
                                (i_term + boost::lexical_cast<std::string>(vals.Ki)).data(),
                                nullptr));
}

void Ui_MainWindow::on_send_kp()
{
    vals.Kp = KpSpinBox->value();
    emit send_vals(vals);
    KpLabel->setText(
        QApplication::translate("MainWindow",
                                (p_term + boost::lexical_cast<std::string>(vals.Kp)).data(),
                                nullptr));
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

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

RESOURCES = pid_plotter_res.qrc

LIBS += \
    -lboost_thread

SOURCES += \
    data_handler.cpp \
    graph_renderer.cpp \
    main.cpp \
    qcustomplot.cpp \
    ui.cpp

HEADERS += \
    data_handler.h \
    graph_renderer.h \
    pid_message_config.h \
    qcustomplot.h \
    ui.h

FORMS +=

TRANSLATIONS += \
    pid_tuning_gui_qt_en_IN.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

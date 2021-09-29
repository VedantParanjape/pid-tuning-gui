#include "graph_renderer.h"
#include "pid_message_config.h"
#include "ui.h"
#include <iostream>
#include <QApplication>
#include <QProgressBar>
#include <QSharedPointer>
#include <QSlider>
#include <QtWidgets/QMainWindow>

QByteArray readTextFile(const QString &file_path)
{
    QFile input_file(file_path);
    QByteArray input_data;

    if (input_file.open(QIODevice::Text | QIODevice::Unbuffered | QIODevice::ReadOnly)) {
        input_data = input_file.readAll();
        input_file.close();
        return input_data;
    } else {
        return QByteArray();
    }
}

int main(int argc, char *argv[])
{
    qRegisterMetaType<pid_terms_incomming_values>("pid_terms_incomming_values");
    qRegisterMetaType<pid_term_send_values>("pid_term_send_values");
    QString style_sheet = readTextFile(":/stylesheets/material-blue.qss");
    QApplication a(argc, argv);
    a.setStyleSheet(style_sheet);
    QMainWindow *m = new QMainWindow();
    Ui_MainWindow *w = new Ui_MainWindow(m);
    datahandler *d_ptr = new datahandler(w);
    QThread *th = new QThread();
    d_ptr->moveToThread(th);
    th->start();
    graph_renderer g(w, d_ptr);
    std::cout << "Main Application thread " << QThread::currentThread() << std::endl;
    m->show();
    auto a_ret = a.exec();
    return a_ret;
}

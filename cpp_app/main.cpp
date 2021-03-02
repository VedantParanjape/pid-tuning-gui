#include "window.h"
#include <QApplication>
#include <QProgressBar>
#include <QSlider>
#include <QtWidgets/QMainWindow>
#include "ui.h"
#include "graph_renderer.h"
#include <iostream>
#include <QSharedPointer>
#include "pid_message_config.h"

int main(int argc, char *argv[])
{
    qRegisterMetaType<pid_terms_incomming_values>("pid_terms_incomming_values");
    qRegisterMetaType<pid_term_send_values>("pid_term_send_values");
    QApplication a(argc, argv);
    QMainWindow *m = new QMainWindow();
    Ui_MainWindow *w= new Ui_MainWindow(m);
    datahandler *d_ptr = new datahandler(w);
    QThread *th = new QThread();
    d_ptr->moveToThread(th);
    th->start();
    graph_renderer g(w,d_ptr);
    std::cout<<"Main Application thread "<<QThread::currentThread()<<std::endl;
    m->show();
    auto a_ret = a.exec();
    return a_ret;
}

#ifndef GRAPH_RENDERER_H
#define GRAPH_RENDERER_H

#include "data_handler.h"
#include "pid_message_config.h"
#include "ui.h"
#include <QApplication>
#include <QMainWindow>
#include <QObject>

#define _MAX_PTS_KI_ 500
#define _MAX_PTS_KP_ 500
#define _MAX_PTS_KD_ 500
#define _MAX_PTS_ERROR_ 500
#define _MAX_PTS_CURR_ 500
#define _MAX_PTS_TIME_ 500
#define _MAX_KI_ 2
#define _MAX_KP_ 2
#define _MAX_KD_ 2
#define _MAX_ERROR_ 1
#define _MAX_CURR_ 314
#define _MIN_KI_ -2
#define _MIN_KP_ -2
#define _MIN_KD_ -2
#define _MIN_ERROR_ -1
#define _MIN_CURR_ -200

class graph_renderer : public QObject
{
    Q_OBJECT
public:
    graph_renderer(Ui_MainWindow *cpy_w, datahandler *d);
    void update_graph();
    void handle_graph();
    void update_vec();
    Ui_MainWindow *w;
public slots:
    void on_data_changed(pid_terms_incomming_values vals);

private:
    pid_terms_incomming_values vals;
};

#endif // GRAPH_RENDERER_H

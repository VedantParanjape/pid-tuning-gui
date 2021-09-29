#include "graph_renderer.h"

static QTime t(QTime::currentTime());

static int curr_idx = 0;
static double tme = 0.0;

QVector<double> kp_vec;
QVector<double> ki_vec;
QVector<double> kd_vec;
QVector<double> curr_vec;
QVector<double> error_vec;
QVector<double> time_vec;

graph_renderer::graph_renderer(Ui_MainWindow *cpy_w, datahandler *d)
{
    w = cpy_w;
    w->PlotWidgetBottomCenter->addGraph();
    w->PlotWidgetBottomLeft->addGraph();
    w->PlotWidgetBottomRight->addGraph();
    w->PlotWidgetUpLeft->addGraph();
    w->PlotWidgetUpRight->addGraph();
    QPen pen;
    pen.setWidth(1);
    pen.setColor(QColor(0, 255, 255));
    w->PlotWidgetBottomCenter->graph(0)->setPen(pen);
    w->PlotWidgetBottomLeft->graph(0)->setPen(pen);
    w->PlotWidgetBottomRight->graph(0)->setPen(pen);
    w->PlotWidgetUpLeft->graph(0)->setPen(pen);
    w->PlotWidgetUpRight->graph(0)->setPen(pen);

    w->PlotWidgetBottomCenter->xAxis->setBasePen(pen);
    w->PlotWidgetBottomLeft->xAxis->setBasePen(pen);
    w->PlotWidgetBottomRight->xAxis->setBasePen(pen);
    w->PlotWidgetUpLeft->xAxis->setBasePen(pen);
    w->PlotWidgetUpRight->xAxis->setBasePen(pen);

    w->PlotWidgetBottomCenter->xAxis->setTickLabelColor(QColor(0, 255, 255));
    w->PlotWidgetBottomLeft->xAxis->setTickLabelColor(QColor(0, 255, 255));
    w->PlotWidgetBottomRight->xAxis->setTickLabelColor(QColor(0, 255, 255));
    w->PlotWidgetUpLeft->xAxis->setTickLabelColor(QColor(0, 255, 255));
    w->PlotWidgetUpRight->xAxis->setTickLabelColor(QColor(0, 255, 255));

    w->PlotWidgetBottomCenter->yAxis->setTickLabelColor(QColor(0, 255, 255));
    w->PlotWidgetBottomLeft->yAxis->setTickLabelColor(QColor(0, 255, 255));
    w->PlotWidgetBottomRight->yAxis->setTickLabelColor(QColor(0, 255, 255));
    w->PlotWidgetUpLeft->yAxis->setTickLabelColor(QColor(0, 255, 255));
    w->PlotWidgetUpRight->yAxis->setTickLabelColor(QColor(0, 255, 255));

    w->PlotWidgetBottomLeft->xAxis->setBasePen(QColor(0, 255, 255));
    w->PlotWidgetBottomRight->xAxis->setBasePen(QColor(0, 255, 255));
    w->PlotWidgetUpLeft->xAxis->setBasePen(QColor(0, 255, 255));
    w->PlotWidgetUpRight->xAxis->setBasePen(QColor(0, 255, 255));

    w->PlotWidgetBottomCenter->yAxis->setBasePen(pen);
    w->PlotWidgetBottomLeft->yAxis->setBasePen(pen);
    w->PlotWidgetBottomRight->yAxis->setBasePen(pen);
    w->PlotWidgetUpLeft->yAxis->setBasePen(pen);
    w->PlotWidgetUpRight->yAxis->setBasePen(pen);

    w->PlotWidgetBottomCenter->yAxis->setLabelColor(QColor(0, 255, 255));
    w->PlotWidgetBottomLeft->yAxis->setBasePen(QColor(0, 255, 255));
    w->PlotWidgetBottomRight->yAxis->setBasePen(QColor(0, 255, 255));
    w->PlotWidgetUpLeft->yAxis->setBasePen(QColor(0, 255, 255));
    w->PlotWidgetUpRight->yAxis->setBasePen(QColor(0, 255, 255));

    w->PlotWidgetBottomCenter->xAxis->setRangeUpper(_MAX_PTS_KI_);
    w->PlotWidgetBottomLeft->xAxis->setRangeUpper(_MAX_PTS_KP_);
    w->PlotWidgetBottomRight->xAxis->setRangeUpper(_MAX_PTS_KD_);
    w->PlotWidgetUpRight->xAxis->setRangeUpper(_MAX_PTS_ERROR_);
    w->PlotWidgetUpLeft->xAxis->setRangeUpper(_MAX_PTS_CURR_);
    w->PlotWidgetBottomCenter->yAxis->setRange(_MIN_KI_, _MAX_KI_);
    w->PlotWidgetBottomLeft->yAxis->setRange(_MIN_KP_, _MAX_KP_);
    w->PlotWidgetBottomRight->yAxis->setRange(_MIN_KD_, _MAX_KD_);
    w->PlotWidgetUpRight->yAxis->setRange(_MIN_ERROR_, _MAX_ERROR_);
    w->PlotWidgetUpLeft->yAxis->setRange(_MIN_CURR_, _MAX_CURR_);

    connect(d,
            SIGNAL(data_received(pid_terms_incomming_values)),
            this,
            SLOT(on_data_changed(pid_terms_incomming_values)),
            Qt::QueuedConnection);
}

void graph_renderer::on_data_changed(pid_terms_incomming_values val)
{
    tme = t.elapsed() / 1000.00;
    vals.Kd = val.Kd;
    vals.Ki = val.Ki;
    vals.Kp = val.Kp;
    vals.current = val.current;
    vals.error = val.error;
    curr_idx++;
    update_vec();
    kp_vec.push_back(vals.Kp);
    kd_vec.push_back(vals.Kd);
    ki_vec.push_back(vals.Ki);
    error_vec.push_back(vals.error);
    curr_vec.push_back(vals.current);
    time_vec.push_back(tme);
    handle_graph();
}

void graph_renderer::handle_graph()
{
    // KI
    auto plot_bc = w->PlotWidgetBottomCenter->graph(0);
    if (plot_bc->dataCount() > _MAX_PTS_KI_) {
        plot_bc->data().data()->clear();
        w->PlotWidgetBottomCenter->replot();
    }
    for (int i = 0; i < ki_vec.size(); i++) {
        plot_bc->addData(time_vec[i], ki_vec[i]);
    }
    plot_bc->rescaleAxes();
    w->PlotWidgetBottomCenter->replot();

    // KP
    auto plot_bl = w->PlotWidgetBottomLeft->graph(0);
    if (plot_bl->dataCount() > _MAX_PTS_KP_) {
        plot_bl->data().data()->clear();
        w->PlotWidgetBottomLeft->replot();
    }
    for (int i = 0; i < kp_vec.size(); i++) {
        plot_bl->addData(time_vec[i], kp_vec[i]);
    }
    plot_bl->rescaleAxes();
    w->PlotWidgetBottomLeft->replot();

    // KD
    auto plot_br = w->PlotWidgetBottomRight->graph(0);
    if (plot_br->dataCount() > _MAX_PTS_KD_) {
        plot_br->data().data()->clear();
        w->PlotWidgetBottomRight->replot();
    }
    for (int i = 0; i < kd_vec.size(); i++) {
        plot_br->addData(time_vec[i], kd_vec[i]);
    }
    plot_br->rescaleAxes();
    w->PlotWidgetBottomRight->replot();

    // CURR
    auto plot_ul = w->PlotWidgetUpLeft->graph(0);
    if (plot_ul->dataCount() > _MAX_PTS_CURR_) {
        plot_ul->data().data()->clear();
        w->PlotWidgetUpLeft->replot();
    }
    for (int i = 0; i < curr_vec.size(); i++) {
        plot_ul->addData(time_vec[i], curr_vec[i]);
    }
    plot_ul->rescaleAxes();
    w->PlotWidgetUpLeft->replot();

    // ERROR
    auto plot_ur = w->PlotWidgetUpRight->graph(0);
    if (plot_ur->dataCount() > _MAX_PTS_ERROR_) {
        plot_ur->data().data()->clear();
        w->PlotWidgetUpRight->replot();
    }
    for (int i = 0; i < error_vec.size(); i++) {
        plot_ur->addData(time_vec[i], error_vec[i]);
    }
    plot_ur->rescaleAxes();
    w->PlotWidgetUpRight->replot();
}

void graph_renderer::update_vec()
{
    /*
     * To be called before pushing back into vectors
    */

    if (kp_vec.size() > _MAX_PTS_KP_) {
        for (int i = 1; i < _MAX_PTS_KP_ + 1; i++) {
            kp_vec[i - 1] = kp_vec[i];
        }
        kp_vec.pop_back();
    }
    if (ki_vec.size() > _MAX_PTS_KI_) {
        for (int i = 1; i < _MAX_PTS_KI_ + 1; i++) {
            ki_vec[i - 1] = ki_vec[i];
        }
        ki_vec.pop_back();
    }
    if (kd_vec.size() > _MAX_PTS_KD_) {
        for (int i = 1; i < _MAX_PTS_KD_ + 1; i++) {
            kd_vec[i - 1] = kd_vec[i];
        }
        kd_vec.pop_back();
    }
    if (error_vec.size() > _MAX_PTS_ERROR_) {
        for (int i = 1; i < _MAX_PTS_ERROR_ + 1; i++) {
            error_vec[i - 1] = error_vec[i];
        }
        error_vec.pop_back();
    }
    if (curr_vec.size() > _MAX_PTS_CURR_) {
        for (int i = 1; i < _MAX_PTS_CURR_ + 1; i++) {
            curr_vec[i - 1] = curr_vec[i];
        }
        curr_vec.pop_back();
    }
    // Reset time vector
    if (time_vec.size() > _MAX_PTS_TIME_) {
        for (int i = 1; i < _MAX_PTS_TIME_ + 1; i++) {
            time_vec[i - 1] = time_vec[i];
        }
        time_vec.pop_back();
    }
}

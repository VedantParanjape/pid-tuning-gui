#ifndef DATA_HANDLER_H
#define DATA_HANDLER_H

#include <QObject>
#include <QThread>
#include <iostream>
#include <boost/asio.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/property_tree/ini_parser.hpp>
#include <boost/thread.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/bind/bind.hpp>
#include "pid_message_config.h"
#include "ui.h"

#ifndef _MAX_BUF_SIZE_
#define _MAX_BUF_SIZE_ 512
#endif

class datahandler : public QObject, public boost::enable_shared_from_this<datahandler>
{
    Q_OBJECT
public:
    explicit datahandler(Ui_MainWindow *cpy_w);
    ~datahandler();
    void init_server();
    void receive_data();
    void handle_received_data();
    void run_once();
    void spin();
    bool is_start();
    bool is_close();
signals:
     void data_received(pid_terms_incomming_values vals);
public slots:
     void send_data(pid_term_send_values send_vals);
     void close_slt(bool _close);
     void start_slt(bool _start);
private:
    char _incomming_data[_MAX_BUF_SIZE_];
    unsigned int _num_bytes_read;
    bool start;
    bool close;
    boost::property_tree::ptree json_tree;
    boost::property_tree::ptree out_json_tree;
    boost::asio::ip::tcp::socket *tcp_socket;
    boost::asio::ip::udp::socket *udp_socket;
    pid_terms_incomming_values vals;
    boost::asio::ip::tcp::acceptor *a;
};

#endif // DATA_HANDLER_H

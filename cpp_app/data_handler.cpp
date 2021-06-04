#include "data_handler.h"

boost::asio::io_service io_service;

datahandler::datahandler(Ui_MainWindow *cpy_w)
{
    std::cout << "Started data_handler " << QThread::currentThread() << std::endl;
    th = nullptr;
    a = nullptr;
    tcp_socket = nullptr;
    udp_socket = nullptr;
    close = false;
    start = false;
    connect(cpy_w,
            SIGNAL(send_vals(pid_term_send_values)),
            this,
            SLOT(send_data(pid_term_send_values)),
            Qt::QueuedConnection);
    connect(cpy_w, SIGNAL(start_sig(bool)), this, SLOT(start_slt(bool)), Qt::QueuedConnection);
    connect(cpy_w, SIGNAL(stop_sig(bool)), this, SLOT(close_slt(bool)), Qt::QueuedConnection);
}

void datahandler::init_server()
{
    std::cout << "\n========Initiating server============" << std::endl;
    std::cout << "Server thread " << QThread::currentThread() << std::endl;
    boost::asio::ip::udp::endpoint local_endpoint
        = boost::asio::ip::udp::endpoint(boost::asio::ip::udp::v4(), 1212);
    std::cout << "Local bind " << local_endpoint << std::endl;
    udp_socket->open(boost::asio::ip::udp::v4());
    udp_socket->bind(local_endpoint);
}

void datahandler::receive_data()
{
    _num_bytes_read = udp_socket->receive(boost::asio::buffer(_incomming_data));
}

void datahandler::handle_received_data()
{
    if (_num_bytes_read > 100) {
        std::string s(_incomming_data, _num_bytes_read);
        std::stringstream ss(s);
        boost::property_tree::read_json(ss, json_tree);
        //        std::cout<<json_tree.get<std::string>("current")<<std::endl;
        vals.Kd = json_tree.get<std::double_t>("D");
        vals.Kp = json_tree.get<std::double_t>("P");
        vals.Ki = json_tree.get<std::double_t>("I");
        vals.current = json_tree.get<std::double_t>("current");
        vals.error = json_tree.get<std::double_t>("error");
        emit data_received(vals);
        _num_bytes_read = 0;
    }
}

void datahandler::send_data(pid_term_send_values send_vals)
{
    //
    std::ostringstream oss;
    out_json_tree.clear();
    out_json_tree.put("Kp", send_vals.Kp);
    out_json_tree.put("Ki", send_vals.Ki);
    out_json_tree.put("Kd", send_vals.Kd);
    out_json_tree.put("SetPoint", send_vals.setpoint);
    boost::property_tree::json_parser::write_json(oss, out_json_tree);
    //    std::cout<<"Sending : "<<oss.str()<<std::endl;
    tcp_socket->write_some(boost::asio::buffer(oss.str()));
}

void datahandler::run_once()
{
    receive_data();
    handle_received_data();
}

void datahandler::spin()
{
    while (!close) {
        run_once();
    }
}

void datahandler::start_slt(bool _start)
{
    start = _start;
    close = false;
    if (start) {
        std::cout << "Start button ack" << std::endl;
        if(tcp_socket==nullptr)
            tcp_socket = new boost::asio::ip::tcp::socket(io_service);
        if(udp_socket==nullptr)
            udp_socket = new boost::asio::ip::udp::socket(io_service);
        if(a==nullptr){
            a = new boost::asio::ip::tcp::acceptor(
                        io_service, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), 2121));
            a->accept(*tcp_socket);
            init_server();
            if(th==nullptr)
                th = new boost::thread([&] { spin(); });
        }
    }
}

void datahandler::close_slt(bool _close)
{
    std::cout << "Close Pressed" << std::endl;
    close = _close;
    start = false;
    if (close) {

        if(a!=nullptr){
            a->close();
            delete a;
            a = nullptr;
        }

        if(tcp_socket!=nullptr){
            tcp_socket->shutdown(tcp_socket->shutdown_both);
            tcp_socket->close();
            delete tcp_socket;
            tcp_socket = nullptr;
        }

        if(udp_socket!=nullptr){
            udp_socket->close();
            delete udp_socket;
            udp_socket = nullptr;
        }

        if(th!=nullptr){
            th->interrupt();
            delete th;
            th = nullptr;
        }
    }
}

bool datahandler::is_start()
{
    return start;
}

bool datahandler::is_close()
{
    return close;
}

datahandler::~datahandler() {}

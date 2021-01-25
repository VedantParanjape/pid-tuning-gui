#pragma once

#include <boost/asio.hpp>
#include <boost/thread.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <iostream>

#define _MAX_BUF_SIZE_ 512

namespace libserver 
{   
    class server :public boost::enable_shared_from_this<libserver::server>
    {
        private:
            boost::asio::ip::tcp::socket tcp_socket;
            boost::asio::ip::udp::socket udp_socket;
            char _incomming_data[_MAX_BUF_SIZE_];
            unsigned int _num_bytes_read; 
            boost::property_tree::ptree json_tree;
        public:
        /**/
            void handler();
            void read();
            // void send(std::string data);
            // void shutdown();    
            // boost::asio::ip::tcp::socket& get_sock();
            server();
            // size_t port;
    };

    class pid_const_data:public boost::enable_shared_from_this<server>
    {
        public:
            double ki;
            double kp;
            double kd;
            double set_point;
            pid_const_data();
            void parse();
    };
    void acceptor();
    void main_handler();
}

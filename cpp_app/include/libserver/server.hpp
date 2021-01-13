#pragma once

#include <boost/asio.hpp>
#include <boost/thread.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <iostream>

namespace libserver 
{   
    class server :public boost::enable_shared_from_this<server>
    {
        private:
        /**/
            boost::asio::ip::tcp::socket tcp_socket;
            boost::asio::ip::udp::socket udp_socket;
            void _read_from_socket();
            std::string _incomming_data;
        public:
        /**/
            server();
            void display();
            boost::asio::ip::tcp::socket& _get_tcp_socket();
            boost::asio::ip::udp::socket& _get_udp_socket();
            void tcp_read();
    };
    void handler();
}

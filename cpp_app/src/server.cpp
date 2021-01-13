#include "libserver/server.hpp"

typedef boost::shared_ptr<libserver::server> server_ptr;

/**/
boost::asio::io_service io_service;


/**/

libserver::server::server():tcp_socket(io_service),udp_socket(io_service)
{
    /**/
}

void libserver::server::display()
{
    std::cout<<_incomming_data<<std::endl;
}

boost::asio::ip::tcp::socket& libserver::server::_get_tcp_socket()
{
    return tcp_socket;
}

boost::asio::ip::udp::socket& libserver::server::_get_udp_socket()
{
    return udp_socket;
}

void libserver::server::tcp_read()
{
    tcp_socket.read_some(boost::asio::buffer(_incomming_data));
}

void libserver::handler()
{
    boost::asio::ip::tcp::acceptor a(io_service,boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(),1212));
    server_ptr ptr(new libserver::server);
    while (true)
    {
        a.accept(ptr->_get_tcp_socket());
        ptr->tcp_read();
        ptr->display();
        ptr.reset();
    }
}
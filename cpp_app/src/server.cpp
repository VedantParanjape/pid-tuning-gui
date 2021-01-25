#include "libserver/server.hpp"

boost::asio::io_context io_service;

libserver::server::server():tcp_socket(io_service),udp_socket(io_service)
{
    boost::asio::ip::tcp::acceptor a(io_service,boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(),2121));
    a.accept(tcp_socket);
    boost::asio::ip::udp::endpoint local_endpoint = boost::asio::ip::udp::endpoint(boost::asio::ip::udp::v4(),1212);
    std::cout << "Local bind " << local_endpoint << std::endl;
    udp_socket.open(boost::asio::ip::udp::v4());
    udp_socket.bind(local_endpoint);
}

void libserver::server::read()
{
    _num_bytes_read = udp_socket.receive(boost::asio::buffer(_incomming_data));
    // std::cout<<_incomming_data<<" Read "<<_num_bytes_read<<std::endl;
}

void libserver::server::handler()
{
    if(_num_bytes_read>100)
    {
        std::string s(_incomming_data,_num_bytes_read);
        std::stringstream ss(s);
        boost::property_tree::read_json(ss,json_tree);
        std::cout<<json_tree.get<std::string>("current")<<std::endl;
    }
}

void libserver::acceptor()
{
    libserver::server s;
    while (true)
    {
        s.read();
        s.handler();
    }
    
}

void libserver::main_handler()
{
    while (true)
    {
        // std::cout<<"..."<<std::endl;
        boost::this_thread::sleep( boost::posix_time::millisec(1000));
    }
    
}
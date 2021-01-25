#include "libserver/server.hpp"

int main() 
{
    boost::thread_group g;
    g.create_thread(libserver::acceptor);
    g.create_thread(libserver::main_handler);
    g.join_all();
    return 0;
}

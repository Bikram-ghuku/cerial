// #include<capnp/message.h>
// #include<capnp/serialize-packed.h>
// #include<capnp/serialize.h>
#include<iostream>
#include<zmqpp/zmqpp.hpp>


void send_msg()
{
    zmqpp::context context;

    zmqpp::socket server(context, zmqpp::socket_type::push);
    try
    {
        zmqpp::zmq_internal_exception error;
        server.bind("tcp://127.0.0.1:5556");
        throw error;
        std::cout<<"binded to tcp addr"<<std::endl;
    }
    catch(zmqpp::zmq_internal_exception error)
    {
        server.connect("tcp://127.0.0.1:5556");
        std::cout<<error.what()<<", therefore connected to server"<<std::endl;
    }
}

int main()
{
    send_msg();
}
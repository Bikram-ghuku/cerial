#include<iostream>
#include<zmqpp/zmqpp.hpp>
#include<kj/arena.h>
#include<capnp/message.h>

void send_msg(kj::ArrayPtr<capnp::word> msg)
{
    zmqpp::context context; 
    zmqpp::socket server(context, zmqpp::socket_type::push);

    zmqpp::zmq_internal_exception error;
    server.bind("tcp://127.0.0.1:5556");
    throw error;
    std::cout<<"binded to tcp addr"<<std::endl;

    zmq_msg_t message;
    zmq_msg_init_data(&message, msg.begin(), msg.size()*sizeof(capnp::word), NULL, NULL);
    int num_val = zmq_msg_send(&message, server, 0);
    if(num_val == -1)
    {
        std::cout<<"error sending"<<std::endl;
    }
    
}

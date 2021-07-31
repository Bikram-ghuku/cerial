#include<iostream>
#include<zmqpp/zmqpp.hpp>
#include<kj/arena.h>
#include<capnp/message.h>
#include<capnp/serialize-packed.h>
#include<schemas/message.capnp.h>

std::string read_msg()
{
    zmqpp::context context; 
    zmqpp::socket client(context, zmqpp::socket_type::push);

    client.connect("tcp://127.0.0.1:5556");
    std::cout<<"binded to tcp addr"<<std::endl;

    zmq_msg_t message;
    zmq_msg_recv(&message, client, 0);

    auto num_words = zmq_msg_size(&message) / sizeof(capnp::word);
    auto word_arr = kj::ArrayPtr<capnp::word const>(reinterpret_cast<capnp::word const *>(zmq_msg_data(&message)), num_words);
    ::capnp::FlatArrayMessageReader msgReader = ::capnp::FlatArrayMessageReader(word_arr);

    auto keyvaluepair = msgReader.getRoot<KeyValuePair>();

    std::string z = keyvaluepair.toString().flatten().cStr();

    return z;
}


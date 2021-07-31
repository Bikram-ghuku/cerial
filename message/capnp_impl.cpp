#include<capnp/serialize.h>
#include<capnp/message.h>
#include<schemas/message.capnp.h>
#include"send_zmq_msg.h"

void write(std::string superkey)
{
    ::capnp::MallocMessageBuilder msg;
    MsgPacket::Builder msgpack = msg.initRoot<MsgPacket>();
    ::capnp::List<KeyValuePair>::Builder keyvaluepair =msgpack.initJson(2);

    KeyValuePair::Builder num_one = keyvaluepair[0];
    num_one.setSuperKey(superkey);
    num_one.setKey("OP");
    num_one.setValue("Noob");

    auto msg_array = capnp::messageToFlatArray(msg);
    send_msg(msg_array);
}

void read(std::string superkery)
{
    ::capnp::MallocMessageBuilder msg;
    
}

int main()
{
    write("SensorEvent");
}
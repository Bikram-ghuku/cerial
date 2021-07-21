#include<capnp/serialize.h>
#include<capnp/message.h>
#include<schemas/message.capnp.h>
#include"zmq_msg.h"

void write()
{
    ::capnp::MallocMessageBuilder msg;
    MsgPacket::Builder msgpack = msg.initRoot<MsgPacket>();
    ::capnp::List<KeyValuePair>::Builder keyvaluepair =msgpack.initJson(2);

    KeyValuePair::Builder num_one = keyvaluepair[0];
    num_one.setSuperKey("SensorEvent");
    num_one.setKey("OP");
    num_one.setValue("Noob");

    auto msg_array = capnp::messageToFlatArray(msg);
    send_msg(msg_array);
    
    
}

int main()
{
    write();
}
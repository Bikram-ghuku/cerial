using Cxx = import "./include/c++.capnp";
$Cxx.namespace("messaging");

@0xdc1423e87dd45e6d;

struct KeyValuePair
{
    key @0 :Text;
    value @1 :Text; 
}

struct MsgPacket
{
    json @0: List(KeyValuePair);
}
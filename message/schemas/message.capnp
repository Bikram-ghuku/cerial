@0xdc1423e87dd45e6d;

struct KeyValuePair
{
    superKey @0 :Text;
    key @1 :Text;
    value @2 :Text; 
}

struct MsgPacket
{
    json @0: List(KeyValuePair);
}
#include<message/zmq_clang_subs.h>

int main()
{
    subs_py subscriber("logs_test_py_to_py");
    Json::Value json_got = subscriber.get_json();
    Json::StreamWriterBuilder builder;
    std::string str_got = Json::writeString(builder, json_got);

    std::cout<<"GOT: "<<std::endl;
    std::cout<<str_got<<std::endl;
    return 0;
}
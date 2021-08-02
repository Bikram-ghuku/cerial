#include<jsoncpp/json/value.h>
#include<jsoncpp/json/json.h>
#include<jsoncpp/json/reader.h>
#include<jsoncpp/json/writer.h>
#include<iostream>
#include<zmqpp/zmqpp.hpp>

int main()
{
    zmqpp::context context;

    zmqpp::socket server(context, zmqpp::socket_type::push);
    server.connect("tcp://127.0.0.1:5555");
    Json::Value out;
    Json::StreamWriterBuilder builder;

    out["OP"] = "noob";
    out["lol"] = "noob";

    std::string string= Json::writeString(builder, out);

    zmqpp::message_t message(string.c_str(),string.size());

    server.send(message);
    std::cout<<out<<std::endl;
}
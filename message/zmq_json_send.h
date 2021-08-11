#include<jsoncpp/json/value.h>
#include<jsoncpp/json/json.h>
#include<jsoncpp/json/reader.h>
#include<jsoncpp/json/writer.h>
#include<iostream>
#include<zmqpp/zmqpp.hpp>
class publish
{
private:
    zmqpp::context context;
    int size;
    Json::StreamWriterBuilder builder;
    std::string request;
    void send_msg_actually(std::string snd)
    {
        zmqpp::socket server(this->context, zmqpp::socket_type::pub);
        server.bind("tcp://127.0.0.1:5555");
        server.send(snd);
    }

public:
    void new_message( std::string request, int size=1)
    {
        this->size = size;
        this->request = request;
    }

    void send_json(Json::Value msg)
    {
        auto request = this->request;
        Json::Value send_msg;
        send_msg[request] = msg;
        std::string send_msg_str = Json::writeString(this->builder, send_msg);
        this->send_msg_actually(send_msg_str);  
    }

    void send(std::list<std::string> label, std::list<std::string> data)
    {
        std::list<std::string>::iterator iter_label = label.begin();
        std::list<std::string>::iterator iter_data = data.begin();
        Json::Value send_msg_create;
        for(int x=0; x<=this->size || iter_data!=data.end() || iter_label!=label.end(); x++)
        {
            send_msg_create[*iter_label] = *iter_data;
            iter_data++;
            iter_label++;
        }
        auto request = this->request;
        Json::Value send_msg;
        send_msg[request] = send_msg_create;
        std::string send_msg_str = Json::writeString(this->builder, send_msg);
        this->send_msg_actually(send_msg_str);
    }
};
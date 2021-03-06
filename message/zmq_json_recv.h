#include<jsoncpp/json/value.h>
#include<jsoncpp/json/json.h>
#include<jsoncpp/json/reader.h>
#include<jsoncpp/json/writer.h>
#include<iostream>
#include<zmqpp/zmqpp.hpp>

class subscribe
{
private:
    zmqpp::context context;
    Json::StreamWriterBuilder builder;
    std::string request;
    std::string requests;
    zmqpp::message recv_msg_actually()
    {
        zmqpp::message message;
        zmqpp::socket client(this->context, zmqpp::socket_type::sub);
        client.connect("tcp://127.0.0.1:5555");
        client.subscribe("");
        client.receive(message);
        return message;
    }

public:
    std::string request;
    subscribe(std::string request) : request(request)
    {
    }

    Json::Value get_json()
    {
        
        auto msgsgs = this->recv_msg_actually();
        auto requests = this->requests;
        msgsgs>>requests;
        Json::Value rootl;
        Json::Reader read;
        Json::Value read_data;
        bool succesful = read.parse(requests, rootl);
        if(!succesful)
        {
            std::cout<<"error reading json from string"<<std::endl;
        }
        else
        {
            read_data = rootl[this->request];
        }

        return read_data;
    }
    
};
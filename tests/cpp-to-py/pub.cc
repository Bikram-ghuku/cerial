#include<message/zmq_clang_pub.h>
#include<unistd.h>
int main()
{
    while(true)
    {
        publish_to_py publisher;
        Json::Value rootl;
        rootl["temp"] = "67°F";
        publisher.new_message("Logs_cxx_to_py");
        publisher.send_json(rootl);
        std::cout<<"Sent message"<<std::endl;
        sleep(1);
    }
    return 0;
}



#include "component/basic.h"

bool BasicComponent::Init()
{
    writer_ = node_->CreateWriter<std_msgs::msg::String>("writer");
    
    ReaderConfig chassis_reader_config;
    chassis_reader_config.channel_name = "reader_with_config";
    chassis_reader_config.pending_queue_size = 2;

    reader_with_config = node_->CreateReader<std_msgs::msg::String>(chassis_reader_config, std::bind(&BasicComponent::callback, this, std::placeholders::_1));
    reader_ = node_->CreateReader<std_msgs::msg::String>("reader", nullptr);
  
    return true;
}
int i = 0;
bool BasicComponent::Proc()
{
    i++;
    std::string data = "";
    auto latest = reader_->GetLatestObserved();
    if (latest != nullptr)
        data = latest->data;
    AINFO << "Timer last received = " << data;
    AINFO << "Publishing echo >> " << data;
    if (latest != nullptr)
        writer_->Write(latest);
   
    return true;
};
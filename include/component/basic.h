#include "cyber/cyber.h"
#include "std_msgs/msg/string.hpp"

using apollo::cyber::Reader;
using apollo::cyber::ReaderConfig;
using apollo::cyber::ReaderJson;
using apollo::cyber::Writer;
using apollo::cyber::WriterJson;

class BasicComponent : public apollo::cyber::TimerComponent
{
public:
    BasicComponent() : TimerComponent("BasicComponent") {}
    bool Init() override;

    bool Proc() override;

    void callback(const std_msgs::msg::String::SharedPtr msg)
    {
        AINFO << "Callback received = " << msg->data;
    }
    long IntervalMilliseconds() { return 500; }

    std::shared_ptr<Writer<std_msgs::msg::String>> writer_ = nullptr;
    std::shared_ptr<Reader<std_msgs::msg::String>> reader_ = nullptr;
    std::shared_ptr<Reader<std_msgs::msg::String>> reader_with_config = nullptr;
};
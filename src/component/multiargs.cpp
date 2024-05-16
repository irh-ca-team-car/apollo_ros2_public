#include "component/multiargs.h"

typedef apollo::cyber::adapter::Sync<std_msgs::msg::String, std_msgs::msg::String> __sync__;

bool MultiArgsComponent::Init()
{
    sync_.proc = std::bind(&MultiArgsComponent::Proc, this, std::placeholders::_1, std::placeholders::_2);
    rd0 = CreateReader<std_msgs::msg::String>("s0",
                                              std::bind(&__sync__::callback0, &sync_, std::placeholders::_1));
    rd1 = CreateReader<std_msgs::msg::String>("s1",
                                              std::bind(&__sync__::callback1, &sync_, std::placeholders::_1));
    return true;
}

std::string MultiArgsComponent::Name() const
{
    return "MultiArgsComponent";
}

void MultiArgsComponent::Proc(const std_msgs::msg::String::SharedPtr p1, const std_msgs::msg::String::SharedPtr p2)
{
    std::cout << p1->data << std::endl;
    std::cout << p2->data << std::endl;
}
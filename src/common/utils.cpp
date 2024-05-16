#include "cyber/cyber.h"
#include "unistd.h"
#include <time.h>
bool apollo::cyber::IsShutdown()
{
    return !rclcpp::ok();
}
bool apollo::cyber::OK()
{
    return rclcpp::ok();
}

void apollo::cyber::ComponentBase::FillHeader(std::string name, std_msgs::msg::Header &header)
{
    header.frame_id = name;
    header.stamp = rclcpp::Clock().now();
}

void apollo::cyber::ComponentBase::FillHeader(std::string name, apollo_msgs::msg::ApollocommonHeader &header)
{
    static std::atomic<uint64_t> sequence_num = {0};
    double timestamp = ::apollo::cyber::Clock::NowInSeconds();
    header.modulename=(name);
    header.timestampsec=(timestamp);
    header.sequencenum=(static_cast<unsigned int>(sequence_num.fetch_add(1)));
}

std::shared_ptr<apollo::cyber::NIComponent> apollo::cyber::CreateNode(std::string name)
{
    return std::make_shared<apollo::cyber::NIComponent>(name);
}

apollo::cyber::ComponentBase* apollo::cyber::ComponentBase::instance(){
    return (apollo::cyber::ComponentBase*)currentNode;
}
namespace apollo::cyber
{
    rclcpp::Node *currentNode;
}

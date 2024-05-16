#include "std_msgs/msg/header.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include <string>
namespace apollo_msgs::msg
{
    nlohmann::json to_json(std_msgs::msg::Header msg);
    std_msgs::msg::Header from_json_Header(nlohmann::json obj);
    close_after_if_not_null &operator<<(close_after_if_not_null stream, const std_msgs::msg::Header &msg);
}
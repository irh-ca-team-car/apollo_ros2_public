#include "cyber/cyber.h"
#include "cyber/adapter.h"
#include "cyber/common/file.h"
#include "apollo_msgs/msg/apollocanbus_wey.hpp"
#include "adapter/serialization/apollo_msgs/apollocontrol_control_command.hpp"
#include "adapter/serialization/apollo_msgs/apollocanbus_wey.hpp"
#include "std_msgs/msg/float64.hpp"
#include "std_msgs/msg/bool.hpp"
#include <filesystem>
#include <iostream>

class DrivekitComponent : public apollo::cyber::Component
{
public:
    DrivekitComponent() : Component("DrivekitComponent") {}
    bool Init();
    void callback(const apollo_msgs::msg::ApollocontrolControlCommand::SharedPtr msg);
    void callback_angle(const std_msgs::msg::Float64::SharedPtr msg);
    std::shared_ptr<apollo::cyber::Reader<apollo_msgs::msg::ApollocontrolControlCommand>> reader_;
    std::shared_ptr<apollo::cyber::Reader<std_msgs::msg::Float64>> readerAngle_;

private:
    void closedLoopControl(_Float64 steeringtarget, std_msgs::msg::Float64 &msg_output);
    _Float64 last_angle_val;
    rclcpp::Publisher<std_msgs::msg::Float64>::SharedPtr pub_torque;
    rclcpp::Publisher<std_msgs::msg::Float64>::SharedPtr pub_acceleration;
    rclcpp::Publisher<std_msgs::msg::Float64>::SharedPtr pub_brake;
    rclcpp::Publisher<std_msgs::msg::Bool>::SharedPtr pub_enabled;
};
#include "component/drivekit.h"
#include "modules/common/util/json_util.h"
#include "adapter/serialization/yaml.hpp"
#include "modules/common/configs/config_gflags.h"
#include <sys/ioctl.h> //ioctl() and TIOCGWINSZ
#include <unistd.h>    // for STDOUT_FILENO
#include "cyber/reader.h"
#include "cyber/writer.h"
#include "modules/common/adapters/adapter_gflags.h"
#include "modules/drivekit/pid_control.h"

#define CAN_TOPIC_DEFAULT "/can0"
#define CAR_ENABLED_TOPIC_DEFAULT "/enabled"
#define CAR_BRAKE_TOPIC_DEFAULT "/brake"
#define CAR_THROTTLE_TOPIC_DEFAULT "/throttle"
#define CAR_STEERING_TORQUE_TOPIC_DEFAULT "/steering/desired"

std::string CAN_TOPIC;
std::string CAR_ENABLED_TOPIC;
std::string CAR_BRAKE_TOPIC;
std::string CAR_THROTTLE_TOPIC;
std::string CAR_STEERING_TORQUE_TOPIC;
std::string CAR_SPEED_FEEDBACK_TOPIC;
std::string CAR_ANGLE_FEEDBACK_TOPIC;

bool DrivekitComponent::Init()
{
    apollo::common::gflags::init_common(this);
    apollo::common::gflags::init_common_adapter(this);
    reader_ = CreateReader<apollo_msgs::msg::ApollocontrolControlCommand>(FLAGS_control_command_topic,
                                                                          std::bind(&DrivekitComponent::callback, this, std::placeholders::_1)
    );
    
   
    auto prefix = declare_parameter<std::string>("prefix", "car");
    CAR_BRAKE_TOPIC = prefix + CAR_BRAKE_TOPIC_DEFAULT;
    CAR_THROTTLE_TOPIC = prefix + CAR_THROTTLE_TOPIC_DEFAULT;
    CAR_STEERING_TORQUE_TOPIC = prefix + CAR_STEERING_TORQUE_TOPIC_DEFAULT;
    CAR_ENABLED_TOPIC = prefix + CAR_ENABLED_TOPIC_DEFAULT;

    AINFO<< "Topics";
    AINFO<< "\tCOMMAND  :"<< CAR_BRAKE_TOPIC;
    AINFO<< "\t          "<< CAR_THROTTLE_TOPIC;
    AINFO<< "\t          "<< CAR_STEERING_TORQUE_TOPIC;
    AINFO<< "\t          "<< CAR_ENABLED_TOPIC;

    pub_torque = this->create_publisher<std_msgs::msg::Float64>(CAR_STEERING_TORQUE_TOPIC, 10);
    pub_acceleration = this->create_publisher<std_msgs::msg::Float64>(CAR_THROTTLE_TOPIC, 10);
    pub_brake = this->create_publisher<std_msgs::msg::Float64>(CAR_BRAKE_TOPIC, 10);
    pub_enabled = this->create_publisher<std_msgs::msg::Bool>(CAR_ENABLED_TOPIC, 10);


    return true;
}
void DrivekitComponent::callback_angle(const std_msgs::msg::Float64::SharedPtr msg)
{
    this->last_angle_val = msg->data;
}
void DrivekitComponent::callback(const apollo_msgs::msg::ApollocontrolControlCommand::SharedPtr msg)
{
    AINFO << "Callback received" <<msg;

    auto msg_en = std_msgs::msg::Bool();
    msg_en.data = msg->engineonoff;
    pub_enabled->publish(msg_en);
    if(msg->engineonoff)
    {
        auto msg_torque = std_msgs::msg::Float64();
        //msg->steeringrate IS ALWAYS POSITIVE NO MATTER THE DIRECTION
        // CURRENT AND TARGET POSITION MUST BE KNOWN TO CALCULATE DIRECTION
        // DRIVEKIT EXPECT -1 TO 1 NOT 0 TO 100
        //msg_torque.data = msg->steeringrate;
        closedLoopControl(msg->steeringtarget, msg_torque);
        pub_torque->publish(msg_torque);

        auto msg_accel = std_msgs::msg::Float64();
        msg_accel.data = msg->throttle / 100;
        pub_acceleration->publish(msg_accel);

        auto msg_brake = std_msgs::msg::Float64();
        msg_brake.data = msg->brake/100;
        pub_brake->publish(msg_brake);
    }
}
void DrivekitComponent::closedLoopControl(_Float64 steeringtarget, std_msgs::msg::Float64 &msg_output)
{
    msg_output.data = steeringtarget;
}

#include "cyber/common/macros.h"
#include "cyber/cyber.h"
#include "modules/canbus/proto/chassis.pb.h"
#include "modules/canbus/proto/chassis_detail.pb.h"
#include "std_msgs/msg/float64.hpp"
#include "std_msgs/msg/bool.hpp"
#include "can_msgs/msg/frame.hpp"

class kia_translator
{
    public:
        void translate(can_msgs::msg::Frame frm, apollo_msgs::msg::ApollocanbusChassis &chassis);
        void translate(can_msgs::msg::Frame frm, apollo_msgs::msg::ApollocanbusChassisDetail &chassis);
};
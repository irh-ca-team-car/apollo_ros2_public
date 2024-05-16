#pragma once
#include "modules/common/proto/header.pb.h"
#include "apollo_msgs/msg/apollocontriblgsvl_msgs_bounding_box2_d.hpp"
#include "adapter/serialization/apollo_msgs/apollocontriblgsvl_msgs_bounding_box2_d.hpp"
namespace apollo::contrib::lgsvl_msgs{
	typedef apollo_msgs::msg::ApollocontriblgsvlMsgsBoundingBox2D BoundingBox2D;
}
#include "apollo_msgs/msg/apollocontriblgsvl_msgs_vector3.hpp"
#include "adapter/serialization/apollo_msgs/apollocontriblgsvl_msgs_vector3.hpp"
namespace apollo::contrib::lgsvl_msgs{
	typedef apollo_msgs::msg::ApollocontriblgsvlMsgsVector3 Vector3;
}
#include "apollo_msgs/msg/apollocontriblgsvl_msgs_twist.hpp"
#include "adapter/serialization/apollo_msgs/apollocontriblgsvl_msgs_twist.hpp"
namespace apollo::contrib::lgsvl_msgs{
	typedef apollo_msgs::msg::ApollocontriblgsvlMsgsTwist Twist;
}
#include "apollo_msgs/msg/apollocontriblgsvl_msgs_detection2_d.hpp"
#include "adapter/serialization/apollo_msgs/apollocontriblgsvl_msgs_detection2_d.hpp"
namespace apollo::contrib::lgsvl_msgs{
	typedef apollo_msgs::msg::ApollocontriblgsvlMsgsDetection2D Detection2D;
}
#pragma once
#include "modules/common/proto/header.pb.h"
#include "modules/common/proto/geometry.pb.h"
#include "modules/contrib/lgsvl_msgs/proto/detection2d.pb.h"
#include "apollo_msgs/msg/apollocontriblgsvl_msgs_pose.hpp"
#include "adapter/serialization/apollo_msgs/apollocontriblgsvl_msgs_pose.hpp"
namespace apollo::contrib::lgsvl_msgs{
	typedef apollo_msgs::msg::ApollocontriblgsvlMsgsPose Pose;
}
#include "apollo_msgs/msg/apollocontriblgsvl_msgs_bounding_box3_d.hpp"
#include "adapter/serialization/apollo_msgs/apollocontriblgsvl_msgs_bounding_box3_d.hpp"
namespace apollo::contrib::lgsvl_msgs{
	typedef apollo_msgs::msg::ApollocontriblgsvlMsgsBoundingBox3D BoundingBox3D;
}
#include "apollo_msgs/msg/apollocontriblgsvl_msgs_detection3_d.hpp"
#include "adapter/serialization/apollo_msgs/apollocontriblgsvl_msgs_detection3_d.hpp"
namespace apollo::contrib::lgsvl_msgs{
	typedef apollo_msgs::msg::ApollocontriblgsvlMsgsDetection3D Detection3D;
}
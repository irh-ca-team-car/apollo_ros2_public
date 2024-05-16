#pragma once
#include "modules/common/proto/header.pb.h"
#include "modules/contrib/lgsvl_msgs/proto/detection3d.pb.h"
#include "apollo_msgs/msg/apollocontriblgsvl_msgs_detection3_d_array.hpp"
#include "adapter/serialization/apollo_msgs/apollocontriblgsvl_msgs_detection3_d_array.hpp"
namespace apollo::contrib::lgsvl_msgs{
	typedef apollo_msgs::msg::ApollocontriblgsvlMsgsDetection3DArray Detection3DArray;
}
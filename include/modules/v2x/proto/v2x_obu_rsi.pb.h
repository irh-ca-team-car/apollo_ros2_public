#pragma once
#include "modules/common/proto/header.pb.h"
#include "modules/common/proto/geometry.pb.h"
#include "apollo_msgs/msg/apollov2xobu_obu_rsi.hpp"
#include "adapter/serialization/apollo_msgs/apollov2xobu_obu_rsi.hpp"
namespace apollo::v2x::obu{
	typedef apollo_msgs::msg::Apollov2xobuObuRsi ObuRsi;
}
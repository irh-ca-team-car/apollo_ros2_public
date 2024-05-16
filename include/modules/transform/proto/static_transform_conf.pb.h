#pragma once
#include "apollo_msgs/msg/apollostatic_transform_extrinsic_file.hpp"
#include "adapter/serialization/apollo_msgs/apollostatic_transform_extrinsic_file.hpp"
namespace apollo::static_transform{
	typedef apollo_msgs::msg::ApollostaticTransformExtrinsicFile ExtrinsicFile;
}
#include "apollo_msgs/msg/apollostatic_transform_conf.hpp"
#include "adapter/serialization/apollo_msgs/apollostatic_transform_conf.hpp"
namespace apollo::static_transform{
	typedef apollo_msgs::msg::ApollostaticTransformConf Conf;
}
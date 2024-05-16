#pragma once
#include "modules/common/proto/header.pb.h"
#include "apollo_msgs/msg/apollocommonutiltest_simple_message.hpp"
#include "adapter/serialization/apollo_msgs/apollocommonutiltest_simple_message.hpp"
namespace apollo::common::util::test{
	typedef apollo_msgs::msg::ApollocommonutiltestSimpleMessage SimpleMessage;
}
#include "apollo_msgs/msg/apollocommonutiltest_simple_repeated_message.hpp"
#include "adapter/serialization/apollo_msgs/apollocommonutiltest_simple_repeated_message.hpp"
namespace apollo::common::util::test{
	typedef apollo_msgs::msg::ApollocommonutiltestSimpleRepeatedMessage SimpleRepeatedMessage;
}
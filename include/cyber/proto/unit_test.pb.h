#pragma once
#include "apollo_msgs/msg/apollocyberproto_unit_test.hpp"
#include "adapter/serialization/apollo_msgs/apollocyberproto_unit_test.hpp"
namespace apollo::cyber::proto{
	typedef apollo_msgs::msg::ApollocyberprotoUnitTest UnitTest;
}
#include "apollo_msgs/msg/apollocyberproto_chatter.hpp"
#include "adapter/serialization/apollo_msgs/apollocyberproto_chatter.hpp"
namespace apollo::cyber::proto{
	typedef apollo_msgs::msg::ApollocyberprotoChatter Chatter;
}
#include "apollo_msgs/msg/apollocyberproto_chatter_benchmark.hpp"
#include "adapter/serialization/apollo_msgs/apollocyberproto_chatter_benchmark.hpp"
namespace apollo::cyber::proto{
	typedef apollo_msgs::msg::ApollocyberprotoChatterBenchmark ChatterBenchmark;
}
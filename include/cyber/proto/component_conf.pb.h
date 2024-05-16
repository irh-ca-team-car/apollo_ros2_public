#pragma once
#include "cyber/proto/qos_profile.pb.h"
#include "apollo_msgs/msg/apollocyberproto_reader_option.hpp"
#include "adapter/serialization/apollo_msgs/apollocyberproto_reader_option.hpp"
namespace apollo::cyber::proto{
	typedef apollo_msgs::msg::ApollocyberprotoReaderOption ReaderOption;
}
#include "apollo_msgs/msg/apollocyberproto_component_config.hpp"
#include "adapter/serialization/apollo_msgs/apollocyberproto_component_config.hpp"
namespace apollo::cyber::proto{
	typedef apollo_msgs::msg::ApollocyberprotoComponentConfig ComponentConfig;
}
#include "apollo_msgs/msg/apollocyberproto_timer_component_config.hpp"
#include "adapter/serialization/apollo_msgs/apollocyberproto_timer_component_config.hpp"
namespace apollo::cyber::proto{
	typedef apollo_msgs::msg::ApollocyberprotoTimerComponentConfig TimerComponentConfig;
}
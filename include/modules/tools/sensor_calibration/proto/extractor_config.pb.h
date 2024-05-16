#pragma once
#include "apollo_msgs/msg/io_config.hpp"
#include "adapter/serialization/apollo_msgs/io_config.hpp"
namespace {
	typedef apollo_msgs::msg::IoConfig IoConfig;
}
#include "apollo_msgs/msg/channel_config.hpp"
#include "adapter/serialization/apollo_msgs/channel_config.hpp"
namespace {
	typedef apollo_msgs::msg::ChannelConfig ChannelConfig;
}
#include "apollo_msgs/msg/channels.hpp"
#include "adapter/serialization/apollo_msgs/channels.hpp"
namespace {
	typedef apollo_msgs::msg::Channels Channels;
}
#include "apollo_msgs/msg/records.hpp"
#include "adapter/serialization/apollo_msgs/records.hpp"
namespace {
	typedef apollo_msgs::msg::Records Records;
}
#include "apollo_msgs/msg/data_extraction_config.hpp"
#include "adapter/serialization/apollo_msgs/data_extraction_config.hpp"
namespace {
	typedef apollo_msgs::msg::DataExtractionConfig DataExtractionConfig;
}
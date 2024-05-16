#pragma once
#include "modules/common/proto/header.pb.h"
#include "apollo_msgs/msg/apollocommon_latency_record.hpp"
#include "adapter/serialization/apollo_msgs/apollocommon_latency_record.hpp"
namespace apollo::common{
	typedef apollo_msgs::msg::ApollocommonLatencyRecord LatencyRecord;
}
#include "apollo_msgs/msg/apollocommon_latency_record_map.hpp"
#include "adapter/serialization/apollo_msgs/apollocommon_latency_record_map.hpp"
namespace apollo::common{
	typedef apollo_msgs::msg::ApollocommonLatencyRecordMap LatencyRecordMap;
}
#include "apollo_msgs/msg/apollocommon_latency_stat.hpp"
#include "adapter/serialization/apollo_msgs/apollocommon_latency_stat.hpp"
namespace apollo::common{
	typedef apollo_msgs::msg::ApollocommonLatencyStat LatencyStat;
}
#include "apollo_msgs/msg/apollocommon_latency_track_latency_track_message.hpp"
#include "adapter/serialization/apollo_msgs/apollocommon_latency_track_latency_track_message.hpp"
namespace apollo::common::LatencyTrack{
	typedef apollo_msgs::msg::ApollocommonLatencyTrackLatencyTrackMessage LatencyTrackMessage;
}
#include "apollo_msgs/msg/apollocommon_latency_track.hpp"
#include "adapter/serialization/apollo_msgs/apollocommon_latency_track.hpp"
#include "apollo_msgs/msg/apollocommon_latency_report.hpp"
#include "adapter/serialization/apollo_msgs/apollocommon_latency_report.hpp"
namespace apollo::common{
	typedef apollo_msgs::msg::ApollocommonLatencyReport LatencyReport;
}
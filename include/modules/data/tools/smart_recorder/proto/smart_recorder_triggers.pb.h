#pragma once
#include "apollo_msgs/msg/apollodata_record_segment_setting.hpp"
#include "adapter/serialization/apollo_msgs/apollodata_record_segment_setting.hpp"
namespace apollo::data{
	typedef apollo_msgs::msg::ApollodataRecordSegmentSetting RecordSegmentSetting;
}
#include "apollo_msgs/msg/apollodata_trigger.hpp"
#include "adapter/serialization/apollo_msgs/apollodata_trigger.hpp"
namespace apollo::data{
	typedef apollo_msgs::msg::ApollodataTrigger Trigger;
}
#include "apollo_msgs/msg/apollodata_smart_record_trigger.hpp"
#include "adapter/serialization/apollo_msgs/apollodata_smart_record_trigger.hpp"
namespace apollo::data{
	typedef apollo_msgs::msg::ApollodataSmartRecordTrigger SmartRecordTrigger;
}
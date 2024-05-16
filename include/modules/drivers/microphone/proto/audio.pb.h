#pragma once
#include "modules/common/proto/header.pb.h"
#include "modules/drivers/microphone/proto/microphone_config.pb.h"
#include "apollo_msgs/msg/apollodriversmicrophoneconfig_channel_data.hpp"
#include "adapter/serialization/apollo_msgs/apollodriversmicrophoneconfig_channel_data.hpp"
namespace apollo::drivers::microphone::config{
	typedef apollo_msgs::msg::ApollodriversmicrophoneconfigChannelData ChannelData;
}
#include "apollo_msgs/msg/apollodriversmicrophoneconfig_audio_data.hpp"
#include "adapter/serialization/apollo_msgs/apollodriversmicrophoneconfig_audio_data.hpp"
namespace apollo::drivers::microphone::config{
	typedef apollo_msgs::msg::ApollodriversmicrophoneconfigAudioData AudioData;
}
#pragma once
#include "apollo_msgs/msg/apollodriversmicrophoneconfig_microphone_config.hpp"
#include "adapter/serialization/apollo_msgs/apollodriversmicrophoneconfig_microphone_config.hpp"
namespace apollo::drivers::microphone::config{
	enum ChannelType {
		UNKNOWN = 0,
		ASR = 1,  // Automatic Speech Recognition
		RAW = 2,
		PLAYBACK = 3
	};
}
namespace apollo::drivers::microphone::config::MicrophoneConfig{
	enum MicrophoneModel {
		UNKNOWN = 0,
		RESPEAKER = 1
	};
}
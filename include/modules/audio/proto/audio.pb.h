#pragma once
#include "modules/audio/proto/audio_common.pb.h"
#include "modules/common/proto/geometry.pb.h"
#include "modules/common/proto/header.pb.h"
#include "apollo_msgs/msg/apolloaudio_audio_detection.hpp"
#include "adapter/serialization/apollo_msgs/apolloaudio_audio_detection.hpp"
namespace apollo::audio{
	typedef apollo_msgs::msg::ApolloaudioAudioDetection AudioDetection;
}
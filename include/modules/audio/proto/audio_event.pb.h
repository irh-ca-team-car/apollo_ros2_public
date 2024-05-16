#pragma once
#include "modules/audio/proto/audio_common.pb.h"
#include "modules/common/proto/header.pb.h"
#include "modules/localization/proto/pose.pb.h"
#include "apollo_msgs/msg/apolloaudio_audio_event.hpp"
#include "adapter/serialization/apollo_msgs/apolloaudio_audio_event.hpp"
namespace apollo::audio{
	typedef apollo_msgs::msg::ApolloaudioAudioEvent AudioEvent;
}
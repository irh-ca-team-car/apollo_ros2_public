#pragma once
#include "apollo_msgs/msg/apolloaudio_topic_conf.hpp"
#include "adapter/serialization/apollo_msgs/apolloaudio_topic_conf.hpp"
namespace apollo::audio{
	typedef apollo_msgs::msg::ApolloaudioTopicConf TopicConf;
}
#include "apollo_msgs/msg/apolloaudio_audio_conf.hpp"
#include "adapter/serialization/apollo_msgs/apolloaudio_audio_conf.hpp"
namespace apollo::audio{
	typedef apollo_msgs::msg::ApolloaudioAudioConf AudioConf;
}
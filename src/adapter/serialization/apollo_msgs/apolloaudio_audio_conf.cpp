#include "adapter/serialization/apollo_msgs/apolloaudio_audio_conf.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloaudioAudioConf &msg) {
        nlohmann::json obj;
        obj["topicconf"] = to_json(msg.topicconf);
        obj["respeakerextrinsicspath"] = (msg.respeakerextrinsicspath);
        return obj;
    }
    ApolloaudioAudioConf from_json_ApolloaudioAudioConf (nlohmann::json obj) {
        ApolloaudioAudioConf msg;
        if(obj.contains("topicconf"))
        {
            msg.topicconf = from_json_ApolloaudioTopicConf(obj["topicconf"]);
        }
        if(obj.contains("respeakerextrinsicspath"))
        {
            msg.respeakerextrinsicspath = (obj["respeakerextrinsicspath"].is_string()?(obj["respeakerextrinsicspath"].get<std::string>().c_str()):obj["respeakerextrinsicspath"].get<std::string>());
        }
        return msg;
    }
    template <>
    ApolloaudioAudioConf from_json<ApolloaudioAudioConf>(nlohmann::json obj){
        return from_json_ApolloaudioAudioConf(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloaudioAudioConf &dt)
    {
        dt=from_json_ApolloaudioAudioConf(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloaudioAudioConf & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloaudioAudioConf & dt)
    {
        os << to_json(dt);
        return os;
    }
}

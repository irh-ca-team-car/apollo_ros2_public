#include "adapter/serialization/apollo_msgs/apolloaudio_audio_detection.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloaudioAudioDetection &msg) {
        nlohmann::json obj;
        obj["apolloheader"] = to_json(msg.apolloheader);
        obj["issiren"] = (msg.issiren);
        obj["movingresult"] = (msg.movingresult);
        obj["position"] = to_json(msg.position);
        obj["sourcedegree"] = (msg.sourcedegree);
        return obj;
    }
    ApolloaudioAudioDetection from_json_ApolloaudioAudioDetection (nlohmann::json obj) {
        ApolloaudioAudioDetection msg;
        if(obj.contains("apolloheader"))
        {
            msg.apolloheader = from_json_ApollocommonHeader(obj["apolloheader"]);
        }
        if(obj.contains("issiren"))
        {
            msg.issiren = (obj["issiren"].is_string()?(bool)atoi(obj["issiren"].get<std::string>().c_str()):obj["issiren"].get<bool>());
        }
        if(obj.contains("movingresult"))
        {
            msg.movingresult = (obj["movingresult"].is_string()?atoi(obj["movingresult"].get<std::string>().c_str()):obj["movingresult"].get<int>());
        }
        if(obj.contains("position"))
        {
            msg.position = from_json_ApollocommonPoint3D(obj["position"]);
        }
        if(obj.contains("sourcedegree"))
        {
            msg.sourcedegree = (obj["sourcedegree"].is_string()?atof(obj["sourcedegree"].get<std::string>().c_str()):obj["sourcedegree"].get<double>());
        }
        return msg;
    }
    template <>
    ApolloaudioAudioDetection from_json<ApolloaudioAudioDetection>(nlohmann::json obj){
        return from_json_ApolloaudioAudioDetection(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloaudioAudioDetection &dt)
    {
        dt=from_json_ApolloaudioAudioDetection(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloaudioAudioDetection & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloaudioAudioDetection & dt)
    {
        os << to_json(dt);
        return os;
    }
}

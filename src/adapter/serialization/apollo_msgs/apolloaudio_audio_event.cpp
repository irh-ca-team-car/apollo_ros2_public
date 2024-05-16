#include "adapter/serialization/apollo_msgs/apolloaudio_audio_event.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloaudioAudioEvent &msg) {
        nlohmann::json obj;
        obj["apolloheader"] = to_json(msg.apolloheader);
        obj["id"] = (msg.id);
        obj["movingresult"] = (msg.movingresult);
        obj["audiotype"] = (msg.audiotype);
        obj["sirenison"] = (msg.sirenison);
        obj["audiodirection"] = (msg.audiodirection);
        obj["pose"] = to_json(msg.pose);
        return obj;
    }
    ApolloaudioAudioEvent from_json_ApolloaudioAudioEvent (nlohmann::json obj) {
        ApolloaudioAudioEvent msg;
        if(obj.contains("apolloheader"))
        {
            msg.apolloheader = from_json_ApollocommonHeader(obj["apolloheader"]);
        }
        if(obj.contains("id"))
        {
            msg.id = (obj["id"].is_string()?atoi(obj["id"].get<std::string>().c_str()):obj["id"].get<int>());
        }
        if(obj.contains("movingresult"))
        {
            msg.movingresult = (obj["movingresult"].is_string()?atoi(obj["movingresult"].get<std::string>().c_str()):obj["movingresult"].get<int>());
        }
        if(obj.contains("audiotype"))
        {
            msg.audiotype = (obj["audiotype"].is_string()?atoi(obj["audiotype"].get<std::string>().c_str()):obj["audiotype"].get<int>());
        }
        if(obj.contains("sirenison"))
        {
            msg.sirenison = (obj["sirenison"].is_string()?(bool)atoi(obj["sirenison"].get<std::string>().c_str()):obj["sirenison"].get<bool>());
        }
        if(obj.contains("audiodirection"))
        {
            msg.audiodirection = (obj["audiodirection"].is_string()?atoi(obj["audiodirection"].get<std::string>().c_str()):obj["audiodirection"].get<int>());
        }
        if(obj.contains("pose"))
        {
            msg.pose = from_json_ApollolocalizationPose(obj["pose"]);
        }
        return msg;
    }
    template <>
    ApolloaudioAudioEvent from_json<ApolloaudioAudioEvent>(nlohmann::json obj){
        return from_json_ApolloaudioAudioEvent(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloaudioAudioEvent &dt)
    {
        dt=from_json_ApolloaudioAudioEvent(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloaudioAudioEvent & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloaudioAudioEvent & dt)
    {
        os << to_json(dt);
        return os;
    }
}

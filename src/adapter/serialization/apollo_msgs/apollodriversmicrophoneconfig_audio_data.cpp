#include "adapter/serialization/apollo_msgs/apollodriversmicrophoneconfig_audio_data.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversmicrophoneconfigAudioData &msg) {
        nlohmann::json obj;
        obj["apolloheader"] = to_json(msg.apolloheader);
        obj["microphoneconfig"] = to_json(msg.microphoneconfig);
        nlohmann::json arr_channeldata;
        for (auto it = msg.channeldata.begin(); it != msg.channeldata.end(); ++it) {
            arr_channeldata.push_back(to_json(*it));
        }
        obj["channeldata"] = arr_channeldata;
        return obj;
    }
    ApollodriversmicrophoneconfigAudioData from_json_ApollodriversmicrophoneconfigAudioData (nlohmann::json obj) {
        ApollodriversmicrophoneconfigAudioData msg;
        if(obj.contains("apolloheader"))
        {
            msg.apolloheader = from_json_ApollocommonHeader(obj["apolloheader"]);
        }
        if(obj.contains("microphoneconfig"))
        {
            msg.microphoneconfig = from_json_ApollodriversmicrophoneconfigMicrophoneConfig(obj["microphoneconfig"]);
        }
        if(obj.contains("channeldata"))
        {
            if(obj["channeldata"].is_array())
            {
                for (auto& element : obj["channeldata"])
                {
                    msg.channeldata.push_back(from_json_ApollodriversmicrophoneconfigChannelData(element));
                }
            }
            else
            {
                msg.channeldata.push_back(from_json_ApollodriversmicrophoneconfigChannelData(obj["channeldata"]));
            }
        }
        return msg;
    }
    template <>
    ApollodriversmicrophoneconfigAudioData from_json<ApollodriversmicrophoneconfigAudioData>(nlohmann::json obj){
        return from_json_ApollodriversmicrophoneconfigAudioData(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversmicrophoneconfigAudioData &dt)
    {
        dt=from_json_ApollodriversmicrophoneconfigAudioData(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollodriversmicrophoneconfigAudioData & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversmicrophoneconfigAudioData & dt)
    {
        os << to_json(dt);
        return os;
    }
}

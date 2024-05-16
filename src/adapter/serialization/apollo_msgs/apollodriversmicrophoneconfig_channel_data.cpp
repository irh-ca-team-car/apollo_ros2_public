#include "adapter/serialization/apollo_msgs/apollodriversmicrophoneconfig_channel_data.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversmicrophoneconfigChannelData &msg) {
        nlohmann::json obj;
        obj["channeltype"] = (msg.channeltype);
        obj["data"] = to_json(msg.data);
        return obj;
    }
    ApollodriversmicrophoneconfigChannelData from_json_ApollodriversmicrophoneconfigChannelData (nlohmann::json obj) {
        ApollodriversmicrophoneconfigChannelData msg;
        if(obj.contains("channeltype"))
        {
            msg.channeltype = (obj["channeltype"].is_string()?atoi(obj["channeltype"].get<std::string>().c_str()):obj["channeltype"].get<int>());
        }
        if(obj.contains("data"))
        {
            msg.data = from_json_Bytes(obj["data"]);
        }
        return msg;
    }
    template <>
    ApollodriversmicrophoneconfigChannelData from_json<ApollodriversmicrophoneconfigChannelData>(nlohmann::json obj){
        return from_json_ApollodriversmicrophoneconfigChannelData(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversmicrophoneconfigChannelData &dt)
    {
        dt=from_json_ApollodriversmicrophoneconfigChannelData(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollodriversmicrophoneconfigChannelData & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversmicrophoneconfigChannelData & dt)
    {
        os << to_json(dt);
        return os;
    }
}

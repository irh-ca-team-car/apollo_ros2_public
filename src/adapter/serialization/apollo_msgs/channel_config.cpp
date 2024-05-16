#include "adapter/serialization/apollo_msgs/channel_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ChannelConfig &msg) {
        nlohmann::json obj;
        obj["description"] = (msg.description);
        obj["name"] = (msg.name);
        obj["extractionrate"] = (msg.extractionrate);
        return obj;
    }
    ChannelConfig from_json_ChannelConfig (nlohmann::json obj) {
        ChannelConfig msg;
        if(obj.contains("description"))
        {
            msg.description = (obj["description"].is_string()?(obj["description"].get<std::string>().c_str()):obj["description"].get<std::string>());
        }
        if(obj.contains("name"))
        {
            msg.name = (obj["name"].is_string()?(obj["name"].get<std::string>().c_str()):obj["name"].get<std::string>());
        }
        if(obj.contains("extractionrate"))
        {
            msg.extractionrate = (obj["extractionrate"].is_string()?atoi(obj["extractionrate"].get<std::string>().c_str()):obj["extractionrate"].get<uint32_t>());
        }
        return msg;
    }
    template <>
    ChannelConfig from_json<ChannelConfig>(nlohmann::json obj){
        return from_json_ChannelConfig(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ChannelConfig &dt)
    {
        dt=from_json_ChannelConfig(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ChannelConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ChannelConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
}

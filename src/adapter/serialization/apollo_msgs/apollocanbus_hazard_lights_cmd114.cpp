#include "adapter/serialization/apollo_msgs/apollocanbus_hazard_lights_cmd114.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusHazardLightsCmd114 &msg) {
        nlohmann::json obj;
        obj["hazardlightscmd"] = (msg.hazardlightscmd);
        obj["ignoreoverrides"] = (msg.ignoreoverrides);
        obj["clearoverride"] = (msg.clearoverride);
        obj["enable"] = (msg.enable);
        obj["clearfaults"] = (msg.clearfaults);
        return obj;
    }
    ApollocanbusHazardLightsCmd114 from_json_ApollocanbusHazardLightsCmd114 (nlohmann::json obj) {
        ApollocanbusHazardLightsCmd114 msg;
        if(obj.contains("hazardlightscmd"))
        {
            msg.hazardlightscmd = (obj["hazardlightscmd"].is_string()?(bool)atoi(obj["hazardlightscmd"].get<std::string>().c_str()):obj["hazardlightscmd"].get<bool>());
        }
        if(obj.contains("ignoreoverrides"))
        {
            msg.ignoreoverrides = (obj["ignoreoverrides"].is_string()?(bool)atoi(obj["ignoreoverrides"].get<std::string>().c_str()):obj["ignoreoverrides"].get<bool>());
        }
        if(obj.contains("clearoverride"))
        {
            msg.clearoverride = (obj["clearoverride"].is_string()?(bool)atoi(obj["clearoverride"].get<std::string>().c_str()):obj["clearoverride"].get<bool>());
        }
        if(obj.contains("enable"))
        {
            msg.enable = (obj["enable"].is_string()?(bool)atoi(obj["enable"].get<std::string>().c_str()):obj["enable"].get<bool>());
        }
        if(obj.contains("clearfaults"))
        {
            msg.clearfaults = (obj["clearfaults"].is_string()?(bool)atoi(obj["clearfaults"].get<std::string>().c_str()):obj["clearfaults"].get<bool>());
        }
        return msg;
    }
    template <>
    ApollocanbusHazardLightsCmd114 from_json<ApollocanbusHazardLightsCmd114>(nlohmann::json obj){
        return from_json_ApollocanbusHazardLightsCmd114(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusHazardLightsCmd114 &dt)
    {
        dt=from_json_ApollocanbusHazardLightsCmd114(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusHazardLightsCmd114 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusHazardLightsCmd114 & dt)
    {
        os << to_json(dt);
        return os;
    }
}

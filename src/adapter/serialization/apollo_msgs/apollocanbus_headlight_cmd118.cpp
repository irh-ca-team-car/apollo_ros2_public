#include "adapter/serialization/apollo_msgs/apollocanbus_headlight_cmd118.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusHeadlightCmd118 &msg) {
        nlohmann::json obj;
        obj["ignoreoverrides"] = (msg.ignoreoverrides);
        obj["enable"] = (msg.enable);
        obj["clearoverride"] = (msg.clearoverride);
        obj["clearfaults"] = (msg.clearfaults);
        obj["headlightcmd"] = (msg.headlightcmd);
        return obj;
    }
    ApollocanbusHeadlightCmd118 from_json_ApollocanbusHeadlightCmd118 (nlohmann::json obj) {
        ApollocanbusHeadlightCmd118 msg;
        if(obj.contains("ignoreoverrides"))
        {
            msg.ignoreoverrides = (obj["ignoreoverrides"].is_string()?(bool)atoi(obj["ignoreoverrides"].get<std::string>().c_str()):obj["ignoreoverrides"].get<bool>());
        }
        if(obj.contains("enable"))
        {
            msg.enable = (obj["enable"].is_string()?(bool)atoi(obj["enable"].get<std::string>().c_str()):obj["enable"].get<bool>());
        }
        if(obj.contains("clearoverride"))
        {
            msg.clearoverride = (obj["clearoverride"].is_string()?(bool)atoi(obj["clearoverride"].get<std::string>().c_str()):obj["clearoverride"].get<bool>());
        }
        if(obj.contains("clearfaults"))
        {
            msg.clearfaults = (obj["clearfaults"].is_string()?(bool)atoi(obj["clearfaults"].get<std::string>().c_str()):obj["clearfaults"].get<bool>());
        }
        if(obj.contains("headlightcmd"))
        {
            msg.headlightcmd = (obj["headlightcmd"].is_string()?atoi(obj["headlightcmd"].get<std::string>().c_str()):obj["headlightcmd"].get<int>());
        }
        return msg;
    }
    template <>
    ApollocanbusHeadlightCmd118 from_json<ApollocanbusHeadlightCmd118>(nlohmann::json obj){
        return from_json_ApollocanbusHeadlightCmd118(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusHeadlightCmd118 &dt)
    {
        dt=from_json_ApollocanbusHeadlightCmd118(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusHeadlightCmd118 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusHeadlightCmd118 & dt)
    {
        os << to_json(dt);
        return os;
    }
}

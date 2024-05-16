#include "adapter/serialization/apollo_msgs/apollocanbus_media_controls_cmd120.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusMediaControlsCmd120 &msg) {
        nlohmann::json obj;
        obj["mediacontrolscmd"] = (msg.mediacontrolscmd);
        obj["ignoreoverrides"] = (msg.ignoreoverrides);
        obj["clearoverride"] = (msg.clearoverride);
        obj["clearfaults"] = (msg.clearfaults);
        obj["enable"] = (msg.enable);
        return obj;
    }
    ApollocanbusMediaControlsCmd120 from_json_ApollocanbusMediaControlsCmd120 (nlohmann::json obj) {
        ApollocanbusMediaControlsCmd120 msg;
        if(obj.contains("mediacontrolscmd"))
        {
            msg.mediacontrolscmd = (obj["mediacontrolscmd"].is_string()?atoi(obj["mediacontrolscmd"].get<std::string>().c_str()):obj["mediacontrolscmd"].get<int>());
        }
        if(obj.contains("ignoreoverrides"))
        {
            msg.ignoreoverrides = (obj["ignoreoverrides"].is_string()?(bool)atoi(obj["ignoreoverrides"].get<std::string>().c_str()):obj["ignoreoverrides"].get<bool>());
        }
        if(obj.contains("clearoverride"))
        {
            msg.clearoverride = (obj["clearoverride"].is_string()?(bool)atoi(obj["clearoverride"].get<std::string>().c_str()):obj["clearoverride"].get<bool>());
        }
        if(obj.contains("clearfaults"))
        {
            msg.clearfaults = (obj["clearfaults"].is_string()?(bool)atoi(obj["clearfaults"].get<std::string>().c_str()):obj["clearfaults"].get<bool>());
        }
        if(obj.contains("enable"))
        {
            msg.enable = (obj["enable"].is_string()?(bool)atoi(obj["enable"].get<std::string>().c_str()):obj["enable"].get<bool>());
        }
        return msg;
    }
    template <>
    ApollocanbusMediaControlsCmd120 from_json<ApollocanbusMediaControlsCmd120>(nlohmann::json obj){
        return from_json_ApollocanbusMediaControlsCmd120(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusMediaControlsCmd120 &dt)
    {
        dt=from_json_ApollocanbusMediaControlsCmd120(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusMediaControlsCmd120 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusMediaControlsCmd120 & dt)
    {
        os << to_json(dt);
        return os;
    }
}

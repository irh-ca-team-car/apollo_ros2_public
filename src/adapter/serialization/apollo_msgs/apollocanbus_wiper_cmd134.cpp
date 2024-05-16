#include "adapter/serialization/apollo_msgs/apollocanbus_wiper_cmd134.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusWiperCmd134 &msg) {
        nlohmann::json obj;
        obj["ignoreoverrides"] = (msg.ignoreoverrides);
        obj["enable"] = (msg.enable);
        obj["clearoverride"] = (msg.clearoverride);
        obj["wipercmd"] = (msg.wipercmd);
        obj["clearfaults"] = (msg.clearfaults);
        return obj;
    }
    ApollocanbusWiperCmd134 from_json_ApollocanbusWiperCmd134 (nlohmann::json obj) {
        ApollocanbusWiperCmd134 msg;
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
        if(obj.contains("wipercmd"))
        {
            msg.wipercmd = (obj["wipercmd"].is_string()?atoi(obj["wipercmd"].get<std::string>().c_str()):obj["wipercmd"].get<int>());
        }
        if(obj.contains("clearfaults"))
        {
            msg.clearfaults = (obj["clearfaults"].is_string()?(bool)atoi(obj["clearfaults"].get<std::string>().c_str()):obj["clearfaults"].get<bool>());
        }
        return msg;
    }
    template <>
    ApollocanbusWiperCmd134 from_json<ApollocanbusWiperCmd134>(nlohmann::json obj){
        return from_json_ApollocanbusWiperCmd134(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusWiperCmd134 &dt)
    {
        dt=from_json_ApollocanbusWiperCmd134(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusWiperCmd134 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusWiperCmd134 & dt)
    {
        os << to_json(dt);
        return os;
    }
}

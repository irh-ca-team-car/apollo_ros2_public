#include "adapter/serialization/apollo_msgs/apollocanbus_horn_cmd11c.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusHornCmd11c &msg) {
        nlohmann::json obj;
        obj["ignoreoverrides"] = (msg.ignoreoverrides);
        obj["enable"] = (msg.enable);
        obj["clearoverride"] = (msg.clearoverride);
        obj["clearfaults"] = (msg.clearfaults);
        obj["horncmd"] = (msg.horncmd);
        return obj;
    }
    ApollocanbusHornCmd11c from_json_ApollocanbusHornCmd11c (nlohmann::json obj) {
        ApollocanbusHornCmd11c msg;
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
        if(obj.contains("horncmd"))
        {
            msg.horncmd = (obj["horncmd"].is_string()?atoi(obj["horncmd"].get<std::string>().c_str()):obj["horncmd"].get<int>());
        }
        return msg;
    }
    template <>
    ApollocanbusHornCmd11c from_json<ApollocanbusHornCmd11c>(nlohmann::json obj){
        return from_json_ApollocanbusHornCmd11c(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusHornCmd11c &dt)
    {
        dt=from_json_ApollocanbusHornCmd11c(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusHornCmd11c & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusHornCmd11c & dt)
    {
        os << to_json(dt);
        return os;
    }
}

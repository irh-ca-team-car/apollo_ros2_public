#include "adapter/serialization/apollo_msgs/apollocanbus_accel_cmd100.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusAccelCmd100 &msg) {
        nlohmann::json obj;
        obj["ignoreoverrides"] = (msg.ignoreoverrides);
        obj["enable"] = (msg.enable);
        obj["clearoverride"] = (msg.clearoverride);
        obj["clearfaults"] = (msg.clearfaults);
        obj["accelcmd"] = (msg.accelcmd);
        return obj;
    }
    ApollocanbusAccelCmd100 from_json_ApollocanbusAccelCmd100 (nlohmann::json obj) {
        ApollocanbusAccelCmd100 msg;
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
        if(obj.contains("accelcmd"))
        {
            msg.accelcmd = (obj["accelcmd"].is_string()?atof(obj["accelcmd"].get<std::string>().c_str()):obj["accelcmd"].get<double>());
        }
        return msg;
    }
    template <>
    ApollocanbusAccelCmd100 from_json<ApollocanbusAccelCmd100>(nlohmann::json obj){
        return from_json_ApollocanbusAccelCmd100(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusAccelCmd100 &dt)
    {
        dt=from_json_ApollocanbusAccelCmd100(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusAccelCmd100 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusAccelCmd100 & dt)
    {
        os << to_json(dt);
        return os;
    }
}

#include "adapter/serialization/apollo_msgs/apollocanbus_shift_cmd128.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusShiftCmd128 &msg) {
        nlohmann::json obj;
        obj["ignoreoverrides"] = (msg.ignoreoverrides);
        obj["enable"] = (msg.enable);
        obj["clearoverride"] = (msg.clearoverride);
        obj["clearfaults"] = (msg.clearfaults);
        obj["shiftcmd"] = (msg.shiftcmd);
        return obj;
    }
    ApollocanbusShiftCmd128 from_json_ApollocanbusShiftCmd128 (nlohmann::json obj) {
        ApollocanbusShiftCmd128 msg;
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
        if(obj.contains("shiftcmd"))
        {
            msg.shiftcmd = (obj["shiftcmd"].is_string()?atoi(obj["shiftcmd"].get<std::string>().c_str()):obj["shiftcmd"].get<int>());
        }
        return msg;
    }
    template <>
    ApollocanbusShiftCmd128 from_json<ApollocanbusShiftCmd128>(nlohmann::json obj){
        return from_json_ApollocanbusShiftCmd128(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusShiftCmd128 &dt)
    {
        dt=from_json_ApollocanbusShiftCmd128(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusShiftCmd128 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusShiftCmd128 & dt)
    {
        os << to_json(dt);
        return os;
    }
}

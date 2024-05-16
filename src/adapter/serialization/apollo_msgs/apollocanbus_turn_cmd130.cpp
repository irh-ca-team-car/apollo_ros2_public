#include "adapter/serialization/apollo_msgs/apollocanbus_turn_cmd130.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusTurnCmd130 &msg) {
        nlohmann::json obj;
        obj["ignoreoverrides"] = (msg.ignoreoverrides);
        obj["enable"] = (msg.enable);
        obj["clearoverride"] = (msg.clearoverride);
        obj["clearfaults"] = (msg.clearfaults);
        obj["turnsignalcmd"] = (msg.turnsignalcmd);
        return obj;
    }
    ApollocanbusTurnCmd130 from_json_ApollocanbusTurnCmd130 (nlohmann::json obj) {
        ApollocanbusTurnCmd130 msg;
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
        if(obj.contains("turnsignalcmd"))
        {
            msg.turnsignalcmd = (obj["turnsignalcmd"].is_string()?atoi(obj["turnsignalcmd"].get<std::string>().c_str()):obj["turnsignalcmd"].get<int>());
        }
        return msg;
    }
    template <>
    ApollocanbusTurnCmd130 from_json<ApollocanbusTurnCmd130>(nlohmann::json obj){
        return from_json_ApollocanbusTurnCmd130(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusTurnCmd130 &dt)
    {
        dt=from_json_ApollocanbusTurnCmd130(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusTurnCmd130 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusTurnCmd130 & dt)
    {
        os << to_json(dt);
        return os;
    }
}

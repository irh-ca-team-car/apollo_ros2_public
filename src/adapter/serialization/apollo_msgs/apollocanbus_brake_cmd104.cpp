#include "adapter/serialization/apollo_msgs/apollocanbus_brake_cmd104.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusBrakeCmd104 &msg) {
        nlohmann::json obj;
        obj["ignoreoverrides"] = (msg.ignoreoverrides);
        obj["enable"] = (msg.enable);
        obj["clearoverride"] = (msg.clearoverride);
        obj["clearfaults"] = (msg.clearfaults);
        obj["brakecmd"] = (msg.brakecmd);
        return obj;
    }
    ApollocanbusBrakeCmd104 from_json_ApollocanbusBrakeCmd104 (nlohmann::json obj) {
        ApollocanbusBrakeCmd104 msg;
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
        if(obj.contains("brakecmd"))
        {
            msg.brakecmd = (obj["brakecmd"].is_string()?atof(obj["brakecmd"].get<std::string>().c_str()):obj["brakecmd"].get<double>());
        }
        return msg;
    }
    template <>
    ApollocanbusBrakeCmd104 from_json<ApollocanbusBrakeCmd104>(nlohmann::json obj){
        return from_json_ApollocanbusBrakeCmd104(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusBrakeCmd104 &dt)
    {
        dt=from_json_ApollocanbusBrakeCmd104(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusBrakeCmd104 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusBrakeCmd104 & dt)
    {
        os << to_json(dt);
        return os;
    }
}

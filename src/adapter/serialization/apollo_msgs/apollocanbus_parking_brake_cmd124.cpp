#include "adapter/serialization/apollo_msgs/apollocanbus_parking_brake_cmd124.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusParkingBrakeCmd124 &msg) {
        nlohmann::json obj;
        obj["ignoreoverrides"] = (msg.ignoreoverrides);
        obj["enable"] = (msg.enable);
        obj["clearoverride"] = (msg.clearoverride);
        obj["parkingbrakecmd"] = (msg.parkingbrakecmd);
        obj["clearfaults"] = (msg.clearfaults);
        return obj;
    }
    ApollocanbusParkingBrakeCmd124 from_json_ApollocanbusParkingBrakeCmd124 (nlohmann::json obj) {
        ApollocanbusParkingBrakeCmd124 msg;
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
        if(obj.contains("parkingbrakecmd"))
        {
            msg.parkingbrakecmd = (obj["parkingbrakecmd"].is_string()?(bool)atoi(obj["parkingbrakecmd"].get<std::string>().c_str()):obj["parkingbrakecmd"].get<bool>());
        }
        if(obj.contains("clearfaults"))
        {
            msg.clearfaults = (obj["clearfaults"].is_string()?(bool)atoi(obj["clearfaults"].get<std::string>().c_str()):obj["clearfaults"].get<bool>());
        }
        return msg;
    }
    template <>
    ApollocanbusParkingBrakeCmd124 from_json<ApollocanbusParkingBrakeCmd124>(nlohmann::json obj){
        return from_json_ApollocanbusParkingBrakeCmd124(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusParkingBrakeCmd124 &dt)
    {
        dt=from_json_ApollocanbusParkingBrakeCmd124(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusParkingBrakeCmd124 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusParkingBrakeCmd124 & dt)
    {
        os << to_json(dt);
        return os;
    }
}

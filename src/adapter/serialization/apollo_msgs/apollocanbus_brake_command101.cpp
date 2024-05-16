#include "adapter/serialization/apollo_msgs/apollocanbus_brake_command101.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusBrakeCommand101 &msg) {
        nlohmann::json obj;
        obj["brakedec"] = (msg.brakedec);
        obj["checksum101"] = (msg.checksum101);
        obj["brakepedaltarget"] = (msg.brakepedaltarget);
        obj["brakeenctrl"] = (msg.brakeenctrl);
        obj["aebenctrl"] = (msg.aebenctrl);
        return obj;
    }
    ApollocanbusBrakeCommand101 from_json_ApollocanbusBrakeCommand101 (nlohmann::json obj) {
        ApollocanbusBrakeCommand101 msg;
        if(obj.contains("brakedec"))
        {
            msg.brakedec = (obj["brakedec"].is_string()?atof(obj["brakedec"].get<std::string>().c_str()):obj["brakedec"].get<double>());
        }
        if(obj.contains("checksum101"))
        {
            msg.checksum101 = (obj["checksum101"].is_string()?atoi(obj["checksum101"].get<std::string>().c_str()):obj["checksum101"].get<int>());
        }
        if(obj.contains("brakepedaltarget"))
        {
            msg.brakepedaltarget = (obj["brakepedaltarget"].is_string()?atof(obj["brakepedaltarget"].get<std::string>().c_str()):obj["brakepedaltarget"].get<double>());
        }
        if(obj.contains("brakeenctrl"))
        {
            msg.brakeenctrl = (obj["brakeenctrl"].is_string()?atoi(obj["brakeenctrl"].get<std::string>().c_str()):obj["brakeenctrl"].get<int>());
        }
        if(obj.contains("aebenctrl"))
        {
            msg.aebenctrl = (obj["aebenctrl"].is_string()?atoi(obj["aebenctrl"].get<std::string>().c_str()):obj["aebenctrl"].get<int>());
        }
        return msg;
    }
    template <>
    ApollocanbusBrakeCommand101 from_json<ApollocanbusBrakeCommand101>(nlohmann::json obj){
        return from_json_ApollocanbusBrakeCommand101(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusBrakeCommand101 &dt)
    {
        dt=from_json_ApollocanbusBrakeCommand101(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusBrakeCommand101 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusBrakeCommand101 & dt)
    {
        os << to_json(dt);
        return os;
    }
}

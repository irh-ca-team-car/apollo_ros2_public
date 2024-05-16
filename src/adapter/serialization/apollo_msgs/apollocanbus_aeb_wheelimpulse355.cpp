#include "adapter/serialization/apollo_msgs/apollocanbus_aeb_wheelimpulse355.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusAebWheelimpulse355 &msg) {
        nlohmann::json obj;
        obj["flimpulse"] = (msg.flimpulse);
        obj["flimpulsevalid"] = (msg.flimpulsevalid);
        obj["frimpulse"] = (msg.frimpulse);
        obj["frimpulsevalid"] = (msg.frimpulsevalid);
        obj["rlimpulse"] = (msg.rlimpulse);
        obj["rlimpulsevalid"] = (msg.rlimpulsevalid);
        obj["rrimpulse"] = (msg.rrimpulse);
        obj["rrimpulsevalid"] = (msg.rrimpulsevalid);
        obj["alivecounter"] = (msg.alivecounter);
        obj["checksum"] = (msg.checksum);
        return obj;
    }
    ApollocanbusAebWheelimpulse355 from_json_ApollocanbusAebWheelimpulse355 (nlohmann::json obj) {
        ApollocanbusAebWheelimpulse355 msg;
        if(obj.contains("flimpulse"))
        {
            msg.flimpulse = (obj["flimpulse"].is_string()?atof(obj["flimpulse"].get<std::string>().c_str()):obj["flimpulse"].get<double>());
        }
        if(obj.contains("flimpulsevalid"))
        {
            msg.flimpulsevalid = (obj["flimpulsevalid"].is_string()?(bool)atoi(obj["flimpulsevalid"].get<std::string>().c_str()):obj["flimpulsevalid"].get<bool>());
        }
        if(obj.contains("frimpulse"))
        {
            msg.frimpulse = (obj["frimpulse"].is_string()?atof(obj["frimpulse"].get<std::string>().c_str()):obj["frimpulse"].get<double>());
        }
        if(obj.contains("frimpulsevalid"))
        {
            msg.frimpulsevalid = (obj["frimpulsevalid"].is_string()?(bool)atoi(obj["frimpulsevalid"].get<std::string>().c_str()):obj["frimpulsevalid"].get<bool>());
        }
        if(obj.contains("rlimpulse"))
        {
            msg.rlimpulse = (obj["rlimpulse"].is_string()?atof(obj["rlimpulse"].get<std::string>().c_str()):obj["rlimpulse"].get<double>());
        }
        if(obj.contains("rlimpulsevalid"))
        {
            msg.rlimpulsevalid = (obj["rlimpulsevalid"].is_string()?(bool)atoi(obj["rlimpulsevalid"].get<std::string>().c_str()):obj["rlimpulsevalid"].get<bool>());
        }
        if(obj.contains("rrimpulse"))
        {
            msg.rrimpulse = (obj["rrimpulse"].is_string()?atof(obj["rrimpulse"].get<std::string>().c_str()):obj["rrimpulse"].get<double>());
        }
        if(obj.contains("rrimpulsevalid"))
        {
            msg.rrimpulsevalid = (obj["rrimpulsevalid"].is_string()?(bool)atoi(obj["rrimpulsevalid"].get<std::string>().c_str()):obj["rrimpulsevalid"].get<bool>());
        }
        if(obj.contains("alivecounter"))
        {
            msg.alivecounter = (obj["alivecounter"].is_string()?atof(obj["alivecounter"].get<std::string>().c_str()):obj["alivecounter"].get<double>());
        }
        if(obj.contains("checksum"))
        {
            msg.checksum = (obj["checksum"].is_string()?atof(obj["checksum"].get<std::string>().c_str()):obj["checksum"].get<double>());
        }
        return msg;
    }
    template <>
    ApollocanbusAebWheelimpulse355 from_json<ApollocanbusAebWheelimpulse355>(nlohmann::json obj){
        return from_json_ApollocanbusAebWheelimpulse355(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusAebWheelimpulse355 &dt)
    {
        dt=from_json_ApollocanbusAebWheelimpulse355(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusAebWheelimpulse355 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusAebWheelimpulse355 & dt)
    {
        os << to_json(dt);
        return os;
    }
}

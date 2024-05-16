#include "adapter/serialization/apollo_msgs/apollocanbus_steer_status512.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusSteerStatus512 &msg) {
        nlohmann::json obj;
        obj["steerangleensts"] = (msg.steerangleensts);
        obj["steeranglests"] = (msg.steeranglests);
        obj["steererr"] = (msg.steererr);
        obj["sensorerr"] = (msg.sensorerr);
        return obj;
    }
    ApollocanbusSteerStatus512 from_json_ApollocanbusSteerStatus512 (nlohmann::json obj) {
        ApollocanbusSteerStatus512 msg;
        if(obj.contains("steerangleensts"))
        {
            msg.steerangleensts = (obj["steerangleensts"].is_string()?atoi(obj["steerangleensts"].get<std::string>().c_str()):obj["steerangleensts"].get<int>());
        }
        if(obj.contains("steeranglests"))
        {
            msg.steeranglests = (obj["steeranglests"].is_string()?atof(obj["steeranglests"].get<std::string>().c_str()):obj["steeranglests"].get<double>());
        }
        if(obj.contains("steererr"))
        {
            msg.steererr = (obj["steererr"].is_string()?atoi(obj["steererr"].get<std::string>().c_str()):obj["steererr"].get<int>());
        }
        if(obj.contains("sensorerr"))
        {
            msg.sensorerr = (obj["sensorerr"].is_string()?atoi(obj["sensorerr"].get<std::string>().c_str()):obj["sensorerr"].get<int>());
        }
        return msg;
    }
    template <>
    ApollocanbusSteerStatus512 from_json<ApollocanbusSteerStatus512>(nlohmann::json obj){
        return from_json_ApollocanbusSteerStatus512(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusSteerStatus512 &dt)
    {
        dt=from_json_ApollocanbusSteerStatus512(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusSteerStatus512 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusSteerStatus512 & dt)
    {
        os << to_json(dt);
        return os;
    }
}

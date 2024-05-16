#include "adapter/serialization/apollo_msgs/apollocanbus_steering_cmd6d.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusSteeringCmd6d &msg) {
        nlohmann::json obj;
        obj["positionvalue"] = (msg.positionvalue);
        obj["speedlimit"] = (msg.speedlimit);
        return obj;
    }
    ApollocanbusSteeringCmd6d from_json_ApollocanbusSteeringCmd6d (nlohmann::json obj) {
        ApollocanbusSteeringCmd6d msg;
        if(obj.contains("positionvalue"))
        {
            msg.positionvalue = (obj["positionvalue"].is_string()?atof(obj["positionvalue"].get<std::string>().c_str()):obj["positionvalue"].get<double>());
        }
        if(obj.contains("speedlimit"))
        {
            msg.speedlimit = (obj["speedlimit"].is_string()?atof(obj["speedlimit"].get<std::string>().c_str()):obj["speedlimit"].get<double>());
        }
        return msg;
    }
    template <>
    ApollocanbusSteeringCmd6d from_json<ApollocanbusSteeringCmd6d>(nlohmann::json obj){
        return from_json_ApollocanbusSteeringCmd6d(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusSteeringCmd6d &dt)
    {
        dt=from_json_ApollocanbusSteeringCmd6d(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusSteeringCmd6d & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusSteeringCmd6d & dt)
    {
        os << to_json(dt);
        return os;
    }
}

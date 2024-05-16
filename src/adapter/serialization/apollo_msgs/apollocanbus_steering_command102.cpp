#include "adapter/serialization/apollo_msgs/apollocanbus_steering_command102.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusSteeringCommand102 &msg) {
        nlohmann::json obj;
        obj["steerenctrl"] = (msg.steerenctrl);
        obj["steerangletarget"] = (msg.steerangletarget);
        obj["steeranglespd"] = (msg.steeranglespd);
        obj["checksum102"] = (msg.checksum102);
        return obj;
    }
    ApollocanbusSteeringCommand102 from_json_ApollocanbusSteeringCommand102 (nlohmann::json obj) {
        ApollocanbusSteeringCommand102 msg;
        if(obj.contains("steerenctrl"))
        {
            msg.steerenctrl = (obj["steerenctrl"].is_string()?atoi(obj["steerenctrl"].get<std::string>().c_str()):obj["steerenctrl"].get<int>());
        }
        if(obj.contains("steerangletarget"))
        {
            msg.steerangletarget = (obj["steerangletarget"].is_string()?atoi(obj["steerangletarget"].get<std::string>().c_str()):obj["steerangletarget"].get<int>());
        }
        if(obj.contains("steeranglespd"))
        {
            msg.steeranglespd = (obj["steeranglespd"].is_string()?atoi(obj["steeranglespd"].get<std::string>().c_str()):obj["steeranglespd"].get<int>());
        }
        if(obj.contains("checksum102"))
        {
            msg.checksum102 = (obj["checksum102"].is_string()?atoi(obj["checksum102"].get<std::string>().c_str()):obj["checksum102"].get<int>());
        }
        return msg;
    }
    template <>
    ApollocanbusSteeringCommand102 from_json<ApollocanbusSteeringCommand102>(nlohmann::json obj){
        return from_json_ApollocanbusSteeringCommand102(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusSteeringCommand102 &dt)
    {
        dt=from_json_ApollocanbusSteeringCommand102(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusSteeringCommand102 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusSteeringCommand102 & dt)
    {
        os << to_json(dt);
        return os;
    }
}

#include "adapter/serialization/apollo_msgs/apollocanbus_steering_control_a2.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusSteeringControlA2 &msg) {
        nlohmann::json obj;
        obj["steeringtarget"] = (msg.steeringtarget);
        obj["steeringenablecontrol"] = (msg.steeringenablecontrol);
        return obj;
    }
    ApollocanbusSteeringControlA2 from_json_ApollocanbusSteeringControlA2 (nlohmann::json obj) {
        ApollocanbusSteeringControlA2 msg;
        if(obj.contains("steeringtarget"))
        {
            msg.steeringtarget = (obj["steeringtarget"].is_string()?atof(obj["steeringtarget"].get<std::string>().c_str()):obj["steeringtarget"].get<double>());
        }
        if(obj.contains("steeringenablecontrol"))
        {
            msg.steeringenablecontrol = (obj["steeringenablecontrol"].is_string()?atoi(obj["steeringenablecontrol"].get<std::string>().c_str()):obj["steeringenablecontrol"].get<int>());
        }
        return msg;
    }
    template <>
    ApollocanbusSteeringControlA2 from_json<ApollocanbusSteeringControlA2>(nlohmann::json obj){
        return from_json_ApollocanbusSteeringControlA2(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusSteeringControlA2 &dt)
    {
        dt=from_json_ApollocanbusSteeringControlA2(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusSteeringControlA2 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusSteeringControlA2 & dt)
    {
        os << to_json(dt);
        return os;
    }
}

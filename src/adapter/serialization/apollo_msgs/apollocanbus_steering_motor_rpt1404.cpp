#include "adapter/serialization/apollo_msgs/apollocanbus_steering_motor_rpt1404.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusSteeringMotorRpt1404 &msg) {
        nlohmann::json obj;
        obj["motorcurrent"] = (msg.motorcurrent);
        obj["shaftposition"] = (msg.shaftposition);
        return obj;
    }
    ApollocanbusSteeringMotorRpt1404 from_json_ApollocanbusSteeringMotorRpt1404 (nlohmann::json obj) {
        ApollocanbusSteeringMotorRpt1404 msg;
        if(obj.contains("motorcurrent"))
        {
            msg.motorcurrent = (obj["motorcurrent"].is_string()?atof(obj["motorcurrent"].get<std::string>().c_str()):obj["motorcurrent"].get<double>());
        }
        if(obj.contains("shaftposition"))
        {
            msg.shaftposition = (obj["shaftposition"].is_string()?atof(obj["shaftposition"].get<std::string>().c_str()):obj["shaftposition"].get<double>());
        }
        return msg;
    }
    template <>
    ApollocanbusSteeringMotorRpt1404 from_json<ApollocanbusSteeringMotorRpt1404>(nlohmann::json obj){
        return from_json_ApollocanbusSteeringMotorRpt1404(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusSteeringMotorRpt1404 &dt)
    {
        dt=from_json_ApollocanbusSteeringMotorRpt1404(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusSteeringMotorRpt1404 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusSteeringMotorRpt1404 & dt)
    {
        os << to_json(dt);
        return os;
    }
}

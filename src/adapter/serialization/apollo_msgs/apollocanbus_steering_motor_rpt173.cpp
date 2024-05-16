#include "adapter/serialization/apollo_msgs/apollocanbus_steering_motor_rpt173.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusSteeringMotorRpt173 &msg) {
        nlohmann::json obj;
        obj["motorcurrent"] = (msg.motorcurrent);
        obj["shaftposition"] = (msg.shaftposition);
        return obj;
    }
    ApollocanbusSteeringMotorRpt173 from_json_ApollocanbusSteeringMotorRpt173 (nlohmann::json obj) {
        ApollocanbusSteeringMotorRpt173 msg;
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
    ApollocanbusSteeringMotorRpt173 from_json<ApollocanbusSteeringMotorRpt173>(nlohmann::json obj){
        return from_json_ApollocanbusSteeringMotorRpt173(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusSteeringMotorRpt173 &dt)
    {
        dt=from_json_ApollocanbusSteeringMotorRpt173(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusSteeringMotorRpt173 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusSteeringMotorRpt173 & dt)
    {
        os << to_json(dt);
        return os;
    }
}

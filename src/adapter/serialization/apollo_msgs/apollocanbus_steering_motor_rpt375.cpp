#include "adapter/serialization/apollo_msgs/apollocanbus_steering_motor_rpt375.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusSteeringMotorRpt375 &msg) {
        nlohmann::json obj;
        obj["torqueoutput"] = (msg.torqueoutput);
        obj["torqueinput"] = (msg.torqueinput);
        return obj;
    }
    ApollocanbusSteeringMotorRpt375 from_json_ApollocanbusSteeringMotorRpt375 (nlohmann::json obj) {
        ApollocanbusSteeringMotorRpt375 msg;
        if(obj.contains("torqueoutput"))
        {
            msg.torqueoutput = (obj["torqueoutput"].is_string()?atof(obj["torqueoutput"].get<std::string>().c_str()):obj["torqueoutput"].get<double>());
        }
        if(obj.contains("torqueinput"))
        {
            msg.torqueinput = (obj["torqueinput"].is_string()?atof(obj["torqueinput"].get<std::string>().c_str()):obj["torqueinput"].get<double>());
        }
        return msg;
    }
    template <>
    ApollocanbusSteeringMotorRpt375 from_json<ApollocanbusSteeringMotorRpt375>(nlohmann::json obj){
        return from_json_ApollocanbusSteeringMotorRpt375(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusSteeringMotorRpt375 &dt)
    {
        dt=from_json_ApollocanbusSteeringMotorRpt375(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusSteeringMotorRpt375 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusSteeringMotorRpt375 & dt)
    {
        os << to_json(dt);
        return os;
    }
}

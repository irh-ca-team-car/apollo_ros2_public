#include "adapter/serialization/apollo_msgs/apollocanbus_steering_motor_rpt274.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusSteeringMotorRpt274 &msg) {
        nlohmann::json obj;
        obj["encodertemperature"] = (msg.encodertemperature);
        obj["motortemperature"] = (msg.motortemperature);
        obj["angularspeed"] = (msg.angularspeed);
        return obj;
    }
    ApollocanbusSteeringMotorRpt274 from_json_ApollocanbusSteeringMotorRpt274 (nlohmann::json obj) {
        ApollocanbusSteeringMotorRpt274 msg;
        if(obj.contains("encodertemperature"))
        {
            msg.encodertemperature = (obj["encodertemperature"].is_string()?atoi(obj["encodertemperature"].get<std::string>().c_str()):obj["encodertemperature"].get<int>());
        }
        if(obj.contains("motortemperature"))
        {
            msg.motortemperature = (obj["motortemperature"].is_string()?atoi(obj["motortemperature"].get<std::string>().c_str()):obj["motortemperature"].get<int>());
        }
        if(obj.contains("angularspeed"))
        {
            msg.angularspeed = (obj["angularspeed"].is_string()?atof(obj["angularspeed"].get<std::string>().c_str()):obj["angularspeed"].get<double>());
        }
        return msg;
    }
    template <>
    ApollocanbusSteeringMotorRpt274 from_json<ApollocanbusSteeringMotorRpt274>(nlohmann::json obj){
        return from_json_ApollocanbusSteeringMotorRpt274(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusSteeringMotorRpt274 &dt)
    {
        dt=from_json_ApollocanbusSteeringMotorRpt274(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusSteeringMotorRpt274 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusSteeringMotorRpt274 & dt)
    {
        os << to_json(dt);
        return os;
    }
}

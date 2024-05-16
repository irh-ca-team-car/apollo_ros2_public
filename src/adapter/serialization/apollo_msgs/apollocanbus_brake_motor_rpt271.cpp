#include "adapter/serialization/apollo_msgs/apollocanbus_brake_motor_rpt271.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusBrakeMotorRpt271 &msg) {
        nlohmann::json obj;
        obj["encodertemperature"] = (msg.encodertemperature);
        obj["motortemperature"] = (msg.motortemperature);
        obj["angularspeed"] = (msg.angularspeed);
        return obj;
    }
    ApollocanbusBrakeMotorRpt271 from_json_ApollocanbusBrakeMotorRpt271 (nlohmann::json obj) {
        ApollocanbusBrakeMotorRpt271 msg;
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
    ApollocanbusBrakeMotorRpt271 from_json<ApollocanbusBrakeMotorRpt271>(nlohmann::json obj){
        return from_json_ApollocanbusBrakeMotorRpt271(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusBrakeMotorRpt271 &dt)
    {
        dt=from_json_ApollocanbusBrakeMotorRpt271(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusBrakeMotorRpt271 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusBrakeMotorRpt271 & dt)
    {
        os << to_json(dt);
        return os;
    }
}

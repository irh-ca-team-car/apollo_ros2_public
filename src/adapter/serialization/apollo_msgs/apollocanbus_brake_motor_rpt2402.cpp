#include "adapter/serialization/apollo_msgs/apollocanbus_brake_motor_rpt2402.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusBrakeMotorRpt2402 &msg) {
        nlohmann::json obj;
        obj["encodertemperature"] = (msg.encodertemperature);
        obj["motortemperature"] = (msg.motortemperature);
        obj["angularspeed"] = (msg.angularspeed);
        return obj;
    }
    ApollocanbusBrakeMotorRpt2402 from_json_ApollocanbusBrakeMotorRpt2402 (nlohmann::json obj) {
        ApollocanbusBrakeMotorRpt2402 msg;
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
    ApollocanbusBrakeMotorRpt2402 from_json<ApollocanbusBrakeMotorRpt2402>(nlohmann::json obj){
        return from_json_ApollocanbusBrakeMotorRpt2402(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusBrakeMotorRpt2402 &dt)
    {
        dt=from_json_ApollocanbusBrakeMotorRpt2402(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusBrakeMotorRpt2402 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusBrakeMotorRpt2402 & dt)
    {
        os << to_json(dt);
        return os;
    }
}

#include "adapter/serialization/apollo_msgs/apollocanbus_brake_control_a4.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusBrakeControlA4 &msg) {
        nlohmann::json obj;
        obj["braketorque"] = (msg.braketorque);
        obj["brakeenablecontrol"] = (msg.brakeenablecontrol);
        return obj;
    }
    ApollocanbusBrakeControlA4 from_json_ApollocanbusBrakeControlA4 (nlohmann::json obj) {
        ApollocanbusBrakeControlA4 msg;
        if(obj.contains("braketorque"))
        {
            msg.braketorque = (obj["braketorque"].is_string()?atof(obj["braketorque"].get<std::string>().c_str()):obj["braketorque"].get<double>());
        }
        if(obj.contains("brakeenablecontrol"))
        {
            msg.brakeenablecontrol = (obj["brakeenablecontrol"].is_string()?atoi(obj["brakeenablecontrol"].get<std::string>().c_str()):obj["brakeenablecontrol"].get<int>());
        }
        return msg;
    }
    template <>
    ApollocanbusBrakeControlA4 from_json<ApollocanbusBrakeControlA4>(nlohmann::json obj){
        return from_json_ApollocanbusBrakeControlA4(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusBrakeControlA4 &dt)
    {
        dt=from_json_ApollocanbusBrakeControlA4(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusBrakeControlA4 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusBrakeControlA4 & dt)
    {
        os << to_json(dt);
        return os;
    }
}

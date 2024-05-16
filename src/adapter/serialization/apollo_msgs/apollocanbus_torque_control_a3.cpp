#include "adapter/serialization/apollo_msgs/apollocanbus_torque_control_a3.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusTorqueControlA3 &msg) {
        nlohmann::json obj;
        obj["driventorque"] = (msg.driventorque);
        obj["drivenenablecontrol"] = (msg.drivenenablecontrol);
        return obj;
    }
    ApollocanbusTorqueControlA3 from_json_ApollocanbusTorqueControlA3 (nlohmann::json obj) {
        ApollocanbusTorqueControlA3 msg;
        if(obj.contains("driventorque"))
        {
            msg.driventorque = (obj["driventorque"].is_string()?atof(obj["driventorque"].get<std::string>().c_str()):obj["driventorque"].get<double>());
        }
        if(obj.contains("drivenenablecontrol"))
        {
            msg.drivenenablecontrol = (obj["drivenenablecontrol"].is_string()?atoi(obj["drivenenablecontrol"].get<std::string>().c_str()):obj["drivenenablecontrol"].get<int>());
        }
        return msg;
    }
    template <>
    ApollocanbusTorqueControlA3 from_json<ApollocanbusTorqueControlA3>(nlohmann::json obj){
        return from_json_ApollocanbusTorqueControlA3(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusTorqueControlA3 &dt)
    {
        dt=from_json_ApollocanbusTorqueControlA3(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusTorqueControlA3 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusTorqueControlA3 & dt)
    {
        os << to_json(dt);
        return os;
    }
}

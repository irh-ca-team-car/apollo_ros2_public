#include "adapter/serialization/apollo_msgs/apollocanbus_brake_motor_rpt1401.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusBrakeMotorRpt1401 &msg) {
        nlohmann::json obj;
        obj["motorcurrent"] = (msg.motorcurrent);
        obj["shaftposition"] = (msg.shaftposition);
        return obj;
    }
    ApollocanbusBrakeMotorRpt1401 from_json_ApollocanbusBrakeMotorRpt1401 (nlohmann::json obj) {
        ApollocanbusBrakeMotorRpt1401 msg;
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
    ApollocanbusBrakeMotorRpt1401 from_json<ApollocanbusBrakeMotorRpt1401>(nlohmann::json obj){
        return from_json_ApollocanbusBrakeMotorRpt1401(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusBrakeMotorRpt1401 &dt)
    {
        dt=from_json_ApollocanbusBrakeMotorRpt1401(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusBrakeMotorRpt1401 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusBrakeMotorRpt1401 & dt)
    {
        os << to_json(dt);
        return os;
    }
}

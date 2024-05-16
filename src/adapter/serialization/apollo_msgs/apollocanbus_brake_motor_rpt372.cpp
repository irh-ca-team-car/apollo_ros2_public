#include "adapter/serialization/apollo_msgs/apollocanbus_brake_motor_rpt372.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusBrakeMotorRpt372 &msg) {
        nlohmann::json obj;
        obj["torqueoutput"] = (msg.torqueoutput);
        obj["torqueinput"] = (msg.torqueinput);
        return obj;
    }
    ApollocanbusBrakeMotorRpt372 from_json_ApollocanbusBrakeMotorRpt372 (nlohmann::json obj) {
        ApollocanbusBrakeMotorRpt372 msg;
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
    ApollocanbusBrakeMotorRpt372 from_json<ApollocanbusBrakeMotorRpt372>(nlohmann::json obj){
        return from_json_ApollocanbusBrakeMotorRpt372(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusBrakeMotorRpt372 &dt)
    {
        dt=from_json_ApollocanbusBrakeMotorRpt372(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusBrakeMotorRpt372 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusBrakeMotorRpt372 & dt)
    {
        os << to_json(dt);
        return os;
    }
}

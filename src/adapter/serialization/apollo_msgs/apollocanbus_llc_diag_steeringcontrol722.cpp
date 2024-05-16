#include "adapter/serialization/apollo_msgs/apollocanbus_llc_diag_steeringcontrol722.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusLlcDiagSteeringcontrol722 &msg) {
        nlohmann::json obj;
        obj["llcdbgsteeringsensorposition"] = (msg.llcdbgsteeringsensorposition);
        obj["llcdbgsteeringrackinputtorque"] = (msg.llcdbgsteeringrackinputtorque);
        obj["llcdbgsteeringmotorposition"] = (msg.llcdbgsteeringmotorposition);
        return obj;
    }
    ApollocanbusLlcDiagSteeringcontrol722 from_json_ApollocanbusLlcDiagSteeringcontrol722 (nlohmann::json obj) {
        ApollocanbusLlcDiagSteeringcontrol722 msg;
        if(obj.contains("llcdbgsteeringsensorposition"))
        {
            msg.llcdbgsteeringsensorposition = (obj["llcdbgsteeringsensorposition"].is_string()?atof(obj["llcdbgsteeringsensorposition"].get<std::string>().c_str()):obj["llcdbgsteeringsensorposition"].get<double>());
        }
        if(obj.contains("llcdbgsteeringrackinputtorque"))
        {
            msg.llcdbgsteeringrackinputtorque = (obj["llcdbgsteeringrackinputtorque"].is_string()?atoi(obj["llcdbgsteeringrackinputtorque"].get<std::string>().c_str()):obj["llcdbgsteeringrackinputtorque"].get<int>());
        }
        if(obj.contains("llcdbgsteeringmotorposition"))
        {
            msg.llcdbgsteeringmotorposition = (obj["llcdbgsteeringmotorposition"].is_string()?atof(obj["llcdbgsteeringmotorposition"].get<std::string>().c_str()):obj["llcdbgsteeringmotorposition"].get<double>());
        }
        return msg;
    }
    template <>
    ApollocanbusLlcDiagSteeringcontrol722 from_json<ApollocanbusLlcDiagSteeringcontrol722>(nlohmann::json obj){
        return from_json_ApollocanbusLlcDiagSteeringcontrol722(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusLlcDiagSteeringcontrol722 &dt)
    {
        dt=from_json_ApollocanbusLlcDiagSteeringcontrol722(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusLlcDiagSteeringcontrol722 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusLlcDiagSteeringcontrol722 & dt)
    {
        os << to_json(dt);
        return os;
    }
}

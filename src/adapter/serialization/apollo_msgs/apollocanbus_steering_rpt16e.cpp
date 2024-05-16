#include "adapter/serialization/apollo_msgs/apollocanbus_steering_rpt16e.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusSteeringRpt16e &msg) {
        nlohmann::json obj;
        obj["manualinput"] = (msg.manualinput);
        obj["commandedvalue"] = (msg.commandedvalue);
        obj["outputvalue"] = (msg.outputvalue);
        return obj;
    }
    ApollocanbusSteeringRpt16e from_json_ApollocanbusSteeringRpt16e (nlohmann::json obj) {
        ApollocanbusSteeringRpt16e msg;
        if(obj.contains("manualinput"))
        {
            msg.manualinput = (obj["manualinput"].is_string()?atof(obj["manualinput"].get<std::string>().c_str()):obj["manualinput"].get<double>());
        }
        if(obj.contains("commandedvalue"))
        {
            msg.commandedvalue = (obj["commandedvalue"].is_string()?atof(obj["commandedvalue"].get<std::string>().c_str()):obj["commandedvalue"].get<double>());
        }
        if(obj.contains("outputvalue"))
        {
            msg.outputvalue = (obj["outputvalue"].is_string()?atof(obj["outputvalue"].get<std::string>().c_str()):obj["outputvalue"].get<double>());
        }
        return msg;
    }
    template <>
    ApollocanbusSteeringRpt16e from_json<ApollocanbusSteeringRpt16e>(nlohmann::json obj){
        return from_json_ApollocanbusSteeringRpt16e(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusSteeringRpt16e &dt)
    {
        dt=from_json_ApollocanbusSteeringRpt16e(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusSteeringRpt16e & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusSteeringRpt16e & dt)
    {
        os << to_json(dt);
        return os;
    }
}

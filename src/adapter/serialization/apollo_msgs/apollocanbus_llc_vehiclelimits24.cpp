#include "adapter/serialization/apollo_msgs/apollocanbus_llc_vehiclelimits24.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusLlcVehiclelimits24 &msg) {
        nlohmann::json obj;
        obj["llcfbkmaxsteeringangle"] = (msg.llcfbkmaxsteeringangle);
        obj["llcfbkmaxbrakepercent"] = (msg.llcfbkmaxbrakepercent);
        return obj;
    }
    ApollocanbusLlcVehiclelimits24 from_json_ApollocanbusLlcVehiclelimits24 (nlohmann::json obj) {
        ApollocanbusLlcVehiclelimits24 msg;
        if(obj.contains("llcfbkmaxsteeringangle"))
        {
            msg.llcfbkmaxsteeringangle = (obj["llcfbkmaxsteeringangle"].is_string()?atoi(obj["llcfbkmaxsteeringangle"].get<std::string>().c_str()):obj["llcfbkmaxsteeringangle"].get<int>());
        }
        if(obj.contains("llcfbkmaxbrakepercent"))
        {
            msg.llcfbkmaxbrakepercent = (obj["llcfbkmaxbrakepercent"].is_string()?atof(obj["llcfbkmaxbrakepercent"].get<std::string>().c_str()):obj["llcfbkmaxbrakepercent"].get<double>());
        }
        return msg;
    }
    template <>
    ApollocanbusLlcVehiclelimits24 from_json<ApollocanbusLlcVehiclelimits24>(nlohmann::json obj){
        return from_json_ApollocanbusLlcVehiclelimits24(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusLlcVehiclelimits24 &dt)
    {
        dt=from_json_ApollocanbusLlcVehiclelimits24(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusLlcVehiclelimits24 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusLlcVehiclelimits24 & dt)
    {
        os << to_json(dt);
        return os;
    }
}

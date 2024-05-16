#include "adapter/serialization/apollo_msgs/apollocanbus_veh_dynamics_rpt413.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusVehDynamicsRpt413 &msg) {
        nlohmann::json obj;
        obj["vehgforces"] = (msg.vehgforces);
        return obj;
    }
    ApollocanbusVehDynamicsRpt413 from_json_ApollocanbusVehDynamicsRpt413 (nlohmann::json obj) {
        ApollocanbusVehDynamicsRpt413 msg;
        if(obj.contains("vehgforces"))
        {
            msg.vehgforces = (obj["vehgforces"].is_string()?atof(obj["vehgforces"].get<std::string>().c_str()):obj["vehgforces"].get<double>());
        }
        return msg;
    }
    template <>
    ApollocanbusVehDynamicsRpt413 from_json<ApollocanbusVehDynamicsRpt413>(nlohmann::json obj){
        return from_json_ApollocanbusVehDynamicsRpt413(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusVehDynamicsRpt413 &dt)
    {
        dt=from_json_ApollocanbusVehDynamicsRpt413(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusVehDynamicsRpt413 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusVehDynamicsRpt413 & dt)
    {
        os << to_json(dt);
        return os;
    }
}

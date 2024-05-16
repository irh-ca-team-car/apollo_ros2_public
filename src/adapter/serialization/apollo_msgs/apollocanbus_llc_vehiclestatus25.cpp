#include "adapter/serialization/apollo_msgs/apollocanbus_llc_vehiclestatus25.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusLlcVehiclestatus25 &msg) {
        nlohmann::json obj;
        obj["llcfbk12voltage"] = (msg.llcfbk12voltage);
        return obj;
    }
    ApollocanbusLlcVehiclestatus25 from_json_ApollocanbusLlcVehiclestatus25 (nlohmann::json obj) {
        ApollocanbusLlcVehiclestatus25 msg;
        if(obj.contains("llcfbk12voltage"))
        {
            msg.llcfbk12voltage = (obj["llcfbk12voltage"].is_string()?atof(obj["llcfbk12voltage"].get<std::string>().c_str()):obj["llcfbk12voltage"].get<double>());
        }
        return msg;
    }
    template <>
    ApollocanbusLlcVehiclestatus25 from_json<ApollocanbusLlcVehiclestatus25>(nlohmann::json obj){
        return from_json_ApollocanbusLlcVehiclestatus25(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusLlcVehiclestatus25 &dt)
    {
        dt=from_json_ApollocanbusLlcVehiclestatus25(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusLlcVehiclestatus25 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusLlcVehiclestatus25 & dt)
    {
        os << to_json(dt);
        return os;
    }
}

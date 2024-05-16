#include "adapter/serialization/apollo_msgs/apollocanbus_vehicle_speed_rpt400.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusVehicleSpeedRpt400 &msg) {
        nlohmann::json obj;
        obj["vehiclespeed"] = (msg.vehiclespeed);
        obj["vehiclespeedvalid"] = (msg.vehiclespeedvalid);
        return obj;
    }
    ApollocanbusVehicleSpeedRpt400 from_json_ApollocanbusVehicleSpeedRpt400 (nlohmann::json obj) {
        ApollocanbusVehicleSpeedRpt400 msg;
        if(obj.contains("vehiclespeed"))
        {
            msg.vehiclespeed = (obj["vehiclespeed"].is_string()?atof(obj["vehiclespeed"].get<std::string>().c_str()):obj["vehiclespeed"].get<double>());
        }
        if(obj.contains("vehiclespeedvalid"))
        {
            msg.vehiclespeedvalid = (obj["vehiclespeedvalid"].is_string()?atoi(obj["vehiclespeedvalid"].get<std::string>().c_str()):obj["vehiclespeedvalid"].get<int>());
        }
        return msg;
    }
    template <>
    ApollocanbusVehicleSpeedRpt400 from_json<ApollocanbusVehicleSpeedRpt400>(nlohmann::json obj){
        return from_json_ApollocanbusVehicleSpeedRpt400(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusVehicleSpeedRpt400 &dt)
    {
        dt=from_json_ApollocanbusVehicleSpeedRpt400(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusVehicleSpeedRpt400 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusVehicleSpeedRpt400 & dt)
    {
        os << to_json(dt);
        return os;
    }
}

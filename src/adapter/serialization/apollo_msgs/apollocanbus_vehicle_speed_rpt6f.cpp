#include "adapter/serialization/apollo_msgs/apollocanbus_vehicle_speed_rpt6f.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusVehicleSpeedRpt6f &msg) {
        nlohmann::json obj;
        obj["vehiclespeed"] = (msg.vehiclespeed);
        obj["vehiclespeedvalid"] = (msg.vehiclespeedvalid);
        return obj;
    }
    ApollocanbusVehicleSpeedRpt6f from_json_ApollocanbusVehicleSpeedRpt6f (nlohmann::json obj) {
        ApollocanbusVehicleSpeedRpt6f msg;
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
    ApollocanbusVehicleSpeedRpt6f from_json<ApollocanbusVehicleSpeedRpt6f>(nlohmann::json obj){
        return from_json_ApollocanbusVehicleSpeedRpt6f(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusVehicleSpeedRpt6f &dt)
    {
        dt=from_json_ApollocanbusVehicleSpeedRpt6f(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusVehicleSpeedRpt6f & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusVehicleSpeedRpt6f & dt)
    {
        os << to_json(dt);
        return os;
    }
}

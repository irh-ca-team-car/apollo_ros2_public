#include "adapter/serialization/apollo_msgs/apollocanbus_vcu_vehicle_info_response502.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusVcuVehicleInfoResponse502 &msg) {
        nlohmann::json obj;
        obj["vehiclesoftwareversionindicati"] = (msg.vehiclesoftwareversionindicati);
        obj["project"] = (msg.project);
        obj["manufacturer"] = (msg.manufacturer);
        obj["year"] = (msg.year);
        obj["month"] = (msg.month);
        obj["day"] = (msg.day);
        obj["vehicleserialnumber"] = (msg.vehicleserialnumber);
        return obj;
    }
    ApollocanbusVcuVehicleInfoResponse502 from_json_ApollocanbusVcuVehicleInfoResponse502 (nlohmann::json obj) {
        ApollocanbusVcuVehicleInfoResponse502 msg;
        if(obj.contains("vehiclesoftwareversionindicati"))
        {
            msg.vehiclesoftwareversionindicati = (obj["vehiclesoftwareversionindicati"].is_string()?atoi(obj["vehiclesoftwareversionindicati"].get<std::string>().c_str()):obj["vehiclesoftwareversionindicati"].get<int>());
        }
        if(obj.contains("project"))
        {
            msg.project = (obj["project"].is_string()?atoi(obj["project"].get<std::string>().c_str()):obj["project"].get<int>());
        }
        if(obj.contains("manufacturer"))
        {
            msg.manufacturer = (obj["manufacturer"].is_string()?atoi(obj["manufacturer"].get<std::string>().c_str()):obj["manufacturer"].get<int>());
        }
        if(obj.contains("year"))
        {
            msg.year = (obj["year"].is_string()?atoi(obj["year"].get<std::string>().c_str()):obj["year"].get<int>());
        }
        if(obj.contains("month"))
        {
            msg.month = (obj["month"].is_string()?atoi(obj["month"].get<std::string>().c_str()):obj["month"].get<int>());
        }
        if(obj.contains("day"))
        {
            msg.day = (obj["day"].is_string()?atoi(obj["day"].get<std::string>().c_str()):obj["day"].get<int>());
        }
        if(obj.contains("vehicleserialnumber"))
        {
            msg.vehicleserialnumber = (obj["vehicleserialnumber"].is_string()?atoi(obj["vehicleserialnumber"].get<std::string>().c_str()):obj["vehicleserialnumber"].get<int>());
        }
        return msg;
    }
    template <>
    ApollocanbusVcuVehicleInfoResponse502 from_json<ApollocanbusVcuVehicleInfoResponse502>(nlohmann::json obj){
        return from_json_ApollocanbusVcuVehicleInfoResponse502(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusVcuVehicleInfoResponse502 &dt)
    {
        dt=from_json_ApollocanbusVcuVehicleInfoResponse502(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusVcuVehicleInfoResponse502 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusVcuVehicleInfoResponse502 & dt)
    {
        os << to_json(dt);
        return os;
    }
}

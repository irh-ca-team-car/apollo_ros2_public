#include "adapter/serialization/apollo_msgs/apollocanbus_vehicle_parameter.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusVehicleParameter &msg) {
        nlohmann::json obj;
        obj["brand"] = (msg.brand);
        obj["maxenginepedal"] = (msg.maxenginepedal);
        obj["maxenablefailattempt"] = (msg.maxenablefailattempt);
        obj["drivingmode"] = (msg.drivingmode);
        return obj;
    }
    ApollocanbusVehicleParameter from_json_ApollocanbusVehicleParameter (nlohmann::json obj) {
        ApollocanbusVehicleParameter msg;
        if(obj.contains("brand"))
        {
            msg.brand = (obj["brand"].is_string()?atoi(obj["brand"].get<std::string>().c_str()):obj["brand"].get<int>());
        }
        if(obj.contains("maxenginepedal"))
        {
            msg.maxenginepedal = (obj["maxenginepedal"].is_string()?atof(obj["maxenginepedal"].get<std::string>().c_str()):obj["maxenginepedal"].get<double>());
        }
        if(obj.contains("maxenablefailattempt"))
        {
            msg.maxenablefailattempt = (obj["maxenablefailattempt"].is_string()?atoi(obj["maxenablefailattempt"].get<std::string>().c_str()):obj["maxenablefailattempt"].get<int>());
        }
        if(obj.contains("drivingmode"))
        {
            msg.drivingmode = (obj["drivingmode"].is_string()?atoi(obj["drivingmode"].get<std::string>().c_str()):obj["drivingmode"].get<int>());
        }
        return msg;
    }
    template <>
    ApollocanbusVehicleParameter from_json<ApollocanbusVehicleParameter>(nlohmann::json obj){
        return from_json_ApollocanbusVehicleParameter(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusVehicleParameter &dt)
    {
        dt=from_json_ApollocanbusVehicleParameter(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusVehicleParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusVehicleParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
}

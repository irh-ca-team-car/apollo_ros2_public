#include "adapter/serialization/apollo_msgs/apollocommon_vehicle_id.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocommonVehicleID &msg) {
        nlohmann::json obj;
        obj["vin"] = (msg.vin);
        obj["plate"] = (msg.plate);
        obj["otheruniqueid"] = (msg.otheruniqueid);
        return obj;
    }
    ApollocommonVehicleID from_json_ApollocommonVehicleID (nlohmann::json obj) {
        ApollocommonVehicleID msg;
        if(obj.contains("vin"))
        {
            msg.vin = (obj["vin"].is_string()?(obj["vin"].get<std::string>().c_str()):obj["vin"].get<std::string>());
        }
        if(obj.contains("plate"))
        {
            msg.plate = (obj["plate"].is_string()?(obj["plate"].get<std::string>().c_str()):obj["plate"].get<std::string>());
        }
        if(obj.contains("otheruniqueid"))
        {
            msg.otheruniqueid = (obj["otheruniqueid"].is_string()?(obj["otheruniqueid"].get<std::string>().c_str()):obj["otheruniqueid"].get<std::string>());
        }
        return msg;
    }
    template <>
    ApollocommonVehicleID from_json<ApollocommonVehicleID>(nlohmann::json obj){
        return from_json_ApollocommonVehicleID(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocommonVehicleID &dt)
    {
        dt=from_json_ApollocommonVehicleID(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocommonVehicleID & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocommonVehicleID & dt)
    {
        os << to_json(dt);
        return os;
    }
}

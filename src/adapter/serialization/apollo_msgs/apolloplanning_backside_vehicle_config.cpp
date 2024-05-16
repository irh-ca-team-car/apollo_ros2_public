#include "adapter/serialization/apollo_msgs/apolloplanning_backside_vehicle_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningBacksideVehicleConfig &msg) {
        nlohmann::json obj;
        obj["backsidelanewidth"] = (msg.backsidelanewidth);
        return obj;
    }
    ApolloplanningBacksideVehicleConfig from_json_ApolloplanningBacksideVehicleConfig (nlohmann::json obj) {
        ApolloplanningBacksideVehicleConfig msg;
        if(obj.contains("backsidelanewidth"))
        {
            msg.backsidelanewidth = (obj["backsidelanewidth"].is_string()?atof(obj["backsidelanewidth"].get<std::string>().c_str()):obj["backsidelanewidth"].get<double>());
        }
        return msg;
    }
    template <>
    ApolloplanningBacksideVehicleConfig from_json<ApolloplanningBacksideVehicleConfig>(nlohmann::json obj){
        return from_json_ApolloplanningBacksideVehicleConfig(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningBacksideVehicleConfig &dt)
    {
        dt=from_json_ApolloplanningBacksideVehicleConfig(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningBacksideVehicleConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningBacksideVehicleConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
}

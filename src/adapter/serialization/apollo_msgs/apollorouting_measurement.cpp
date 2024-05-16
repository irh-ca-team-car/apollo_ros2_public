#include "adapter/serialization/apollo_msgs/apollorouting_measurement.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloroutingMeasurement &msg) {
        nlohmann::json obj;
        obj["distance"] = (msg.distance);
        return obj;
    }
    ApolloroutingMeasurement from_json_ApolloroutingMeasurement (nlohmann::json obj) {
        ApolloroutingMeasurement msg;
        if(obj.contains("distance"))
        {
            msg.distance = (obj["distance"].is_string()?atof(obj["distance"].get<std::string>().c_str()):obj["distance"].get<double>());
        }
        return msg;
    }
    template <>
    ApolloroutingMeasurement from_json<ApolloroutingMeasurement>(nlohmann::json obj){
        return from_json_ApolloroutingMeasurement(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloroutingMeasurement &dt)
    {
        dt=from_json_ApolloroutingMeasurement(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloroutingMeasurement & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloroutingMeasurement & dt)
    {
        os << to_json(dt);
        return os;
    }
}

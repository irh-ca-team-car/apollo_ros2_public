#include "adapter/serialization/apollo_msgs/apollorouting_curve_point.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloroutingCurvePoint &msg) {
        nlohmann::json obj;
        obj["s"] = (msg.s);
        return obj;
    }
    ApolloroutingCurvePoint from_json_ApolloroutingCurvePoint (nlohmann::json obj) {
        ApolloroutingCurvePoint msg;
        if(obj.contains("s"))
        {
            msg.s = (obj["s"].is_string()?atof(obj["s"].get<std::string>().c_str()):obj["s"].get<double>());
        }
        return msg;
    }
    template <>
    ApolloroutingCurvePoint from_json<ApolloroutingCurvePoint>(nlohmann::json obj){
        return from_json_ApolloroutingCurvePoint(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloroutingCurvePoint &dt)
    {
        dt=from_json_ApolloroutingCurvePoint(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloroutingCurvePoint & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloroutingCurvePoint & dt)
    {
        os << to_json(dt);
        return os;
    }
}

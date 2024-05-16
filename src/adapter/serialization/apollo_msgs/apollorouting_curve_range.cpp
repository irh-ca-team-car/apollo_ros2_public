#include "adapter/serialization/apollo_msgs/apollorouting_curve_range.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloroutingCurveRange &msg) {
        nlohmann::json obj;
        obj["start"] = to_json(msg.start);
        obj["end"] = to_json(msg.end);
        return obj;
    }
    ApolloroutingCurveRange from_json_ApolloroutingCurveRange (nlohmann::json obj) {
        ApolloroutingCurveRange msg;
        if(obj.contains("start"))
        {
            msg.start = from_json_ApolloroutingCurvePoint(obj["start"]);
        }
        if(obj.contains("end"))
        {
            msg.end = from_json_ApolloroutingCurvePoint(obj["end"]);
        }
        return msg;
    }
    template <>
    ApolloroutingCurveRange from_json<ApolloroutingCurveRange>(nlohmann::json obj){
        return from_json_ApolloroutingCurveRange(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloroutingCurveRange &dt)
    {
        dt=from_json_ApolloroutingCurveRange(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloroutingCurveRange & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloroutingCurveRange & dt)
    {
        os << to_json(dt);
        return os;
    }
}

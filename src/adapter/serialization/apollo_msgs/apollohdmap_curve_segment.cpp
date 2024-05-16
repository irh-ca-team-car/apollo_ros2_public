#include "adapter/serialization/apollo_msgs/apollohdmap_curve_segment.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollohdmapCurveSegment &msg) {
        nlohmann::json obj;
        obj["curvetype"] = to_json(msg.curvetype);
        obj["s"] = (msg.s);
        obj["startposition"] = to_json(msg.startposition);
        obj["heading"] = (msg.heading);
        obj["length"] = (msg.length);
        return obj;
    }
    ApollohdmapCurveSegment from_json_ApollohdmapCurveSegment (nlohmann::json obj) {
        ApollohdmapCurveSegment msg;
        if(obj.contains("curvetype"))
        {
            msg.curvetype = from_json_ApollohdmapCurveSegmentcurveType(obj["curvetype"]);
        }
        if(obj.contains("s"))
        {
            msg.s = (obj["s"].is_string()?atof(obj["s"].get<std::string>().c_str()):obj["s"].get<double>());
        }
        if(obj.contains("startposition"))
        {
            msg.startposition = from_json_ApollocommonPointENU(obj["startposition"]);
        }
        if(obj.contains("heading"))
        {
            msg.heading = (obj["heading"].is_string()?atof(obj["heading"].get<std::string>().c_str()):obj["heading"].get<double>());
        }
        if(obj.contains("length"))
        {
            msg.length = (obj["length"].is_string()?atof(obj["length"].get<std::string>().c_str()):obj["length"].get<double>());
        }
        return msg;
    }
    template <>
    ApollohdmapCurveSegment from_json<ApollohdmapCurveSegment>(nlohmann::json obj){
        return from_json_ApollohdmapCurveSegment(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollohdmapCurveSegment &dt)
    {
        dt=from_json_ApollohdmapCurveSegment(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollohdmapCurveSegment & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollohdmapCurveSegment & dt)
    {
        os << to_json(dt);
        return os;
    }
}

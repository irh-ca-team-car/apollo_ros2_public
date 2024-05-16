#include "adapter/serialization/apollo_msgs/apollohdmap_curve_segmentcurve_type.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollohdmapCurveSegmentcurveType &msg) {
        nlohmann::json obj;
        obj["linesegment"] = to_json(msg.linesegment);
        return obj;
    }
    ApollohdmapCurveSegmentcurveType from_json_ApollohdmapCurveSegmentcurveType (nlohmann::json obj) {
        ApollohdmapCurveSegmentcurveType msg;
        if(obj.contains("linesegment"))
        {
            msg.linesegment = from_json_ApollohdmapLineSegment(obj["linesegment"]);
        }
        return msg;
    }
    template <>
    ApollohdmapCurveSegmentcurveType from_json<ApollohdmapCurveSegmentcurveType>(nlohmann::json obj){
        return from_json_ApollohdmapCurveSegmentcurveType(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollohdmapCurveSegmentcurveType &dt)
    {
        dt=from_json_ApollohdmapCurveSegmentcurveType(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollohdmapCurveSegmentcurveType & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollohdmapCurveSegmentcurveType & dt)
    {
        os << to_json(dt);
        return os;
    }
}

#include "adapter/serialization/apollo_msgs/apollohdmap_curve.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollohdmapCurve &msg) {
        nlohmann::json obj;
        nlohmann::json arr_segment;
        for (auto it = msg.segment.begin(); it != msg.segment.end(); ++it) {
            arr_segment.push_back(to_json(*it));
        }
        obj["segment"] = arr_segment;
        return obj;
    }
    ApollohdmapCurve from_json_ApollohdmapCurve (nlohmann::json obj) {
        ApollohdmapCurve msg;
        if(obj.contains("segment"))
        {
            if(obj["segment"].is_array())
            {
                for (auto& element : obj["segment"])
                {
                    msg.segment.push_back(from_json_ApollohdmapCurveSegment(element));
                }
            }
            else
            {
                msg.segment.push_back(from_json_ApollohdmapCurveSegment(obj["segment"]));
            }
        }
        return msg;
    }
    template <>
    ApollohdmapCurve from_json<ApollohdmapCurve>(nlohmann::json obj){
        return from_json_ApollohdmapCurve(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollohdmapCurve &dt)
    {
        dt=from_json_ApollohdmapCurve(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollohdmapCurve & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollohdmapCurve & dt)
    {
        os << to_json(dt);
        return os;
    }
}

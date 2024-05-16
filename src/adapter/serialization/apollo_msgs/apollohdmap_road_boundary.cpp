#include "adapter/serialization/apollo_msgs/apollohdmap_road_boundary.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollohdmapRoadBoundary &msg) {
        nlohmann::json obj;
        obj["outerpolygon"] = to_json(msg.outerpolygon);
        nlohmann::json arr_hole;
        for (auto it = msg.hole.begin(); it != msg.hole.end(); ++it) {
            arr_hole.push_back(to_json(*it));
        }
        obj["hole"] = arr_hole;
        return obj;
    }
    ApollohdmapRoadBoundary from_json_ApollohdmapRoadBoundary (nlohmann::json obj) {
        ApollohdmapRoadBoundary msg;
        if(obj.contains("outerpolygon"))
        {
            msg.outerpolygon = from_json_ApollohdmapBoundaryPolygon(obj["outerpolygon"]);
        }
        if(obj.contains("hole"))
        {
            if(obj["hole"].is_array())
            {
                for (auto& element : obj["hole"])
                {
                    msg.hole.push_back(from_json_ApollohdmapBoundaryPolygon(element));
                }
            }
            else
            {
                msg.hole.push_back(from_json_ApollohdmapBoundaryPolygon(obj["hole"]));
            }
        }
        return msg;
    }
    template <>
    ApollohdmapRoadBoundary from_json<ApollohdmapRoadBoundary>(nlohmann::json obj){
        return from_json_ApollohdmapRoadBoundary(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollohdmapRoadBoundary &dt)
    {
        dt=from_json_ApollohdmapRoadBoundary(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollohdmapRoadBoundary & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollohdmapRoadBoundary & dt)
    {
        os << to_json(dt);
        return os;
    }
}

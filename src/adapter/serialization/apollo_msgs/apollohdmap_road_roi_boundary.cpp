#include "adapter/serialization/apollo_msgs/apollohdmap_road_roi_boundary.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollohdmapRoadROIBoundary &msg) {
        nlohmann::json obj;
        obj["id"] = to_json(msg.id);
        nlohmann::json arr_roadboundaries;
        for (auto it = msg.roadboundaries.begin(); it != msg.roadboundaries.end(); ++it) {
            arr_roadboundaries.push_back(to_json(*it));
        }
        obj["roadboundaries"] = arr_roadboundaries;
        return obj;
    }
    ApollohdmapRoadROIBoundary from_json_ApollohdmapRoadROIBoundary (nlohmann::json obj) {
        ApollohdmapRoadROIBoundary msg;
        if(obj.contains("id"))
        {
            msg.id = from_json_ApollohdmapId(obj["id"]);
        }
        if(obj.contains("roadboundaries"))
        {
            if(obj["roadboundaries"].is_array())
            {
                for (auto& element : obj["roadboundaries"])
                {
                    msg.roadboundaries.push_back(from_json_ApollohdmapRoadBoundary(element));
                }
            }
            else
            {
                msg.roadboundaries.push_back(from_json_ApollohdmapRoadBoundary(obj["roadboundaries"]));
            }
        }
        return msg;
    }
    template <>
    ApollohdmapRoadROIBoundary from_json<ApollohdmapRoadROIBoundary>(nlohmann::json obj){
        return from_json_ApollohdmapRoadROIBoundary(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollohdmapRoadROIBoundary &dt)
    {
        dt=from_json_ApollohdmapRoadROIBoundary(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollohdmapRoadROIBoundary & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollohdmapRoadROIBoundary & dt)
    {
        os << to_json(dt);
        return os;
    }
}

#include "adapter/serialization/apollo_msgs/apollodbmap_db_neighbour_path.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodbmapDBNeighbourPath &msg) {
        nlohmann::json obj;
        nlohmann::json arr_segment;
        for (auto it = msg.segment.begin(); it != msg.segment.end(); ++it) {
            arr_segment.push_back(to_json(*it));
        }
        obj["segment"] = arr_segment;
        return obj;
    }
    ApollodbmapDBNeighbourPath from_json_ApollodbmapDBNeighbourPath (nlohmann::json obj) {
        ApollodbmapDBNeighbourPath msg;
        if(obj.contains("segment"))
        {
            if(obj["segment"].is_array())
            {
                for (auto& element : obj["segment"])
                {
                    msg.segment.push_back(from_json_ApollodbmapDBNeighbourSegment(element));
                }
            }
            else
            {
                msg.segment.push_back(from_json_ApollodbmapDBNeighbourSegment(obj["segment"]));
            }
        }
        return msg;
    }
    template <>
    ApollodbmapDBNeighbourPath from_json<ApollodbmapDBNeighbourPath>(nlohmann::json obj){
        return from_json_ApollodbmapDBNeighbourPath(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollodbmapDBNeighbourPath &dt)
    {
        dt=from_json_ApollodbmapDBNeighbourPath(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollodbmapDBNeighbourPath & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodbmapDBNeighbourPath & dt)
    {
        os << to_json(dt);
        return os;
    }
}

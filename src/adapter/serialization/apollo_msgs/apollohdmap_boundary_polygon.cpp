#include "adapter/serialization/apollo_msgs/apollohdmap_boundary_polygon.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollohdmapBoundaryPolygon &msg) {
        nlohmann::json obj;
        nlohmann::json arr_edge;
        for (auto it = msg.edge.begin(); it != msg.edge.end(); ++it) {
            arr_edge.push_back(to_json(*it));
        }
        obj["edge"] = arr_edge;
        return obj;
    }
    ApollohdmapBoundaryPolygon from_json_ApollohdmapBoundaryPolygon (nlohmann::json obj) {
        ApollohdmapBoundaryPolygon msg;
        if(obj.contains("edge"))
        {
            if(obj["edge"].is_array())
            {
                for (auto& element : obj["edge"])
                {
                    msg.edge.push_back(from_json_ApollohdmapBoundaryEdge(element));
                }
            }
            else
            {
                msg.edge.push_back(from_json_ApollohdmapBoundaryEdge(obj["edge"]));
            }
        }
        return msg;
    }
    template <>
    ApollohdmapBoundaryPolygon from_json<ApollohdmapBoundaryPolygon>(nlohmann::json obj){
        return from_json_ApollohdmapBoundaryPolygon(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollohdmapBoundaryPolygon &dt)
    {
        dt=from_json_ApollohdmapBoundaryPolygon(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollohdmapBoundaryPolygon & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollohdmapBoundaryPolygon & dt)
    {
        os << to_json(dt);
        return os;
    }
}

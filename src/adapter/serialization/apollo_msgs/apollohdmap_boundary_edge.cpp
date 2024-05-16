#include "adapter/serialization/apollo_msgs/apollohdmap_boundary_edge.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollohdmapBoundaryEdge &msg) {
        nlohmann::json obj;
        obj["curve"] = to_json(msg.curve);
        obj["type"] = (msg.type);
        return obj;
    }
    ApollohdmapBoundaryEdge from_json_ApollohdmapBoundaryEdge (nlohmann::json obj) {
        ApollohdmapBoundaryEdge msg;
        if(obj.contains("curve"))
        {
            msg.curve = from_json_ApollohdmapCurve(obj["curve"]);
        }
        if(obj.contains("type"))
        {
            msg.type = (obj["type"].is_string()?atoi(obj["type"].get<std::string>().c_str()):obj["type"].get<int>());
        }
        return msg;
    }
    template <>
    ApollohdmapBoundaryEdge from_json<ApollohdmapBoundaryEdge>(nlohmann::json obj){
        return from_json_ApollohdmapBoundaryEdge(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollohdmapBoundaryEdge &dt)
    {
        dt=from_json_ApollohdmapBoundaryEdge(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollohdmapBoundaryEdge & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollohdmapBoundaryEdge & dt)
    {
        os << to_json(dt);
        return os;
    }
}

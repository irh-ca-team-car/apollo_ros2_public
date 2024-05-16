#include "adapter/serialization/apollo_msgs/apollodbmap_db_neighbour_segment.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodbmapDBNeighbourSegment &msg) {
        nlohmann::json obj;
        obj["starts"] = (msg.starts);
        obj["ends"] = (msg.ends);
        obj["pathid"] = (msg.pathid);
        obj["pathstarts"] = (msg.pathstarts);
        obj["pathends"] = (msg.pathends);
        return obj;
    }
    ApollodbmapDBNeighbourSegment from_json_ApollodbmapDBNeighbourSegment (nlohmann::json obj) {
        ApollodbmapDBNeighbourSegment msg;
        if(obj.contains("starts"))
        {
            msg.starts = (obj["starts"].is_string()?atof(obj["starts"].get<std::string>().c_str()):obj["starts"].get<double>());
        }
        if(obj.contains("ends"))
        {
            msg.ends = (obj["ends"].is_string()?atof(obj["ends"].get<std::string>().c_str()):obj["ends"].get<double>());
        }
        if(obj.contains("pathid"))
        {
            msg.pathid = (obj["pathid"].is_string()?(obj["pathid"].get<std::string>().c_str()):obj["pathid"].get<std::string>());
        }
        if(obj.contains("pathstarts"))
        {
            msg.pathstarts = (obj["pathstarts"].is_string()?atof(obj["pathstarts"].get<std::string>().c_str()):obj["pathstarts"].get<double>());
        }
        if(obj.contains("pathends"))
        {
            msg.pathends = (obj["pathends"].is_string()?atof(obj["pathends"].get<std::string>().c_str()):obj["pathends"].get<double>());
        }
        return msg;
    }
    template <>
    ApollodbmapDBNeighbourSegment from_json<ApollodbmapDBNeighbourSegment>(nlohmann::json obj){
        return from_json_ApollodbmapDBNeighbourSegment(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollodbmapDBNeighbourSegment &dt)
    {
        dt=from_json_ApollodbmapDBNeighbourSegment(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollodbmapDBNeighbourSegment & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodbmapDBNeighbourSegment & dt)
    {
        os << to_json(dt);
        return os;
    }
}

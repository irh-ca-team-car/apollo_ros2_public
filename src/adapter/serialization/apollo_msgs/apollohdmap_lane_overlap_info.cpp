#include "adapter/serialization/apollo_msgs/apollohdmap_lane_overlap_info.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollohdmapLaneOverlapInfo &msg) {
        nlohmann::json obj;
        obj["starts"] = (msg.starts);
        obj["ends"] = (msg.ends);
        obj["ismerge"] = (msg.ismerge);
        obj["regionoverlapid"] = to_json(msg.regionoverlapid);
        return obj;
    }
    ApollohdmapLaneOverlapInfo from_json_ApollohdmapLaneOverlapInfo (nlohmann::json obj) {
        ApollohdmapLaneOverlapInfo msg;
        if(obj.contains("starts"))
        {
            msg.starts = (obj["starts"].is_string()?atof(obj["starts"].get<std::string>().c_str()):obj["starts"].get<double>());
        }
        if(obj.contains("ends"))
        {
            msg.ends = (obj["ends"].is_string()?atof(obj["ends"].get<std::string>().c_str()):obj["ends"].get<double>());
        }
        if(obj.contains("ismerge"))
        {
            msg.ismerge = (obj["ismerge"].is_string()?(bool)atoi(obj["ismerge"].get<std::string>().c_str()):obj["ismerge"].get<bool>());
        }
        if(obj.contains("regionoverlapid"))
        {
            msg.regionoverlapid = from_json_ApollohdmapId(obj["regionoverlapid"]);
        }
        return msg;
    }
    template <>
    ApollohdmapLaneOverlapInfo from_json<ApollohdmapLaneOverlapInfo>(nlohmann::json obj){
        return from_json_ApollohdmapLaneOverlapInfo(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollohdmapLaneOverlapInfo &dt)
    {
        dt=from_json_ApollohdmapLaneOverlapInfo(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollohdmapLaneOverlapInfo & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollohdmapLaneOverlapInfo & dt)
    {
        os << to_json(dt);
        return os;
    }
}

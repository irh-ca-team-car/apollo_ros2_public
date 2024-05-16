#include "adapter/serialization/apollo_msgs/apollohdmap_object_overlap_info.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollohdmapObjectOverlapInfo &msg) {
        nlohmann::json obj;
        obj["id"] = to_json(msg.id);
        obj["overlapinfo"] = to_json(msg.overlapinfo);
        return obj;
    }
    ApollohdmapObjectOverlapInfo from_json_ApollohdmapObjectOverlapInfo (nlohmann::json obj) {
        ApollohdmapObjectOverlapInfo msg;
        if(obj.contains("id"))
        {
            msg.id = from_json_ApollohdmapId(obj["id"]);
        }
        if(obj.contains("overlapinfo"))
        {
            msg.overlapinfo = from_json_ApollohdmapObjectOverlapInfooverlapInfo(obj["overlapinfo"]);
        }
        return msg;
    }
    template <>
    ApollohdmapObjectOverlapInfo from_json<ApollohdmapObjectOverlapInfo>(nlohmann::json obj){
        return from_json_ApollohdmapObjectOverlapInfo(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollohdmapObjectOverlapInfo &dt)
    {
        dt=from_json_ApollohdmapObjectOverlapInfo(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollohdmapObjectOverlapInfo & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollohdmapObjectOverlapInfo & dt)
    {
        os << to_json(dt);
        return os;
    }
}

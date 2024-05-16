#include "adapter/serialization/apollo_msgs/apollohdmap_crosswalk_overlap_info.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollohdmapCrosswalkOverlapInfo &msg) {
        nlohmann::json obj;
        obj["regionoverlapid"] = to_json(msg.regionoverlapid);
        return obj;
    }
    ApollohdmapCrosswalkOverlapInfo from_json_ApollohdmapCrosswalkOverlapInfo (nlohmann::json obj) {
        ApollohdmapCrosswalkOverlapInfo msg;
        if(obj.contains("regionoverlapid"))
        {
            msg.regionoverlapid = from_json_ApollohdmapId(obj["regionoverlapid"]);
        }
        return msg;
    }
    template <>
    ApollohdmapCrosswalkOverlapInfo from_json<ApollohdmapCrosswalkOverlapInfo>(nlohmann::json obj){
        return from_json_ApollohdmapCrosswalkOverlapInfo(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollohdmapCrosswalkOverlapInfo &dt)
    {
        dt=from_json_ApollohdmapCrosswalkOverlapInfo(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollohdmapCrosswalkOverlapInfo & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollohdmapCrosswalkOverlapInfo & dt)
    {
        os << to_json(dt);
        return os;
    }
}

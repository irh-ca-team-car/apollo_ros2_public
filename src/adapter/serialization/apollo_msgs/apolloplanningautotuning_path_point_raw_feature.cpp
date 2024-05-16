#include "adapter/serialization/apollo_msgs/apolloplanningautotuning_path_point_raw_feature.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningautotuningPathPointRawFeature &msg) {
        nlohmann::json obj;
        obj["cartesiancoord"] = to_json(msg.cartesiancoord);
        obj["frenetcoord"] = to_json(msg.frenetcoord);
        return obj;
    }
    ApolloplanningautotuningPathPointRawFeature from_json_ApolloplanningautotuningPathPointRawFeature (nlohmann::json obj) {
        ApolloplanningautotuningPathPointRawFeature msg;
        if(obj.contains("cartesiancoord"))
        {
            msg.cartesiancoord = from_json_ApollocommonPathPoint(obj["cartesiancoord"]);
        }
        if(obj.contains("frenetcoord"))
        {
            msg.frenetcoord = from_json_ApollocommonFrenetFramePoint(obj["frenetcoord"]);
        }
        return msg;
    }
    template <>
    ApolloplanningautotuningPathPointRawFeature from_json<ApolloplanningautotuningPathPointRawFeature>(nlohmann::json obj){
        return from_json_ApolloplanningautotuningPathPointRawFeature(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningautotuningPathPointRawFeature &dt)
    {
        dt=from_json_ApolloplanningautotuningPathPointRawFeature(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningautotuningPathPointRawFeature & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningautotuningPathPointRawFeature & dt)
    {
        os << to_json(dt);
        return os;
    }
}

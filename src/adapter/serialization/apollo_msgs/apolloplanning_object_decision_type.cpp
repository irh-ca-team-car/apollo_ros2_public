#include "adapter/serialization/apollo_msgs/apolloplanning_object_decision_type.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningObjectDecisionType &msg) {
        nlohmann::json obj;
        obj["objecttag"] = to_json(msg.objecttag);
        return obj;
    }
    ApolloplanningObjectDecisionType from_json_ApolloplanningObjectDecisionType (nlohmann::json obj) {
        ApolloplanningObjectDecisionType msg;
        if(obj.contains("objecttag"))
        {
            msg.objecttag = from_json_ApolloplanningObjectDecisionTypeobjectTag(obj["objecttag"]);
        }
        return msg;
    }
    template <>
    ApolloplanningObjectDecisionType from_json<ApolloplanningObjectDecisionType>(nlohmann::json obj){
        return from_json_ApolloplanningObjectDecisionType(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningObjectDecisionType &dt)
    {
        dt=from_json_ApolloplanningObjectDecisionType(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningObjectDecisionType & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningObjectDecisionType & dt)
    {
        os << to_json(dt);
        return os;
    }
}

#include "adapter/serialization/apollo_msgs/apolloplanning_internal_decision_tag.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningInternalDecisionTag &msg) {
        nlohmann::json obj;
        obj["decidertag"] = (msg.decidertag);
        obj["decision"] = to_json(msg.decision);
        return obj;
    }
    ApolloplanningInternalDecisionTag from_json_ApolloplanningInternalDecisionTag (nlohmann::json obj) {
        ApolloplanningInternalDecisionTag msg;
        if(obj.contains("decidertag"))
        {
            msg.decidertag = (obj["decidertag"].is_string()?(obj["decidertag"].get<std::string>().c_str()):obj["decidertag"].get<std::string>());
        }
        if(obj.contains("decision"))
        {
            msg.decision = from_json_ApolloplanningObjectDecisionType(obj["decision"]);
        }
        return msg;
    }
    template <>
    ApolloplanningInternalDecisionTag from_json<ApolloplanningInternalDecisionTag>(nlohmann::json obj){
        return from_json_ApolloplanningInternalDecisionTag(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningInternalDecisionTag &dt)
    {
        dt=from_json_ApolloplanningInternalDecisionTag(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningInternalDecisionTag & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningInternalDecisionTag & dt)
    {
        os << to_json(dt);
        return os;
    }
}

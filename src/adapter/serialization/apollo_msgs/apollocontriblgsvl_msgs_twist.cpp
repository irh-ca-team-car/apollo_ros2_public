#include "adapter/serialization/apollo_msgs/apollocontriblgsvl_msgs_twist.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocontriblgsvlMsgsTwist &msg) {
        nlohmann::json obj;
        obj["linear"] = to_json(msg.linear);
        obj["angular"] = to_json(msg.angular);
        return obj;
    }
    ApollocontriblgsvlMsgsTwist from_json_ApollocontriblgsvlMsgsTwist (nlohmann::json obj) {
        ApollocontriblgsvlMsgsTwist msg;
        if(obj.contains("linear"))
        {
            msg.linear = from_json_ApollocontriblgsvlMsgsVector3(obj["linear"]);
        }
        if(obj.contains("angular"))
        {
            msg.angular = from_json_ApollocontriblgsvlMsgsVector3(obj["angular"]);
        }
        return msg;
    }
    template <>
    ApollocontriblgsvlMsgsTwist from_json<ApollocontriblgsvlMsgsTwist>(nlohmann::json obj){
        return from_json_ApollocontriblgsvlMsgsTwist(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocontriblgsvlMsgsTwist &dt)
    {
        dt=from_json_ApollocontriblgsvlMsgsTwist(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocontriblgsvlMsgsTwist & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocontriblgsvlMsgsTwist & dt)
    {
        os << to_json(dt);
        return os;
    }
}

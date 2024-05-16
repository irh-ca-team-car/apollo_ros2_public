#include "adapter/serialization/apollo_msgs/apolloplanning_object_status.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningObjectStatus &msg) {
        nlohmann::json obj;
        obj["motiontype"] = to_json(msg.motiontype);
        obj["decisiontype"] = to_json(msg.decisiontype);
        return obj;
    }
    ApolloplanningObjectStatus from_json_ApolloplanningObjectStatus (nlohmann::json obj) {
        ApolloplanningObjectStatus msg;
        if(obj.contains("motiontype"))
        {
            msg.motiontype = from_json_ApolloplanningObjectMotionType(obj["motiontype"]);
        }
        if(obj.contains("decisiontype"))
        {
            msg.decisiontype = from_json_ApolloplanningObjectDecisionType(obj["decisiontype"]);
        }
        return msg;
    }
    template <>
    ApolloplanningObjectStatus from_json<ApolloplanningObjectStatus>(nlohmann::json obj){
        return from_json_ApolloplanningObjectStatus(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningObjectStatus &dt)
    {
        dt=from_json_ApolloplanningObjectStatus(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningObjectStatus & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningObjectStatus & dt)
    {
        os << to_json(dt);
        return os;
    }
}

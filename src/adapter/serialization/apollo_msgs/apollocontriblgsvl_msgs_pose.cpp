#include "adapter/serialization/apollo_msgs/apollocontriblgsvl_msgs_pose.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocontriblgsvlMsgsPose &msg) {
        nlohmann::json obj;
        obj["position"] = to_json(msg.position);
        obj["orientation"] = to_json(msg.orientation);
        return obj;
    }
    ApollocontriblgsvlMsgsPose from_json_ApollocontriblgsvlMsgsPose (nlohmann::json obj) {
        ApollocontriblgsvlMsgsPose msg;
        if(obj.contains("position"))
        {
            msg.position = from_json_ApollocommonPoint3D(obj["position"]);
        }
        if(obj.contains("orientation"))
        {
            msg.orientation = from_json_ApollocommonQuaternion(obj["orientation"]);
        }
        return msg;
    }
    template <>
    ApollocontriblgsvlMsgsPose from_json<ApollocontriblgsvlMsgsPose>(nlohmann::json obj){
        return from_json_ApollocontriblgsvlMsgsPose(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocontriblgsvlMsgsPose &dt)
    {
        dt=from_json_ApollocontriblgsvlMsgsPose(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocontriblgsvlMsgsPose & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocontriblgsvlMsgsPose & dt)
    {
        os << to_json(dt);
        return os;
    }
}

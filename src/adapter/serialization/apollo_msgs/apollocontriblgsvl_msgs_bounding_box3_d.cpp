#include "adapter/serialization/apollo_msgs/apollocontriblgsvl_msgs_bounding_box3_d.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocontriblgsvlMsgsBoundingBox3D &msg) {
        nlohmann::json obj;
        obj["position"] = to_json(msg.position);
        obj["size"] = to_json(msg.size);
        return obj;
    }
    ApollocontriblgsvlMsgsBoundingBox3D from_json_ApollocontriblgsvlMsgsBoundingBox3D (nlohmann::json obj) {
        ApollocontriblgsvlMsgsBoundingBox3D msg;
        if(obj.contains("position"))
        {
            msg.position = from_json_ApollocontriblgsvlMsgsPose(obj["position"]);
        }
        if(obj.contains("size"))
        {
            msg.size = from_json_ApollocontriblgsvlMsgsVector3(obj["size"]);
        }
        return msg;
    }
    template <>
    ApollocontriblgsvlMsgsBoundingBox3D from_json<ApollocontriblgsvlMsgsBoundingBox3D>(nlohmann::json obj){
        return from_json_ApollocontriblgsvlMsgsBoundingBox3D(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocontriblgsvlMsgsBoundingBox3D &dt)
    {
        dt=from_json_ApollocontriblgsvlMsgsBoundingBox3D(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocontriblgsvlMsgsBoundingBox3D & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocontriblgsvlMsgsBoundingBox3D & dt)
    {
        os << to_json(dt);
        return os;
    }
}

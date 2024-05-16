#include "adapter/serialization/apollo_msgs/apollocontriblgsvl_msgs_detection3_d.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocontriblgsvlMsgsDetection3D &msg) {
        nlohmann::json obj;
        obj["apolloheader"] = to_json(msg.apolloheader);
        obj["id"] = (msg.id);
        obj["label"] = (msg.label);
        obj["score"] = (msg.score);
        obj["bbox"] = to_json(msg.bbox);
        obj["velocity"] = to_json(msg.velocity);
        return obj;
    }
    ApollocontriblgsvlMsgsDetection3D from_json_ApollocontriblgsvlMsgsDetection3D (nlohmann::json obj) {
        ApollocontriblgsvlMsgsDetection3D msg;
        if(obj.contains("apolloheader"))
        {
            msg.apolloheader = from_json_ApollocommonHeader(obj["apolloheader"]);
        }
        if(obj.contains("id"))
        {
            msg.id = (obj["id"].is_string()?atoi(obj["id"].get<std::string>().c_str()):obj["id"].get<uint32_t>());
        }
        if(obj.contains("label"))
        {
            msg.label = (obj["label"].is_string()?(obj["label"].get<std::string>().c_str()):obj["label"].get<std::string>());
        }
        if(obj.contains("score"))
        {
            msg.score = (obj["score"].is_string()?atof(obj["score"].get<std::string>().c_str()):obj["score"].get<double>());
        }
        if(obj.contains("bbox"))
        {
            msg.bbox = from_json_ApollocontriblgsvlMsgsBoundingBox3D(obj["bbox"]);
        }
        if(obj.contains("velocity"))
        {
            msg.velocity = from_json_ApollocontriblgsvlMsgsTwist(obj["velocity"]);
        }
        return msg;
    }
    template <>
    ApollocontriblgsvlMsgsDetection3D from_json<ApollocontriblgsvlMsgsDetection3D>(nlohmann::json obj){
        return from_json_ApollocontriblgsvlMsgsDetection3D(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocontriblgsvlMsgsDetection3D &dt)
    {
        dt=from_json_ApollocontriblgsvlMsgsDetection3D(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocontriblgsvlMsgsDetection3D & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocontriblgsvlMsgsDetection3D & dt)
    {
        os << to_json(dt);
        return os;
    }
}

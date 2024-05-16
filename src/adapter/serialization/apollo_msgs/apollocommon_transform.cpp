#include "adapter/serialization/apollo_msgs/apollocommon_transform.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocommonTransform &msg) {
        nlohmann::json obj;
        obj["sourceframe"] = to_json(msg.sourceframe);
        obj["targetframe"] = to_json(msg.targetframe);
        obj["translation"] = to_json(msg.translation);
        obj["rotation"] = to_json(msg.rotation);
        return obj;
    }
    ApollocommonTransform from_json_ApollocommonTransform (nlohmann::json obj) {
        ApollocommonTransform msg;
        if(obj.contains("sourceframe"))
        {
            msg.sourceframe = from_json_Bytes(obj["sourceframe"]);
        }
        if(obj.contains("targetframe"))
        {
            msg.targetframe = from_json_Bytes(obj["targetframe"]);
        }
        if(obj.contains("translation"))
        {
            msg.translation = from_json_ApollocommonPoint3D(obj["translation"]);
        }
        if(obj.contains("rotation"))
        {
            msg.rotation = from_json_ApollocommonQuaternion(obj["rotation"]);
        }
        return msg;
    }
    template <>
    ApollocommonTransform from_json<ApollocommonTransform>(nlohmann::json obj){
        return from_json_ApollocommonTransform(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocommonTransform &dt)
    {
        dt=from_json_ApollocommonTransform(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocommonTransform & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocommonTransform & dt)
    {
        os << to_json(dt);
        return os;
    }
}

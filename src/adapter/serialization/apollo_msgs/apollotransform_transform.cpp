#include "adapter/serialization/apollo_msgs/apollotransform_transform.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollotransformTransform &msg) {
        nlohmann::json obj;
        obj["translation"] = to_json(msg.translation);
        obj["rotation"] = to_json(msg.rotation);
        return obj;
    }
    ApollotransformTransform from_json_ApollotransformTransform (nlohmann::json obj) {
        ApollotransformTransform msg;
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
    ApollotransformTransform from_json<ApollotransformTransform>(nlohmann::json obj){
        return from_json_ApollotransformTransform(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollotransformTransform &dt)
    {
        dt=from_json_ApollotransformTransform(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollotransformTransform & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollotransformTransform & dt)
    {
        os << to_json(dt);
        return os;
    }
}

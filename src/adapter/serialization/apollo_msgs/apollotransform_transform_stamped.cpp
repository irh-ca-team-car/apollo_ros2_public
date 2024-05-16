#include "adapter/serialization/apollo_msgs/apollotransform_transform_stamped.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollotransformTransformStamped &msg) {
        nlohmann::json obj;
        obj["apolloheader"] = to_json(msg.apolloheader);
        obj["childframeid"] = (msg.childframeid);
        obj["transform"] = to_json(msg.transform);
        return obj;
    }
    ApollotransformTransformStamped from_json_ApollotransformTransformStamped (nlohmann::json obj) {
        ApollotransformTransformStamped msg;
        if(obj.contains("apolloheader"))
        {
            msg.apolloheader = from_json_ApollocommonHeader(obj["apolloheader"]);
        }
        if(obj.contains("childframeid"))
        {
            msg.childframeid = (obj["childframeid"].is_string()?(obj["childframeid"].get<std::string>().c_str()):obj["childframeid"].get<std::string>());
        }
        if(obj.contains("transform"))
        {
            msg.transform = from_json_ApollotransformTransform(obj["transform"]);
        }
        return msg;
    }
    template <>
    ApollotransformTransformStamped from_json<ApollotransformTransformStamped>(nlohmann::json obj){
        return from_json_ApollotransformTransformStamped(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollotransformTransformStamped &dt)
    {
        dt=from_json_ApollotransformTransformStamped(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollotransformTransformStamped & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollotransformTransformStamped & dt)
    {
        os << to_json(dt);
        return os;
    }
}

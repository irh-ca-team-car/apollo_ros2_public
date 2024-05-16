#include "adapter/serialization/apollo_msgs/apollotransform_transform_stampeds.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollotransformTransformStampeds &msg) {
        nlohmann::json obj;
        obj["apolloheader"] = to_json(msg.apolloheader);
        nlohmann::json arr_transforms;
        for (auto it = msg.transforms.begin(); it != msg.transforms.end(); ++it) {
            arr_transforms.push_back(to_json(*it));
        }
        obj["transforms"] = arr_transforms;
        return obj;
    }
    ApollotransformTransformStampeds from_json_ApollotransformTransformStampeds (nlohmann::json obj) {
        ApollotransformTransformStampeds msg;
        if(obj.contains("apolloheader"))
        {
            msg.apolloheader = from_json_ApollocommonHeader(obj["apolloheader"]);
        }
        if(obj.contains("transforms"))
        {
            if(obj["transforms"].is_array())
            {
                for (auto& element : obj["transforms"])
                {
                    msg.transforms.push_back(from_json_ApollotransformTransformStamped(element));
                }
            }
            else
            {
                msg.transforms.push_back(from_json_ApollotransformTransformStamped(obj["transforms"]));
            }
        }
        return msg;
    }
    template <>
    ApollotransformTransformStampeds from_json<ApollotransformTransformStampeds>(nlohmann::json obj){
        return from_json_ApollotransformTransformStampeds(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollotransformTransformStampeds &dt)
    {
        dt=from_json_ApollotransformTransformStampeds(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollotransformTransformStampeds & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollotransformTransformStampeds & dt)
    {
        os << to_json(dt);
        return os;
    }
}

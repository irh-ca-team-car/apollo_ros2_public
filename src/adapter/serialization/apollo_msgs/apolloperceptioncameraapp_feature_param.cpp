#include "adapter/serialization/apollo_msgs/apolloperceptioncameraapp_feature_param.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioncameraappFeatureParam &msg) {
        nlohmann::json obj;
        obj["pluginparam"] = to_json(msg.pluginparam);
        return obj;
    }
    ApolloperceptioncameraappFeatureParam from_json_ApolloperceptioncameraappFeatureParam (nlohmann::json obj) {
        ApolloperceptioncameraappFeatureParam msg;
        if(obj.contains("pluginparam"))
        {
            msg.pluginparam = from_json_ApolloperceptioncameraappPluginParam(obj["pluginparam"]);
        }
        return msg;
    }
    template <>
    ApolloperceptioncameraappFeatureParam from_json<ApolloperceptioncameraappFeatureParam>(nlohmann::json obj){
        return from_json_ApolloperceptioncameraappFeatureParam(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioncameraappFeatureParam &dt)
    {
        dt=from_json_ApolloperceptioncameraappFeatureParam(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioncameraappFeatureParam & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioncameraappFeatureParam & dt)
    {
        os << to_json(dt);
        return os;
    }
}

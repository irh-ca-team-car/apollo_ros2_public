#include "adapter/serialization/apollo_msgs/apolloperceptioncameraapp_postprocessor_param.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioncameraappPostprocessorParam &msg) {
        nlohmann::json obj;
        obj["pluginparam"] = to_json(msg.pluginparam);
        return obj;
    }
    ApolloperceptioncameraappPostprocessorParam from_json_ApolloperceptioncameraappPostprocessorParam (nlohmann::json obj) {
        ApolloperceptioncameraappPostprocessorParam msg;
        if(obj.contains("pluginparam"))
        {
            msg.pluginparam = from_json_ApolloperceptioncameraappPluginParam(obj["pluginparam"]);
        }
        return msg;
    }
    template <>
    ApolloperceptioncameraappPostprocessorParam from_json<ApolloperceptioncameraappPostprocessorParam>(nlohmann::json obj){
        return from_json_ApolloperceptioncameraappPostprocessorParam(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioncameraappPostprocessorParam &dt)
    {
        dt=from_json_ApolloperceptioncameraappPostprocessorParam(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioncameraappPostprocessorParam & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioncameraappPostprocessorParam & dt)
    {
        os << to_json(dt);
        return os;
    }
}

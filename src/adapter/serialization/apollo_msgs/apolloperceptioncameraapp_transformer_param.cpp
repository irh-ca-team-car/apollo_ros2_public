#include "adapter/serialization/apollo_msgs/apolloperceptioncameraapp_transformer_param.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioncameraappTransformerParam &msg) {
        nlohmann::json obj;
        obj["pluginparam"] = to_json(msg.pluginparam);
        return obj;
    }
    ApolloperceptioncameraappTransformerParam from_json_ApolloperceptioncameraappTransformerParam (nlohmann::json obj) {
        ApolloperceptioncameraappTransformerParam msg;
        if(obj.contains("pluginparam"))
        {
            msg.pluginparam = from_json_ApolloperceptioncameraappPluginParam(obj["pluginparam"]);
        }
        return msg;
    }
    template <>
    ApolloperceptioncameraappTransformerParam from_json<ApolloperceptioncameraappTransformerParam>(nlohmann::json obj){
        return from_json_ApolloperceptioncameraappTransformerParam(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioncameraappTransformerParam &dt)
    {
        dt=from_json_ApolloperceptioncameraappTransformerParam(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioncameraappTransformerParam & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioncameraappTransformerParam & dt)
    {
        os << to_json(dt);
        return os;
    }
}

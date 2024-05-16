#include "adapter/serialization/apollo_msgs/apolloperceptioncameraapp_object_template_param.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioncameraappObjectTemplateParam &msg) {
        nlohmann::json obj;
        obj["pluginparam"] = to_json(msg.pluginparam);
        return obj;
    }
    ApolloperceptioncameraappObjectTemplateParam from_json_ApolloperceptioncameraappObjectTemplateParam (nlohmann::json obj) {
        ApolloperceptioncameraappObjectTemplateParam msg;
        if(obj.contains("pluginparam"))
        {
            msg.pluginparam = from_json_ApolloperceptioncameraappPluginParam(obj["pluginparam"]);
        }
        return msg;
    }
    template <>
    ApolloperceptioncameraappObjectTemplateParam from_json<ApolloperceptioncameraappObjectTemplateParam>(nlohmann::json obj){
        return from_json_ApolloperceptioncameraappObjectTemplateParam(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioncameraappObjectTemplateParam &dt)
    {
        dt=from_json_ApolloperceptioncameraappObjectTemplateParam(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioncameraappObjectTemplateParam & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioncameraappObjectTemplateParam & dt)
    {
        os << to_json(dt);
        return os;
    }
}

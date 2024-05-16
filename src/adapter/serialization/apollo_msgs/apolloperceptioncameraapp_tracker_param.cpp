#include "adapter/serialization/apollo_msgs/apolloperceptioncameraapp_tracker_param.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioncameraappTrackerParam &msg) {
        nlohmann::json obj;
        obj["pluginparam"] = to_json(msg.pluginparam);
        return obj;
    }
    ApolloperceptioncameraappTrackerParam from_json_ApolloperceptioncameraappTrackerParam (nlohmann::json obj) {
        ApolloperceptioncameraappTrackerParam msg;
        if(obj.contains("pluginparam"))
        {
            msg.pluginparam = from_json_ApolloperceptioncameraappPluginParam(obj["pluginparam"]);
        }
        return msg;
    }
    template <>
    ApolloperceptioncameraappTrackerParam from_json<ApolloperceptioncameraappTrackerParam>(nlohmann::json obj){
        return from_json_ApolloperceptioncameraappTrackerParam(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioncameraappTrackerParam &dt)
    {
        dt=from_json_ApolloperceptioncameraappTrackerParam(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioncameraappTrackerParam & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioncameraappTrackerParam & dt)
    {
        os << to_json(dt);
        return os;
    }
}

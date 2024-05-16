#include "adapter/serialization/apollo_msgs/apolloperceptioncameratracking_feature_roi_pooling_param.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioncameratrackingFeatureROIPoolingParam &msg) {
        nlohmann::json obj;
        obj["pooledh"] = (msg.pooledh);
        obj["pooledw"] = (msg.pooledw);
        obj["usefloor"] = (msg.usefloor);
        return obj;
    }
    ApolloperceptioncameratrackingFeatureROIPoolingParam from_json_ApolloperceptioncameratrackingFeatureROIPoolingParam (nlohmann::json obj) {
        ApolloperceptioncameratrackingFeatureROIPoolingParam msg;
        if(obj.contains("pooledh"))
        {
            msg.pooledh = (obj["pooledh"].is_string()?atoi(obj["pooledh"].get<std::string>().c_str()):obj["pooledh"].get<int>());
        }
        if(obj.contains("pooledw"))
        {
            msg.pooledw = (obj["pooledw"].is_string()?atoi(obj["pooledw"].get<std::string>().c_str()):obj["pooledw"].get<int>());
        }
        if(obj.contains("usefloor"))
        {
            msg.usefloor = (obj["usefloor"].is_string()?(bool)atoi(obj["usefloor"].get<std::string>().c_str()):obj["usefloor"].get<bool>());
        }
        return msg;
    }
    template <>
    ApolloperceptioncameratrackingFeatureROIPoolingParam from_json<ApolloperceptioncameratrackingFeatureROIPoolingParam>(nlohmann::json obj){
        return from_json_ApolloperceptioncameratrackingFeatureROIPoolingParam(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioncameratrackingFeatureROIPoolingParam &dt)
    {
        dt=from_json_ApolloperceptioncameratrackingFeatureROIPoolingParam(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioncameratrackingFeatureROIPoolingParam & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioncameratrackingFeatureROIPoolingParam & dt)
    {
        os << to_json(dt);
        return os;
    }
}

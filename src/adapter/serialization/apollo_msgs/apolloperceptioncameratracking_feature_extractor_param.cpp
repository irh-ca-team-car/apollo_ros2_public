#include "adapter/serialization/apollo_msgs/apolloperceptioncameratracking_feature_extractor_param.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioncameratrackingFeatureExtractorParam &msg) {
        nlohmann::json obj;
        obj["featblob"] = (msg.featblob);
        obj["feattype"] = (msg.feattype);
        obj["roipoolingparam"] = to_json(msg.roipoolingparam);
        obj["psroipoolingparam"] = to_json(msg.psroipoolingparam);
        return obj;
    }
    ApolloperceptioncameratrackingFeatureExtractorParam from_json_ApolloperceptioncameratrackingFeatureExtractorParam (nlohmann::json obj) {
        ApolloperceptioncameratrackingFeatureExtractorParam msg;
        if(obj.contains("featblob"))
        {
            msg.featblob = (obj["featblob"].is_string()?(obj["featblob"].get<std::string>().c_str()):obj["featblob"].get<std::string>());
        }
        if(obj.contains("feattype"))
        {
            msg.feattype = (obj["feattype"].is_string()?atoi(obj["feattype"].get<std::string>().c_str()):obj["feattype"].get<int>());
        }
        if(obj.contains("roipoolingparam"))
        {
            msg.roipoolingparam = from_json_ApolloperceptioncameratrackingFeatureROIPoolingParam(obj["roipoolingparam"]);
        }
        if(obj.contains("psroipoolingparam"))
        {
            msg.psroipoolingparam = from_json_ApolloperceptioncameratrackingFeaturePSROIPoolingParam(obj["psroipoolingparam"]);
        }
        return msg;
    }
    template <>
    ApolloperceptioncameratrackingFeatureExtractorParam from_json<ApolloperceptioncameratrackingFeatureExtractorParam>(nlohmann::json obj){
        return from_json_ApolloperceptioncameratrackingFeatureExtractorParam(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioncameratrackingFeatureExtractorParam &dt)
    {
        dt=from_json_ApolloperceptioncameratrackingFeatureExtractorParam(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioncameratrackingFeatureExtractorParam & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioncameratrackingFeatureExtractorParam & dt)
    {
        os << to_json(dt);
        return os;
    }
}

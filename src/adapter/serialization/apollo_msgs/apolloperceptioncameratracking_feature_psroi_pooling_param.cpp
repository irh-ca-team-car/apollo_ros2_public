#include "adapter/serialization/apollo_msgs/apolloperceptioncameratracking_feature_psroi_pooling_param.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioncameratrackingFeaturePSROIPoolingParam &msg) {
        nlohmann::json obj;
        obj["heatmapa"] = (msg.heatmapa);
        obj["outputdim"] = (msg.outputdim);
        obj["groupheight"] = (msg.groupheight);
        obj["groupwidth"] = (msg.groupwidth);
        obj["pooledheight"] = (msg.pooledheight);
        obj["pooledwidth"] = (msg.pooledwidth);
        obj["sampleperpart"] = (msg.sampleperpart);
        return obj;
    }
    ApolloperceptioncameratrackingFeaturePSROIPoolingParam from_json_ApolloperceptioncameratrackingFeaturePSROIPoolingParam (nlohmann::json obj) {
        ApolloperceptioncameratrackingFeaturePSROIPoolingParam msg;
        if(obj.contains("heatmapa"))
        {
            msg.heatmapa = (obj["heatmapa"].is_string()?atoi(obj["heatmapa"].get<std::string>().c_str()):obj["heatmapa"].get<int>());
        }
        if(obj.contains("outputdim"))
        {
            msg.outputdim = (obj["outputdim"].is_string()?atoi(obj["outputdim"].get<std::string>().c_str()):obj["outputdim"].get<int>());
        }
        if(obj.contains("groupheight"))
        {
            msg.groupheight = (obj["groupheight"].is_string()?atoi(obj["groupheight"].get<std::string>().c_str()):obj["groupheight"].get<int>());
        }
        if(obj.contains("groupwidth"))
        {
            msg.groupwidth = (obj["groupwidth"].is_string()?atoi(obj["groupwidth"].get<std::string>().c_str()):obj["groupwidth"].get<int>());
        }
        if(obj.contains("pooledheight"))
        {
            msg.pooledheight = (obj["pooledheight"].is_string()?atoi(obj["pooledheight"].get<std::string>().c_str()):obj["pooledheight"].get<int>());
        }
        if(obj.contains("pooledwidth"))
        {
            msg.pooledwidth = (obj["pooledwidth"].is_string()?atoi(obj["pooledwidth"].get<std::string>().c_str()):obj["pooledwidth"].get<int>());
        }
        if(obj.contains("sampleperpart"))
        {
            msg.sampleperpart = (obj["sampleperpart"].is_string()?atoi(obj["sampleperpart"].get<std::string>().c_str()):obj["sampleperpart"].get<int>());
        }
        return msg;
    }
    template <>
    ApolloperceptioncameratrackingFeaturePSROIPoolingParam from_json<ApolloperceptioncameratrackingFeaturePSROIPoolingParam>(nlohmann::json obj){
        return from_json_ApolloperceptioncameratrackingFeaturePSROIPoolingParam(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioncameratrackingFeaturePSROIPoolingParam &dt)
    {
        dt=from_json_ApolloperceptioncameratrackingFeaturePSROIPoolingParam(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioncameratrackingFeaturePSROIPoolingParam & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioncameratrackingFeaturePSROIPoolingParam & dt)
    {
        os << to_json(dt);
        return os;
    }
}

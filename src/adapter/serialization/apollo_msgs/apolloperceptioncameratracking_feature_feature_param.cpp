#include "adapter/serialization/apollo_msgs/apolloperceptioncameratracking_feature_feature_param.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioncameratrackingFeatureFeatureParam &msg) {
        nlohmann::json obj;
        obj["featstride"] = (msg.featstride);
        nlohmann::json arr_extractor;
        for (auto it = msg.extractor.begin(); it != msg.extractor.end(); ++it) {
            arr_extractor.push_back(to_json(*it));
        }
        obj["extractor"] = arr_extractor;
        obj["remapmodel"] = (msg.remapmodel);
        return obj;
    }
    ApolloperceptioncameratrackingFeatureFeatureParam from_json_ApolloperceptioncameratrackingFeatureFeatureParam (nlohmann::json obj) {
        ApolloperceptioncameratrackingFeatureFeatureParam msg;
        if(obj.contains("featstride"))
        {
            msg.featstride = (obj["featstride"].is_string()?atoi(obj["featstride"].get<std::string>().c_str()):obj["featstride"].get<int>());
        }
        if(obj.contains("extractor"))
        {
            if(obj["extractor"].is_array())
            {
                for (auto& element : obj["extractor"])
                {
                    msg.extractor.push_back(from_json_ApolloperceptioncameratrackingFeatureExtractorParam(element));
                }
            }
            else
            {
                msg.extractor.push_back(from_json_ApolloperceptioncameratrackingFeatureExtractorParam(obj["extractor"]));
            }
        }
        if(obj.contains("remapmodel"))
        {
            msg.remapmodel = (obj["remapmodel"].is_string()?(obj["remapmodel"].get<std::string>().c_str()):obj["remapmodel"].get<std::string>());
        }
        return msg;
    }
    template <>
    ApolloperceptioncameratrackingFeatureFeatureParam from_json<ApolloperceptioncameratrackingFeatureFeatureParam>(nlohmann::json obj){
        return from_json_ApolloperceptioncameratrackingFeatureFeatureParam(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioncameratrackingFeatureFeatureParam &dt)
    {
        dt=from_json_ApolloperceptioncameratrackingFeatureFeatureParam(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioncameratrackingFeatureFeatureParam & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioncameratrackingFeatureFeatureParam & dt)
    {
        os << to_json(dt);
        return os;
    }
}

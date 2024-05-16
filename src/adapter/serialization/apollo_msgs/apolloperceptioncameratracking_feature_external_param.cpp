#include "adapter/serialization/apollo_msgs/apolloperceptioncameratracking_feature_external_param.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioncameratrackingFeatureExternalParam &msg) {
        nlohmann::json obj;
        obj["modeltype"] = (msg.modeltype);
        obj["protofile"] = (msg.protofile);
        obj["weightfile"] = (msg.weightfile);
        obj["resizeheight"] = (msg.resizeheight);
        obj["resizewidth"] = (msg.resizewidth);
        obj["inputblob"] = (msg.inputblob);
        obj["featblob"] = (msg.featblob);
        obj["offsetratio"] = (msg.offsetratio);
        obj["featurefile"] = (msg.featurefile);
        return obj;
    }
    ApolloperceptioncameratrackingFeatureExternalParam from_json_ApolloperceptioncameratrackingFeatureExternalParam (nlohmann::json obj) {
        ApolloperceptioncameratrackingFeatureExternalParam msg;
        if(obj.contains("modeltype"))
        {
            msg.modeltype = (obj["modeltype"].is_string()?(obj["modeltype"].get<std::string>().c_str()):obj["modeltype"].get<std::string>());
        }
        if(obj.contains("protofile"))
        {
            msg.protofile = (obj["protofile"].is_string()?(obj["protofile"].get<std::string>().c_str()):obj["protofile"].get<std::string>());
        }
        if(obj.contains("weightfile"))
        {
            msg.weightfile = (obj["weightfile"].is_string()?(obj["weightfile"].get<std::string>().c_str()):obj["weightfile"].get<std::string>());
        }
        if(obj.contains("resizeheight"))
        {
            msg.resizeheight = (obj["resizeheight"].is_string()?atoi(obj["resizeheight"].get<std::string>().c_str()):obj["resizeheight"].get<int>());
        }
        if(obj.contains("resizewidth"))
        {
            msg.resizewidth = (obj["resizewidth"].is_string()?atoi(obj["resizewidth"].get<std::string>().c_str()):obj["resizewidth"].get<int>());
        }
        if(obj.contains("inputblob"))
        {
            msg.inputblob = (obj["inputblob"].is_string()?(obj["inputblob"].get<std::string>().c_str()):obj["inputblob"].get<std::string>());
        }
        if(obj.contains("featblob"))
        {
            msg.featblob = (obj["featblob"].is_string()?(obj["featblob"].get<std::string>().c_str()):obj["featblob"].get<std::string>());
        }
        if(obj.contains("offsetratio"))
        {
            msg.offsetratio = (obj["offsetratio"].is_string()?(float)atof(obj["offsetratio"].get<std::string>().c_str()):obj["offsetratio"].get<float>());
        }
        if(obj.contains("featurefile"))
        {
            msg.featurefile = (obj["featurefile"].is_string()?(obj["featurefile"].get<std::string>().c_str()):obj["featurefile"].get<std::string>());
        }
        return msg;
    }
    template <>
    ApolloperceptioncameratrackingFeatureExternalParam from_json<ApolloperceptioncameratrackingFeatureExternalParam>(nlohmann::json obj){
        return from_json_ApolloperceptioncameratrackingFeatureExternalParam(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioncameratrackingFeatureExternalParam &dt)
    {
        dt=from_json_ApolloperceptioncameratrackingFeatureExternalParam(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioncameratrackingFeatureExternalParam & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioncameratrackingFeatureExternalParam & dt)
    {
        os << to_json(dt);
        return os;
    }
}

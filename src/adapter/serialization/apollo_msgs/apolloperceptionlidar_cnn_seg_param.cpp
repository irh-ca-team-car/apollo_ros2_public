#include "adapter/serialization/apollo_msgs/apolloperceptionlidar_cnn_seg_param.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptionlidarCNNSegParam &msg) {
        nlohmann::json obj;
        obj["modeltype"] = (msg.modeltype);
        obj["networkparam"] = to_json(msg.networkparam);
        obj["featureparam"] = to_json(msg.featureparam);
        obj["doclassification"] = (msg.doclassification);
        obj["doheading"] = (msg.doheading);
        obj["gpuid"] = (msg.gpuid);
        obj["grounddetector"] = (msg.grounddetector);
        obj["roifilter"] = (msg.roifilter);
        obj["removegroundpoints"] = (msg.removegroundpoints);
        obj["objectnessthresh"] = (msg.objectnessthresh);
        obj["confidencethresh"] = (msg.confidencethresh);
        obj["heightthresh"] = (msg.heightthresh);
        obj["minptsnum"] = (msg.minptsnum);
        obj["confidencerange"] = (msg.confidencerange);
        return obj;
    }
    ApolloperceptionlidarCNNSegParam from_json_ApolloperceptionlidarCNNSegParam (nlohmann::json obj) {
        ApolloperceptionlidarCNNSegParam msg;
        if(obj.contains("modeltype"))
        {
            msg.modeltype = (obj["modeltype"].is_string()?(obj["modeltype"].get<std::string>().c_str()):obj["modeltype"].get<std::string>());
        }
        if(obj.contains("networkparam"))
        {
            msg.networkparam = from_json_ApolloperceptionlidarNetworkParam(obj["networkparam"]);
        }
        if(obj.contains("featureparam"))
        {
            msg.featureparam = from_json_ApolloperceptionlidarFeatureParam(obj["featureparam"]);
        }
        if(obj.contains("doclassification"))
        {
            msg.doclassification = (obj["doclassification"].is_string()?(bool)atoi(obj["doclassification"].get<std::string>().c_str()):obj["doclassification"].get<bool>());
        }
        if(obj.contains("doheading"))
        {
            msg.doheading = (obj["doheading"].is_string()?(bool)atoi(obj["doheading"].get<std::string>().c_str()):obj["doheading"].get<bool>());
        }
        if(obj.contains("gpuid"))
        {
            msg.gpuid = (obj["gpuid"].is_string()?atoi(obj["gpuid"].get<std::string>().c_str()):obj["gpuid"].get<uint32_t>());
        }
        if(obj.contains("grounddetector"))
        {
            msg.grounddetector = (obj["grounddetector"].is_string()?(obj["grounddetector"].get<std::string>().c_str()):obj["grounddetector"].get<std::string>());
        }
        if(obj.contains("roifilter"))
        {
            msg.roifilter = (obj["roifilter"].is_string()?(obj["roifilter"].get<std::string>().c_str()):obj["roifilter"].get<std::string>());
        }
        if(obj.contains("removegroundpoints"))
        {
            msg.removegroundpoints = (obj["removegroundpoints"].is_string()?(bool)atoi(obj["removegroundpoints"].get<std::string>().c_str()):obj["removegroundpoints"].get<bool>());
        }
        if(obj.contains("objectnessthresh"))
        {
            msg.objectnessthresh = (obj["objectnessthresh"].is_string()?(float)atof(obj["objectnessthresh"].get<std::string>().c_str()):obj["objectnessthresh"].get<float>());
        }
        if(obj.contains("confidencethresh"))
        {
            msg.confidencethresh = (obj["confidencethresh"].is_string()?(float)atof(obj["confidencethresh"].get<std::string>().c_str()):obj["confidencethresh"].get<float>());
        }
        if(obj.contains("heightthresh"))
        {
            msg.heightthresh = (obj["heightthresh"].is_string()?(float)atof(obj["heightthresh"].get<std::string>().c_str()):obj["heightthresh"].get<float>());
        }
        if(obj.contains("minptsnum"))
        {
            msg.minptsnum = (obj["minptsnum"].is_string()?atoi(obj["minptsnum"].get<std::string>().c_str()):obj["minptsnum"].get<uint32_t>());
        }
        if(obj.contains("confidencerange"))
        {
            msg.confidencerange = (obj["confidencerange"].is_string()?(float)atof(obj["confidencerange"].get<std::string>().c_str()):obj["confidencerange"].get<float>());
        }
        return msg;
    }
    template <>
    ApolloperceptionlidarCNNSegParam from_json<ApolloperceptionlidarCNNSegParam>(nlohmann::json obj){
        return from_json_ApolloperceptionlidarCNNSegParam(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptionlidarCNNSegParam &dt)
    {
        dt=from_json_ApolloperceptionlidarCNNSegParam(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptionlidarCNNSegParam & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptionlidarCNNSegParam & dt)
    {
        os << to_json(dt);
        return os;
    }
}

#include "adapter/serialization/apollo_msgs/apolloperceptionlidar_feature_param.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptionlidarFeatureParam &msg) {
        nlohmann::json obj;
        obj["pointcloudrange"] = (msg.pointcloudrange);
        obj["width"] = (msg.width);
        obj["height"] = (msg.height);
        obj["minheight"] = (msg.minheight);
        obj["maxheight"] = (msg.maxheight);
        obj["useintensityfeature"] = (msg.useintensityfeature);
        obj["useconstantfeature"] = (msg.useconstantfeature);
        return obj;
    }
    ApolloperceptionlidarFeatureParam from_json_ApolloperceptionlidarFeatureParam (nlohmann::json obj) {
        ApolloperceptionlidarFeatureParam msg;
        if(obj.contains("pointcloudrange"))
        {
            msg.pointcloudrange = (obj["pointcloudrange"].is_string()?(float)atof(obj["pointcloudrange"].get<std::string>().c_str()):obj["pointcloudrange"].get<float>());
        }
        if(obj.contains("width"))
        {
            msg.width = (obj["width"].is_string()?atoi(obj["width"].get<std::string>().c_str()):obj["width"].get<uint32_t>());
        }
        if(obj.contains("height"))
        {
            msg.height = (obj["height"].is_string()?atoi(obj["height"].get<std::string>().c_str()):obj["height"].get<uint32_t>());
        }
        if(obj.contains("minheight"))
        {
            msg.minheight = (obj["minheight"].is_string()?(float)atof(obj["minheight"].get<std::string>().c_str()):obj["minheight"].get<float>());
        }
        if(obj.contains("maxheight"))
        {
            msg.maxheight = (obj["maxheight"].is_string()?(float)atof(obj["maxheight"].get<std::string>().c_str()):obj["maxheight"].get<float>());
        }
        if(obj.contains("useintensityfeature"))
        {
            msg.useintensityfeature = (obj["useintensityfeature"].is_string()?(bool)atoi(obj["useintensityfeature"].get<std::string>().c_str()):obj["useintensityfeature"].get<bool>());
        }
        if(obj.contains("useconstantfeature"))
        {
            msg.useconstantfeature = (obj["useconstantfeature"].is_string()?(bool)atoi(obj["useconstantfeature"].get<std::string>().c_str()):obj["useconstantfeature"].get<bool>());
        }
        return msg;
    }
    template <>
    ApolloperceptionlidarFeatureParam from_json<ApolloperceptionlidarFeatureParam>(nlohmann::json obj){
        return from_json_ApolloperceptionlidarFeatureParam(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptionlidarFeatureParam &dt)
    {
        dt=from_json_ApolloperceptionlidarFeatureParam(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptionlidarFeatureParam & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptionlidarFeatureParam & dt)
    {
        os << to_json(dt);
        return os;
    }
}

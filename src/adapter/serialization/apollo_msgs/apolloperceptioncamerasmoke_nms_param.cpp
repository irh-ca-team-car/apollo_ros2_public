#include "adapter/serialization/apollo_msgs/apolloperceptioncamerasmoke_nms_param.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioncamerasmokeNMSParam &msg) {
        nlohmann::json obj;
        obj["type"] = (msg.type);
        obj["threshold"] = (msg.threshold);
        obj["sigma"] = (msg.sigma);
        obj["interclsconfthresh"] = (msg.interclsconfthresh);
        obj["interclsnmsthresh"] = (msg.interclsnmsthresh);
        return obj;
    }
    ApolloperceptioncamerasmokeNMSParam from_json_ApolloperceptioncamerasmokeNMSParam (nlohmann::json obj) {
        ApolloperceptioncamerasmokeNMSParam msg;
        if(obj.contains("type"))
        {
            msg.type = (obj["type"].is_string()?(obj["type"].get<std::string>().c_str()):obj["type"].get<std::string>());
        }
        if(obj.contains("threshold"))
        {
            msg.threshold = (obj["threshold"].is_string()?(float)atof(obj["threshold"].get<std::string>().c_str()):obj["threshold"].get<float>());
        }
        if(obj.contains("sigma"))
        {
            msg.sigma = (obj["sigma"].is_string()?(float)atof(obj["sigma"].get<std::string>().c_str()):obj["sigma"].get<float>());
        }
        if(obj.contains("interclsconfthresh"))
        {
            msg.interclsconfthresh = (obj["interclsconfthresh"].is_string()?(float)atof(obj["interclsconfthresh"].get<std::string>().c_str()):obj["interclsconfthresh"].get<float>());
        }
        if(obj.contains("interclsnmsthresh"))
        {
            msg.interclsnmsthresh = (obj["interclsnmsthresh"].is_string()?(float)atof(obj["interclsnmsthresh"].get<std::string>().c_str()):obj["interclsnmsthresh"].get<float>());
        }
        return msg;
    }
    template <>
    ApolloperceptioncamerasmokeNMSParam from_json<ApolloperceptioncamerasmokeNMSParam>(nlohmann::json obj){
        return from_json_ApolloperceptioncamerasmokeNMSParam(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioncamerasmokeNMSParam &dt)
    {
        dt=from_json_ApolloperceptioncamerasmokeNMSParam(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioncamerasmokeNMSParam & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioncamerasmokeNMSParam & dt)
    {
        os << to_json(dt);
        return os;
    }
}
